<?php

/**
 * Output a black-and-white BMP image to either the browser or a file.
 * 
 * @param resource $image
 *            An image resource, returned by one of the image creation functions,
 *            such as imagecreatetruecolor().
 *
 * @param string|null $to
 *            The path or an open stream resource
 *            (which is automatically being closed after this function returns)
 *            to save the file to.
 *            If not set or NULL, the raw image stream will be outputted directly.
 *
 * @param float $threshold
 *            The number in the range of 0.0 to 1.0.
 *            Brighter for larger, or darker for smaller.
 *
 * @return bool Returns TRUE on success or FALSE on failure.
 * 
 */
function imagebwbmp($image, $to = null, $threshold = 0.5)
{
    // Validate argument counts and types
    if (func_num_args() < 1) {
        $fmt = "imagebwbmp() expects a least 1 parameters, %d given";
        trigger_error(sprintf($fmt, func_num_args()), E_USER_WARNING);
        return;
    }
    if (!is_resource($image)) {
        $fmt = "imagebwbmp() expects parameter 1 to be resource, %s given";
        trigger_error(sprintf($fmt, gettype($image)), E_USER_WARNING);
        return;
    }
    if (!is_numeric($threshold)) {
        $fmt = "imagebwbmp() expects parameter 3 to be float, %s given";
        trigger_error(sprintf($fmt, gettype($threshold)), E_USER_WARNING);
        return;
    }

    // Validate argument details
    if (get_resource_type($image) !== 'gd') {
        $msg = "imagebwbmp(): supplied resource is not a valid gd resource";
        trigger_error($msg, E_USER_WARNING);
        return false;
    }
    switch (true) {
        case $to === null:
            break;
        case is_resource($to) && get_resource_type($to) === 'stream':
        case is_string($to) and $to = fopen($to, 'wb'):
            if (preg_match('/[waxc+]/', stream_get_meta_data($to)['mode'])) {
                break;
            }
        default:
            $msg = "imagebwbmp(): Invalid 2nd parameter, it must a writable filename or a writable stream";
            trigger_error($msg, E_USER_WARNING);
            return false;
    }

    // Open default output as resource if 2nd argument is not specified
    if ($to === null) {
        $to = fopen('php://output', 'wb');
    }

    // Get image information
    $biWidth = imagesx($image);
    $biHeight = imagesy($image);
    $biSizeImage = ((int)ceil($biWidth / 32) * 32 / 8 * $biHeight);
    $bfOffBits = 54 + 4 * 2; // Use two colors (black and white)
    $bfSize = $bfOffBits + $biSizeImage;
    
    // Write Header (Use raw 1bit bitmap)
    fwrite($to, 'BM');
    fwrite($to, pack('VvvV', $bfSize, 0, 0, $bfOffBits));
    fwrite($to, pack('VVVvvVVVVVV', 40, $biWidth, $biHeight, 1, 1, 0, $biSizeImage, 0, 0, 0, 0));
    fwrite($to, "\xff\xff\xff\x00"); // white
    fwrite($to, "\x00\x00\x00\x00"); // black
    
    for ($y = $biHeight - 1; $y >= 0; --$y) {

        // Initialize byte
        $byte = 0;

        for ($x = 0; $x < $biWidth; ++$x) {
            // Calculate RGB
            $rgb = imagecolorat($image, $x, $y);
            $r = ($rgb >> 16) & 0xff;
            $g = ($rgb >> 8) & 0xff;
            $b = $rgb & 0xff;

            // Calculate weightened average of RGB
            $value = (0.299 * $r + 0.587 * $g + 0.114 * $b) / 0xff;

            // Determine white(0) or black(1)
            $color = (int)($value > $threshold);

            // Append color bit to the byte
            $byte = ($byte << 1) | $color;

            // For each byte ...
            if ($x % 8 === 7) {
                // Write byte data
                fwrite($to, pack('C', $byte));
                // Reset byte data
                $byte = 0;
            }
        }

        // If number of bits is not a multiple of 8, pad right with zeros and flush them
        if ($x % 8) {
            fwrite($to, pack('C', $byte << (8 - $x % 8)));
        }

        // If number of bits is not a multiple of 32, fill blank with zeros
        if ($x % 32) {
            fwrite($to, str_repeat("\x00", (int)((32 - $x % 32) / 8)));
        }
    }

    return true;
}

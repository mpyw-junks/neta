<?php

require_once __DIR__ . '/function.php';

$list = [
    'lenna.png' => 0.45,
    'yaju.jpg' => 0.4,
    'cat.jpg' => 0.7,
    'mpyw.png' => 0.7,
    'sky.jpg' => 0.5,
];

foreach ($list as $filename => $threshold) {
    $in = __DIR__ . '/in/' . $filename;
    $out = __DIR__ . '/out/' . preg_replace('/.\K[^.]*+\z/', 'bmp', $filename);
    $create = substr_replace(getimagesize($in)['mime'], 'createfrom', 5, 1);
    imagebwbmp($create($in), $out, $threshold);
}
#include <stdio.h>

/**
 * 変換結果を文字列バッファに格納します。
 * 文字列はNULL終端処理されます。
 * 
 * num: 非負整数
 * base: 基数 (2〜16)
 * size: 出力バッファのサイズ
 * buf[size]: 出力バッファ
 *  
 * 返り値: 成功したとき格納したNULL文字を除く文字列長，失敗したとき0を返します。
 */
size_t base_convert(unsigned num, int base, size_t size, char buf[size])
{
    static const char *digits = "0123456789ABCDEF";

    if (base < 2 || base > 16) {
        return 0;
    }

    for (size_t length = 0; length < size - 1; num /= base) {
        buf[length++] = digits[num % base];
        if (num >= base) {
            continue;
        }
        for (size_t i = 0; i < length / 2; ++i) {
            char tmp = buf[i];
            buf[i] = buf[length - i - 1];
            buf[length - i - 1] = tmp;
        }
        buf[length] = '\0';
        return length;
    }

    return 0;
}

int main(void)
{
    unsigned n;
    char buf[256];

    printf("0以上の10進数を入力: ");
    if (scanf("%u", &n) != 1) {
        return 1;
    }

    for (int i = 2; i <= 16; ++i) {
        if (base_convert(n, i, sizeof(buf), buf)) {
            printf("%2d進数表記: %s\n", i, buf);
        }
    }

    return 0;
}

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
    wchar_t buffer[256];
    setlocale(LC_ALL, "");

    printf("日本語を含む文字列を1文字ずつに分割して表示します\n");
    printf("入力: ");
    if (wscanf(L"%255l[^\n]%*[^\n]", buffer) != 1) {
        return 1;
    }
    /*
    macOS 以外では scanf で書いても動作する↓

    if (scanf("%255l[^\n]%*[^\n]", buffer) != 1) {
        return 1;
    }
    */
    scanf("%*c");

    printf("出力: ");
    for (wchar_t *c = buffer; *c; ++c) {
        printf("「%lc」", *c);
    }
    putchar('\n');

    return 0;
}

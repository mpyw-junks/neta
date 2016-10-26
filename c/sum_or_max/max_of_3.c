#include <stdio.h>

int main(void)
{
    int a, b, c, max;

    printf("入力1: ");
    if (scanf("%d%*[^\n]", &a) != 1) {
        return 1;
    }
    printf("入力2: ");
    if (scanf("%d%*[^\n]", &b) != 1) {
        return 1;
    }
    printf("入力3: ");
    if (scanf("%d%*[^\n]", &c) != 1) {
        return 1;
    }

    max = (a > b) ? a : b;
    max = (max > c) ? max : c;

    printf("最大値: %d\n", max);

    return 0;
}

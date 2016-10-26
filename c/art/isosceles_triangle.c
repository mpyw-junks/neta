#include <stdio.h>

int main(void)
{
    unsigned n;

    printf("N (3≦N≦40) := ");
    if (scanf("%u%*[^\n]", &n) != 1 || n < 3 || n > 40) {
        return 1;
    }

    putchar('\n');
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n - i; ++j) {
            putchar(' ');
        }
        putchar('*');
        if (i > 0) {
            for (size_t j = 0; j < 2 * i - 1; ++j) {
                putchar(i == n - 1 ? '*' : ' ');
            }
            putchar('*');
        }
        for (size_t j = 0; j < n - i; ++j) {
            putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}

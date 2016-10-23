#include <stdio.h>

unsigned C(unsigned n, unsigned r)
{
    unsigned s = 1;
    if (r > n / 2) r = n - r; // e.g.   C(100, 97) = C(100, 3)
    for (unsigned i = 1; i <= r; ++i) {
        s *= n - r + i; // e.g.   98, 99, 100
        s /= i;         // e.g.   1, 2, 3
    }
    return s;
}

int main(void)
{
    unsigned n, r;

    printf("n = ");
    if (scanf("%u", &n) != 1) return 1;

    printf("r = ");
    if (scanf("%u", &r) != 1) return 1;

    printf("C(%u, %u) = %u\n", n, r, C(n, r));

    return 0;
}

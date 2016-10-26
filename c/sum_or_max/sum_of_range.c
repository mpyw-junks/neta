#include <stdio.h>

/*

Σ[m→n]k
= Σ[0→n]k - Σ[0→m-1]k
= n(n+1)/2 - m(m-1)/2
= {n(n+1) - m(m-1)} / 2

*/

int sumOfRange(int m, int n)
{
    if (m > n) {
        int t = m;
        m = n;
        n = t;
    }
    return (n * (n + 1) - m * (m - 1)) / 2;
}

int main(void)
{
    int m, n;

    printf("m = ");
    if (scanf("%d%*[^\n]", &m) != 1) {
        return 1;
    }

    printf("n = ");
    if (scanf("%d%*[^\n]", &n) != 1) {
        return 1;
    }

    printf("sumOfRange(%d, %d) = %d\n", m, n, sumOfRange(m, n));
    return 0;
}

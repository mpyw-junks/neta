#include <stdio.h>

double sqrt(double n)
{
    double s = n / 2;
    if (s < 0.0) return 0.0 / 0;
    if (s == 0.0) return 0.0;
    for (double t = 0.0; t = (s + n / s) / 2, s != t; s = t);
    return s;
}

int main(void)
{
    double n;
    printf("n = ");
    if (scanf("%lf", &n) != 1) {
        return 1;
    }
    printf("sqrt(n) = %f\n", sqrt(n));
    return 0;
}

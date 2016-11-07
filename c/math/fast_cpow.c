#include <stdio.h>

typedef struct {
    double r;
    double i;
} Complex;

Complex cmul(Complex x, Complex y)
{
    return (Complex){
        .r = x.r * y.r - x.i * y.i,
        .i = x.r * y.i + y.r * x.i,
    };
}

Complex fast_cpow(Complex c, unsigned n)
{
    Complex a = {.r = 1, .i = 0};
    while (n) {
        if (n % 2) {
            a = cmul(a, c);
            --n;
        } else {
            c = cmul(c, c);
            n >>= 1;
        }
    }
    return a;
}

int main(void)
{
    Complex c;
    double x, y;
    unsigned n;

    printf("x = ");
    if (scanf("%lf", &x) != 1) {
        return 1;
    }

    printf("y = ");
    if (scanf("%lf", &y) != 1) {
        return 1;
    }

    printf("n = ");
    if (scanf("%u", &n) != 1) {
        return 1;
    }

    c = fast_cpow((Complex){.r = x, .i = y}, n);

    if (c.r && c.i) {
        printf("(x+iy)^n = %.37g+%.37gi\n", c.r, c.i);
    } else if (c.i) {
        printf("(x+iy)^n = %.37gi\n", c.i);
    } else {
        printf("(x+iy)^n = %.37g\n", c.r);
    }

    return 0;
}

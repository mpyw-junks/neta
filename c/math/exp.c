#include <stdio.h>

/*

exp(x) = x^0/0! + x^1/1! + x^2/2! + ...

n = 0: exp(x)_{0} = 1
n > 0: exp(x)_{n} = exp(x)_{n-1} * x/n

exp(-x) = 1 / exp(x)

*/

double exp(double x)
{
    int n = 0;
    double psum, sum = 1.0, item = 1.0;
    do {
        psum = sum;
        sum += item = item * (x < 0 ? -x : x) / ++n;
    } while (sum != psum);
    return x < 0 ? 1 / sum : sum;
}

int main(void)
{
    double n;
    printf("n = ");
    if (scanf("%lf", &n) != 1) {
        return 1;
    }
    printf("exp(n) = %f\n", exp(n));
    return 0;
}

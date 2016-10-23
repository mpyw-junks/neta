#include <stdio.h>
#include <math.h>

/*

exp(x) = x^0/0! + x^1/1! + x^2/2! + ...

n = 0: exp(x)_{0} = 1
n > 0: exp(x)_{n} = exp(x)_{n-1} * x/n

exp(-x) = 1 / exp(x)

*/

double myexp(double x)
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
    int nums[] = {
        -1000, -200, -100, -50, -10, -1,
        0,
        1, 10, 50, 100, 200, 1000
    };
    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i) {
        printf("  exp(%+6d): %e\n", nums[i], exp(nums[i]));
        printf("myexp(%+6d): %e\n", nums[i], myexp(nums[i]));
    }
    return 0;
}

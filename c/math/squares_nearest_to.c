#include <stdio.h>

typedef struct {
    unsigned x, y;
} Point;

double sqrt(double n)
{
    double s = n / 2;
    if (s < 0.0) return 0.0 / 0;
    if (s == 0.0) return 0.0;
    for (double t = 0.0; t = (s + n / s) / 2, s != t; s = t);
    return s;
}

Point squaresNearestTo(unsigned n) 
{
    double *min;
    Point *p;
    
    for (unsigned x = 0, range = sqrt(n); x <= range; ++x) {
        double intercept = sqrt(n - x * x);
        unsigned y = intercept;
        double diff = intercept - y;
        if (diff >= 0.5) {
            diff = 1 - diff;
            ++y;
        }
        if (min == NULL || diff < *min) {
            min = &(double){diff};
            p = &(Point){x, y};
        }
    }
    
    return *p;
}

int main(void)
{
    unsigned n;
    
    printf("n = ");
    if (scanf("%u", &n) != 1) return 1;
    
    Point p = squaresNearestTo(n);
    printf(
        "%u に最も近い非負整数二乗和は %u^2 + %u^2 = %u\n",
        n, p.x, p.y, p.x * p.x + p.y * p.y
    );
    
    return 0;
}

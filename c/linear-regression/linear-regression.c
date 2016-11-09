#include <stdio.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    double slope, intercept;
} Line;

Line linear_regression(size_t n, Point points[n])
{
    double sxy = 0, sx = 0, sy = 0, sx2 = 0;
    for (size_t i = 0; i < n; ++i) {
        sxy += points[i].x * points[i].y;
        sx  += points[i].x;
        sy  += points[i].y;
        sx2 += points[i].x * points[i].x;
    }
    return (Line){
        .slope     = (n * sxy - sx * sy) / (n * sx2 - sx * sx),
        .intercept = (sx2 * sy - sxy * sx) / (n * sx2 - sx * sx),
    };
}

int main(void)
{
    char buffer[256];
    Point points[100];
    size_t n = 0;
    Line line;

    for (size_t i = 0; i < 100; ++i) {
        printf("points[%zu] = ", i);
        if (scanf("%255[^\n]%*[^\n]", buffer) != 1) {
            break;
        }
        scanf("%*c");
        if (sscanf(buffer, "%lf %lf", &points[n].x, &points[n].y) != 2) {
            break;
        }
        ++n;
    }

    line = linear_regression(n, points);
    printf("\nLinear Regression: y = %f * x + %f\n", line.slope, line.intercept);
    return 0;
}
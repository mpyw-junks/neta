#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a, b, x;
    srand(time(NULL));

    printf("Player A: ");
    if (scanf("%d%*[^\n]", &a) != 1) {
        return 1;
    }

    printf("Player B: ");
    if (scanf("%d%*[^\n]", &b) != 1) {
        return 1;
    }

    x = rand() % 10;
    a = a > x ? a - x : x - a;
    b = b > x ? b - x : x - b;

    printf("Secret Number is %d\n", x);
    if (a == b) {
        printf("Draw...\n");
    } else {
        printf("Player %c Win!\n", a < b ? 'A' : 'B');
    }

    return 0;
}

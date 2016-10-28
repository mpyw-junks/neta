#include <stdio.h>

int main(void)
{
    unsigned x;

    printf("駐車時間: ");
    if (scanf("%u", &x) != 1) {
        return 1;
    }

    printf("駐車料金: %u円\n", 
        (x < 17) ? 60 * x :
        (x < 24) ? 1000 :
        (x / 24 + (x % 24 != 0)) * 1000
    );
    return 0;
}

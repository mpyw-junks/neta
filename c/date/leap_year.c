#include <stdio.h>

int isLeapYear(unsigned y)
{
    return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}

int main(void)
{
    unsigned y;
    printf("Year: ");
    if (scanf("%u", &y) != 1) return 1;
    printf("LeapYear? %s\n", isLeapYear(y) ? "true" : "false");
    return 0;
}

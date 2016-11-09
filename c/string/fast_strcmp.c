#include <stdio.h>

int fast_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2) ++s1, ++s2;
    return (unsigned char)*s1 - (unsigned char)*s2;
}

int main(void)
{
    char s1[256], s2[256];

    printf("s1: ");
    if (scanf("%255[^\n]%*[^\n]", s1) != 1) {
        return 1;
    }
    scanf("%*c");

    printf("s2: ");
    if (scanf("%255[^\n]%*[^\n]", s2) != 1) {
        return 1;
    }
    scanf("%*c");

    printf("fast_strcmp(s1, s2) = %d\n", fast_strcmp(s1, s2));
    return 0;
}

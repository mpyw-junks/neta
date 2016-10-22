#include <stdio.h>

int main(void)
{
    int a, b, c, max;
    
    printf("入力1: "); scanf("%d", &a);
    printf("入力2: "); scanf("%d", &b);
    printf("入力3: "); scanf("%d", &c);
    
    max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    
    printf("最大値: %d\n", max);
    
    return 0;
}

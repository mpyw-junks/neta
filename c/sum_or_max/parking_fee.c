#include <stdio.h>

int main(void)
{
    unsigned x;

    printf("駐車時間: ");
    if (scanf("%u", &x) != 1) {
        return 1;
    }

    /*
        1時間60円の駐車場の料金
        24時間以内であれば1000円を上限とし、
        24時間を超えた場合の料金は1日ごとに1000円
    */

    printf("駐車料金: %u円\n", 
        (x < 17) ? 60 * x :
        (x < 24) ? 1000 :
        (x / 24 + (x % 24 != 0)) * 1000
    );
    return 0;
}

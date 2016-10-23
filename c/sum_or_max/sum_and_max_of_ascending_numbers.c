#include <stdio.h>

int main(void)
{
    int count = 0, sum = 0, *max = NULL, num;

    while (1) {
        printf("入力%d: ", count + 1);
        if (scanf("%d", &num) != 1) break;
        if (max != NULL && num < *max) break;
        ++count;
        sum += num;
        max = &(int){num};
    }

    puts("\n昇順の数値が入力されなかったので読み取りを終了します。\n");
    if (max != NULL) printf("最後の値 (かつ最大値) は%dです。\n", *max);
    printf("入力されたデータ数は%dです。\n", count);
    printf("データの合計は%dです。\n", sum);

    return 0;
}

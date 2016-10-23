#include <stdio.h>

int main(void)
{
    int count, num, *max = NULL;

    printf("何個入力しますか？: ");
    if (scanf("%d", &count) != 1) {
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        printf("入力%d: ", i + 1);
        if (scanf("%d", &num) != 1) {
            break;
        }
        if (max == NULL || num > *max) {
            max = &(int){num};
        }
    }

    if (max == NULL) {
        printf("最大値: 未定義\n");
    } else {
        printf("最大値: %d\n", *max);
    }

    return 0;
}

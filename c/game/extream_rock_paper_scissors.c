#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    const char *handFaces[] = {"✊", "✌", "✋", "😠", "👑"};
    const int handValues[] = {0, 1, 2, 3, 6};

    int myHand, enemyHand, myValue, enemyValue, result,
        round = 1, win = 0, lose = 0;

    srand((unsigned)time(NULL));
    printf("5番勝負\n\n");

    for (int round = 1; round <= 5; ++round) {

        printf("%d回目の手を選択 (現在%d勝%d敗)\n", round, win, lose);
        while (1) {
        RETAKE:
            printf("0:✊　　1:✌　　2:✋　　3:😠　　4:👑\n");
            printf(">>> ");
            int scanned = scanf("%d%*[^\n]", &myHand);
            if (scanned == EOF) return 1;
            if (scanned == 1 && myHand >= 0 && myHand <= 5) break;
        }
        enemyHand = rand() % 5;

        myValue = handValues[myHand];
        enemyValue = handValues[enemyHand];

        if (myHand > 2 || enemyHand > 2) {
            myValue /= 3;
            enemyValue /= 3;
        }

        result = (myValue - enemyValue + 3) % 3;

        printf("あなた: %s　　", handFaces[myHand]);
        printf("相手: %s　　", handFaces[enemyHand]);

        switch (result) {
            case 2:
                printf("結果: ✨\n\n");
                ++win;
                break;
            case 1:
                printf("結果: ☠\n\n");
                ++lose;
                break;
            default:
                printf("結果: ❓\n\n");
                printf("あいこです\n");
                goto RETAKE;
        }

    }

    printf("最終結果: %d勝%d敗\n", win, lose);
    return 0;
}

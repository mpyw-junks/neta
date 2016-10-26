#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char token[1024];
    size_t count;
} Counter;

int main(void)
{
    char token[1024];
    Counter counters[11];
    size_t size = 0;

    // 1023文字までの半角英数字の連続を読み取る
    // (ここではそれ以上の連続が現れて分裂することは考慮しない)
    while (scanf("%1023[_A-Za-z0-9-]", token) != EOF && scanf("%*[^_A-Za-z0-9-]") != EOF) {

        // 既に見つけたものの中から一致するものを探し，
        // 見つかった場合はカウンタをインクリメントして追加処理をスキップ
        for (size_t i = 0; i < size; ++i) {
            if (!strcmp(token, counters[i].token)) {
                ++counters[i].count;
                goto SKIP_APPEND;
            }
        }

        // カウンタ配列が最大サイズに到達していなければサイズを拡張する
        if (size < 11) {
            ++size;
        }

        // カウンタ配列の末尾に追加または上書き
        strcpy(counters[size - 1].token, token);
        counters[size - 1].count = 1;

        // 末尾以外のデータはソートされているので効率のいい挿入ソートを適用する
        SKIP_APPEND:
        for (size_t i = 1; i < size; ++i) {
            Counter tmp = counters[i];
            if (counters[i - 1].count < tmp.count) {
                size_t j = i;
                do {
                    counters[j] = counters[j - 1];
                    --j;
                } while (j > 0 && counters[j - 1].count < tmp.count);
                counters[j] = tmp;
            }
        }
    }

    // 11個目は意味を持たないので10個目までをランキングとして採用する
    printf("最も多く見つかった単語ランキング10\n");
    for (size_t i = 0; i < (size < 11 ? size : 10); ++i) {
        printf("第%2zu位: %4zu回: %s\n",
                i + 1, counters[i].count, counters[i].token);
    }

    return 0;
}

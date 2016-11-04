/*
1年3組20番 渡辺
1年1組1番 青木
1年4組10番 鈴木

のような行入力を想定
*/

#include <stdio.h>
#include <stdint.h>
#define MAX_RECORD_SIZE 20

/*

uint8_t が4つの構造体
→ 比較が uint32_t にキャストするだけでできる
→ IntelのCPUはリトルエンディアンなのでソートの優先度の低いものを頭に持ってくる

※ 移植性を考えるならすべきではないロマンのコード

*/
typedef struct {
    uint8_t index;
    uint8_t number;
    uint8_t class;
    uint8_t grade;
} Record;

int main(void)
{
    Record records[MAX_RECORD_SIZE];
    char names[MAX_RECORD_SIZE][256];
    char buffer[512];
    uint8_t n;

    // 入力受付開始
    printf("[入力]\n");

    for (n = 0; n < MAX_RECORD_SIZE; ++n) {
        printf("%hhu: ", n);
        // 標準入力から最大511文字までで1行を格納
        if (scanf("%511[^\n]%*[^\n]", buffer) != 1) {
            break;
        }
        scanf("%*c");
        // さらにn番目のレコードに読み取り結果を格納
        Record *r = &records[n];
        char *name = names[n];
        r->index = n;
        if (sscanf(buffer, "%hhu年%hhu組%hhu番 %255s", &r->grade, &r->class, &r->number, name) != 4) {
            break;
        }
    }

    // バブルソートで手抜き
    for (uint8_t i = 0; i < n - 1; ++i) {
        for (uint8_t j = n - 1; j > i; --j) {
            if (*((uint32_t *)&records[j - 1]) > *((uint32_t *)&records[j])) {
                Record tmp = records[j];
                records[j] = records[j - 1];
                records[j - 1]= tmp;
            }
        }
    }

    // 結果を表示
    printf("\n[ソート後]\n");
    for (uint8_t i = 0; i < n; ++i) {
        Record *r = &records[i];
        char *name = names[r->index];
        printf("[%hhu] %hhu年%hhu組%hhu番 %s\n", i, r->grade, r->class, r->number, name);
    }

    return 0;
}

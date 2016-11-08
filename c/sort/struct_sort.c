/*
1年3組20番 渡辺
1年1組1番 青木
1年4組10番 鈴木

のような行入力を想定
*/

#include <stdio.h>
#include <stdint.h>

// Record構造体配列の上限
#define MAX_RECORD_SIZE 20
// Record構造体をuint32_t化するマクロ
#define RINT32(r) (r.grade << 24 | r.class << 16 | r.number << 8 | r.index)

typedef struct {
    uint8_t grade, class, number, index;
    char name[256];
} Record;

int main(void)
{
    Record records[MAX_RECORD_SIZE];
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
        r->index = n;
        if (sscanf(buffer, "%hhu年%hhu組%hhu番 %255s", &r->grade, &r->class, &r->number, r->name) != 4) {
            break;
        }
    }

    // バブルソートで手抜き
    for (uint8_t i = 0; i < n - 1; ++i) {
        for (uint8_t j = n - 1; j > i; --j) {
            if (RINT32(records[j - 1]) > RINT32(records[j])) {
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
        printf("[%hhu] %hhu年%hhu組%hhu番 %s\n", i, r->grade, r->class, r->number, r->name);
    }

    return 0;
}

#include <stdio.h>

typedef struct {
    char *letter;
    unsigned value;
} Letter;

char *romanize(unsigned n, char buffer[16])
{
    size_t offset;
    Letter *letters[] = {
        &(Letter){"M", 1000},
        &(Letter){"CM", 900},
        &(Letter){"D", 500},
        &(Letter){"CD", 400},
        &(Letter){"C", 100},
        &(Letter){"XC", 90},
        &(Letter){"L", 50},
        &(Letter){"XL", 40},
        &(Letter){"X", 10},
        &(Letter){"IX", 9},
        &(Letter){"V", 5},
        &(Letter){"IV", 4},
        &(Letter){"I", 1},
    };

    if (n < 1 || n > 3999) {
        return NULL;
    }

    for (size_t i = 0; i < sizeof(letters) / sizeof(Letter *); ++i) {
        unsigned quotient = n / letters[i]->value;
        unsigned reminder = n % letters[i]->value;
        while (quotient--) {
            char *letter = letters[i]->letter;
            while (*letter) buffer[offset++] = *letter++;
        }
        n = reminder;
    }
    buffer[offset] = '\0';

    return buffer;
}

int main(void)
{
    char buffer[16];
    unsigned input;

    printf("1〜3999までの数値を入力: ");
    if (scanf("%u", &input) != 1) {
        printf("読み取りに失敗しました\n");
        return 1;
    }

    if (!romanize(input, buffer)) {
        printf("%u は表記できません\n", input);
        return 1;
    }
    printf("%u はローマ数字表記で %s です\n", input, buffer);

    return 0;
}

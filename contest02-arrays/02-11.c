#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool b[8][8] = {0};
    int c;
    while((c = getchar()) != EOF) {
        if (c == '\n')
            break;
        int row = c - 'a';
        c = getchar();
        if (c == EOF)
            break;
        int col = c - '1';
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (row + i >= 0 && row + i < 8 && col + j >= 0 && col + j < 8)
                    b[row + i][col + j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (!b[i][j])
                ++ans;
        }
    }
    printf("%d", ans);
}

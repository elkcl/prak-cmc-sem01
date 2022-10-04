#include <stdio.h>

typedef unsigned int ui;

int main(void) {
    ui n;
    scanf("%d", &n);
    int cnt = 0;
    for (ui mask = 1; mask != 0; mask <<= 1) {
        if (n & mask)
            ++cnt;
    }
    printf("%d", cnt);
}
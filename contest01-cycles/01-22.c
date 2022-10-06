#include <stdio.h>

int main(void) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    if (x < 0)
        x = -x;
    if (y < 0)
        y = -y;
    int ans = 0;
    int rest = 0;
    if (x < y) {
        ans = x;
        rest = y - x;
    } else {
        ans = y;
        rest = x - y;
    }
    printf("%d", ans * 2 + (rest / 2) * 3 + (rest - rest / 2));
}
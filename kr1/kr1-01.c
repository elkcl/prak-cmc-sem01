#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
    int r, n;
    scanf("%d", &r);
    scanf("%d", &n);
    int ans = 0;
    for (int x = -r; x <= r; ++x) {
        for (int y = -r; y <= r; ++y) {
            if (x * x + y * y <= r * r)
                ++ans;
        }
    }
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        if (x * x + y * y <= r * r)
            --ans;
    }
    printf("%d\n", ans);
}

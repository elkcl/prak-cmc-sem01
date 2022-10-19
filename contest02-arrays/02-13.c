#include <stdio.h>
#include <stdbool.h>

#define MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))

int main(void) {
    int a1[8], a2[8];
    for (int i = 0; i < 8; ++i)
        scanf("%d", a1 + i);
    for (int i = 0; i < 8; ++i)
        scanf("%d", a2 + i);
    for (int i = 0; i < 8; ++i) {
        bool found = false;
        for (int j = 0; j < 8; ++j) {
            if (a1[i] <= a2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            puts("-1\n");
            return 0;
        }
    }
    for (int i = 0; i < 8; ++i) {
        bool found = false;
        for (int j = 0; j < 8; ++j) {
            if (a2[i] <= a1[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            puts("-1\n");
            return 0;
        }
    }
    int cnt1[101] = {0};
    int cnt2[101] = {0};
    for (int i = 0; i < 8; ++i) {
        ++cnt1[a1[i]];
        ++cnt2[a2[i]];
    }
    int ans = 0;
    for (int i = 0; i <= 100; ++i) {
        ans += i * MAX(cnt1[i], cnt2[i]);
    }
    printf("%d", ans);
}
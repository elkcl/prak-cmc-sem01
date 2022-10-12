#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);
    bool used[n];
    memset(used, false, n);
    int ans[n];
    int inp[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", inp + i);
    for (int i = 0; i < n; ++i) {
        int curr = 0;
        bool found = false;
        for (int c = n - 1; c >= 0; --c) {
            if (!used[c]) {
                if (inp[i] == curr) {
                    ans[i] = c;
                    used[c] = true;
                    found = true;
                    break;
                }
                ++curr;
            }
        }
        if (!found) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", ans[i] + 1);
}

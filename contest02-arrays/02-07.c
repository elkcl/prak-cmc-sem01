#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);
    bool used[n];
    memset(used, false, n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (x < 1 || x > n || used[x - 1]) {
            puts("No\n");
            return 0;
        }
        used[x - 1] = true;
    }
    puts("Yes\n");
}
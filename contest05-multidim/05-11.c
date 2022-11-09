#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

typedef long long ll;

int main(void) {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int (*a)[m] = malloc(sizeof(int[n][m]));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    ll (*dp)[m] = calloc(n * m, sizeof(ll));
    for (int i = 0; i < n; ++i)
        dp[i][0] = a[i][0];
    for (int j = 1; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            dp[i][j] = dp[i][j - 1];
            if (i != 0)
                dp[i][j] = MAX(dp[i][j], dp[i - 1][j - 1]);
            if (i != n - 1)
                dp[i][j] = MAX(dp[i][j], dp[i + 1][j - 1]);
            dp[i][j] += a[i][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans = MAX(ans, dp[i][m - 1]);
    printf("%Ld\n", ans);

    free(a);
    free(dp);
}
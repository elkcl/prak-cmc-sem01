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

void mat_mul(ll p, int n, int m, int l, const ll a[n][m], const ll b[m][l], ll c[n][l]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < m; ++k) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= p;
            }
        }
    }
}

void mat_pow(int p, int s, int n, const ll a[n][n], ll b[n][n], ll c[n][n]) {
    if (s == 1) {
        memcpy(c, a, sizeof(ll[n][n]));
        return;
    }
    if (s % 2 == 0) {
        mat_pow(p, s / 2, n, a, c, b);
        mat_mul(p, n, n, n, b, b, c);
    } else {
        mat_pow(p, s - 1, n, a, c, b);
        mat_mul(p, n, n, n, b, a, c);
    }
}

int main(void) {
    int k, n, p;
    scanf("%d", &k);
    scanf("%d", &n);
    scanf("%d", &p);
    ll (*a)[k] = calloc(k * k, sizeof(ll));
    ll (*b)[k] = calloc(k * k, sizeof(ll));
    ll (*c)[k] = calloc(k * k, sizeof(ll));
    ll (*f)[1] = calloc(k * 1, sizeof(ll));
    ll (*res)[1] = calloc(k * 1, sizeof(ll));
    for (int i = 0; i < k; ++i)
        scanf("%Ld", &f[i][0]);
    for (int i = k - 1; i >= 0; --i)
        scanf("%Ld", &a[k - 1][i]);
    for (int i = 1; i < k; ++i)
        a[i - 1][i] = 1;
    if (n <= k) {
        printf("%Ld\n", f[n - 1][0] % p);
    } else {
        mat_pow(p, n - k, k, a, b, c);
        mat_mul(p, k, k, 1, c, f, res);
        printf("%Ld\n", res[k - 1][0]);
    }

    free(a);
    free(b);
    free(c);
    free(f);
    free(res);
}
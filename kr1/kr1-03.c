#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <limits.h>


unsigned int f(int *hyperparams, int N) {
    char d[1000], *p = d;
    for (int i = 0; i < N; ++i) p += sprintf(p, "%d_", hyperparams[i]);
    p = d;
    N = strlen(p);
    unsigned int m = 0x5bd1e995, h = 0x5df2eefe ^ N;
    while (N >= 4) {
        unsigned int k = *(unsigned int *)p;
        k *= m; k ^= k >> 24; k *= m; h *= m; h ^= k; p += 4; N -= 4;
    }
    switch (N) { case 3: h ^= p[2] << 16; case 2: h ^= p[1] << 8; case 1: h ^= p[0]; h *= m; default: ;};
    h ^= h >> 13; h *= m; h ^= h >> 15;
    return h;
}

#define MAXN 20

int p[MAXN], ans_p[MAXN];
unsigned int min_h = UINT_MAX;

void solve(int n, int a[n], int b[n], int i) {
    if (i == n) {
        unsigned int curr_h = f(p, n);
        if (curr_h < min_h) {
            min_h = curr_h;
            memcpy(ans_p, p, n * sizeof(int));
        }
        return;
    }
    for (int x = a[i]; x <= b[i]; ++x) {
        p[i] = x;
        solve(n, a, b, i + 1);
    }
}


int main(void) {
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        scanf("%d", b + i);
    }
    solve(n, a, b, 0);
    for (int i = 0; i< n; ++i)
        printf("%d ", ans_p[i]);
    putchar('\n');
}
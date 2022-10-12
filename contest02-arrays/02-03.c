#include <stdio.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))

int main(void) {
    int n, m;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    scanf("%d", &m);
    int b[m];
    for (int i = 0; i < m; ++i)
        scanf("%d", b + i);
    int c[n + m];
    for (int i = 0; i < MIN(n, m); ++i) {
        c[2 * i] = a[i];
        c[2 * i + 1] = b[i];
    }
    if (n < m) {
        for (int i = n; i < m; ++i)
            c[n + i] = b[i];
    } else if (n > m) {
        for (int i = m; i < n; ++i)
            c[m + i] = a[i];
    }
    for (int i = 0; i < m + n; ++i)
        printf("%d ", c[i]);
}
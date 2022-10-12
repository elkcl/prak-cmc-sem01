#include <stdio.h>

#define MAX(_a, _b) ((_a) > (_b)) ? (_a) : (_b)

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        ans += MAX(a[i], b[i]);
    printf("%Ld", ans);
}
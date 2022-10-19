#include <stdio.h>

typedef long long ll;

int main(void) {
    int n;
    scanf("%d", &n);
    ll a[n];
    for (int i = 0; i < n; ++i)
        scanf("%Ld", a + i);
    int m;
    scanf("%d", &m);
    ll x[m];
    for (int i = 0; i < m; ++i)
        scanf("%Ld", x + i);
    for (int i = m - 1; i >= 0; --i) {
        ll ans = 0;
        for (int j = n - 1; j >= 0; --j) {
            ans *= x[i];
            ans += a[j];
        }
        printf("%Ld ", ans);
    }
}
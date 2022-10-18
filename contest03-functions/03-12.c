#include <stdio.h>

int ans = 0;

void solve(int n, int *a, int k, int sum1, int sum2) {
    if (k == n) {
        if (sum1 == sum2 && sum1 > ans)
            ans = sum1;
        return;
    }
    solve(n, a, k + 1, sum1, sum2);
    solve(n, a, k + 1, sum1 + a[k], sum2);
    solve(n, a, k + 1, sum1, sum2 + a[k]);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    solve(n, a, 0, 0, 0);
    printf("%d", ans);
}
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 2; j < n; j += 2) {
            int k = (i + j) / 2;
            if (arr[k] * 2 == arr[i] + arr[j])
                ++ans;
        }
    }
    printf("%d", ans);
}
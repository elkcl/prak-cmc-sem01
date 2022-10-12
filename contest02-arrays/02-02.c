#include <stdio.h>

const size_t MAXN = 10000;

int main(void) {
    int arr[MAXN];
    int curr;
    int n = 0;
    scanf("%d", &curr);
    while (curr != 0) {
        arr[n] = curr;
        ++n;
        scanf("%d", &curr);
    }
    for (int i = 0; i < n; i += 2)
        printf("%d ", arr[i]);
    for (int i = (n % 2) ? (n - 2) : (n - 1); i >= 0; i -= 2)
        printf("%d ", arr[i]);
}
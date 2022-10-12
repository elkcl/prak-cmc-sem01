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
    for (int i = n - 1; i >= 0; --i)
        printf("%d ", arr[i]);
}
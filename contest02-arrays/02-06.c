#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n];
    int arr1[n];
    int pi[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", pi + i);
        --pi[i];
        arr[i] = i + 1;
    }
    bool swap = false;
    for (int q = 0; q < 3; ++q) {
        if (!swap) {
            for (int i = 0; i < n; ++i) {
                arr1[i] = arr[pi[i]];
            }
            swap = true;
        } else {
            for (int i = 0; i < n; ++i) {
                arr[i] = arr1[pi[i]];
            }
            swap = false;
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", arr1[i]);
}

#include <stdio.h>

#define ARRAY(_T, _s, _n) _T _arr_ ## _n[_s]; _T * _n = _arr_ ## _n
#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

int main(void) {
    int n;
    scanf("%d", &n);
    ARRAY(int, n, arr);
    ARRAY(int, n, arr1);
    int pi[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", pi + i);
        --pi[i];
        arr[i] = i + 1;
    }
    for (int q = 0; q < 3; ++q) {
        for (int i = 0; i < n; ++i) {
            arr1[i] = arr[pi[i]];
        }
        SWAP(arr, arr1);
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
}
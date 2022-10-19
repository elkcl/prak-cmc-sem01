#include <stdio.h>
#include <stdbool.h>

#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

typedef unsigned ui;

int main(void) {
    int n;
    scanf("%d", &n);
    ui a[n];
    ui xor = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%u", a + i);
        xor ^= a[i];
    }
    ui mask = 1;
    for (; mask != 0; mask <<= 1) {
        if (xor & mask)
            break;
    }
    ui x = 0;
    ui y = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] & mask)
            x ^= a[i];
        else
            y ^= a[i];
    }
    if (x > y)
        SWAP(x, y);
    printf("%u %u", x, y);
}
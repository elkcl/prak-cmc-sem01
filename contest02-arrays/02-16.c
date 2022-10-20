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
    ui x = 0, y = 0, z = 0, xor2 = 0;
    ui mask = 1;
    bool bit = false;
    for (; mask != 0; mask <<= 1) {
        ui s0 = 0;
        ui s1 = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] & mask)
                s1 ^= a[i];
            else
                s0 ^= a[i];
        }
        if (s0 != 0 && s1 != 0) {
            if (xor & mask) {
                x = s1;
                xor2 = s0;
                bit = false;
            } else {
                x = s0;
                xor2 = s1;
                bit = true;
            }
            break;
        }
    }
    ui mask2 = 1;
    for (; mask2 != 0; mask2 <<= 1) {
        if (xor2 & mask2)
            break;
    }
    for (int i = 0; i < n; ++i) {
        if ((bool)(a[i] & mask) == bit) {
            if (a[i] & mask2)
                y ^= a[i];
            else
                z ^= a[i];
        }
    }
    if (z < y)
        SWAP(z, y);
    if (y < x)
        SWAP(y, x);
    if (z < y)
        SWAP(z, y);
    printf("%u %u %u", x, y, z);
}
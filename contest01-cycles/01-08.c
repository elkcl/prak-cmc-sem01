#include <stdio.h>

typedef unsigned int ui;

int main(void) {
    ui n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    ui cmax = 0;
    ui mask = (1 << k) - 1;
    for (int i = 0; i < 32 - k + 1; ++i) {
        ui curr = ((n & mask) >> i);
        if (curr > cmax)
            cmax = curr;
        mask <<= 1;
    }
    printf("%u", cmax);
}
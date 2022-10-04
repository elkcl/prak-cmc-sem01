#include <stdio.h>

typedef unsigned int ui;

int main(void) {
    ui n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    ui mask = (1 << k) - 1;
    n &= mask;
    printf("%u", n);
}
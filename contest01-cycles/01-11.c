#include <stdio.h>

typedef unsigned int ui;

int main(void) {
    ui n;
    scanf("%d", &n);
    ui mask = ((1 << 8) - 1) << 24;
    printf("%u", n ^ mask);
}
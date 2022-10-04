#include <stdio.h>

typedef unsigned int ui;

int main(void) {
    ui a, b, c, d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    ui n = a + (b << 8) + (c << 16) + (d << 24);
    printf("%u", n);
}
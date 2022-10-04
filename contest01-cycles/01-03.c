#include <stdio.h>

int main(void) {
    int k;
    scanf("%d", &k);
    char c;
    while ((c = getchar()) != '.') {
        if (c == ' ') {
            putchar(' ');
        } else if (c >= 'a' && c <= 'z') {
            putchar((c - 'a' + k) % 26 + 'a');
        } else {
            putchar((c - 'A' + k) % 26 + 'A');
        }
    }
    putchar('.');
}
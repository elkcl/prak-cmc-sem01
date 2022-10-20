#include <stdio.h>
#include <stdbool.h>

void reverse(bool odd) {
    int n;
    scanf("%d", &n);
    if (n == 0)
        return;
    if (odd) {
        printf("%d ", n);
        reverse(false);
    } else {
        reverse(true);
        printf("%d ", n);
    }
}

int main(void) {
    reverse(true);
}
#include <stdio.h>

#define SWAP(x, y) do { typeof(x) TEMP = x; x = y; y = TEMP; } while (0)

int main(void) {
    int n;
    scanf("%d", &n);
    int a1, a2, a3;
    scanf("%d", &a1);
    scanf("%d", &a2);
    scanf("%d", &a3);
    if (a3 > a2)
        SWAP(a3, a2);
    if (a2 > a1)
        SWAP(a2, a1);
    if (a3 > a2)
        SWAP(a3, a2);

    for (int i = 0; i < n - 3; ++i) {
        int a4;
        scanf("%d", &a4);
        if (a4 > a3)
            SWAP(a4, a3);
        if (a3 > a2)
            SWAP(a3, a2);
        if (a2 > a1)
            SWAP(a2, a1);
    }

    printf("%d %d %d", a1, a2, a3);
}
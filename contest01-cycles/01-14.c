#include <stdio.h>

#define SWAP(x, y) do { typeof(x) TEMP = x; x = y; y = TEMP; } while (0)

int main(void) {
    int n;
    scanf("%d", &n);

    if (n == 2) {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);
        if (a > b)
            SWAP(a, b);
        printf("%d %d", a, b);
        return 0;
    }

    int p1, p2, n1, n2;
    p1 = p2 = n1 = n2 = 0;
    for (int i = 0; i < n; ++i) {
        int curr;
        scanf("%d", &curr);
        if (curr > 0) {
            if (curr > p2)
                SWAP(curr, p2);
            if (p2 > p1)
                SWAP(p2, p1);
        } else if (curr < 0) {
            if (curr < n2)
                SWAP(curr, n2);
            if (n2 < n1)
                SWAP(n2, n1);
        }
    }
    if ((long long) p1 * p2 > (long long) n1 * n2)
        printf("%d %d", p2, p1);
    else
        printf("%d %d", n1, n2);
}
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int cmin, cmax;
    scanf("%d", &cmin);
    cmax = cmin;
    for (int i = 0; i < n - 1; ++i) {
        int curr;
        scanf("%d", &curr);
        if (curr < cmin)
            cmin = curr;
        if (curr > cmax)
            cmax = curr;
    }
    printf("%d", cmax - cmin);
}
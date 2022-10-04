#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int curr = 1;
    int cnt = 0;
    while (curr <= n) {
        curr *= 3;
    }
    curr /= 3;
    while (curr > 0) {
        if (2 * curr <= n) {
            puts("-1");
            return 0;
        } else if (curr <= n) {
            ++cnt;
            n -= curr;
        }
        curr /= 3;
    }
    printf("%d", cnt);
}
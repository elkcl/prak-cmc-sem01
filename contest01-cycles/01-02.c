#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int cmax;
    scanf("%d", &cmax);
    int cnt = 1;
    for (int i = 0; i < n - 1; ++i) {
        int curr;
        scanf("%d", &curr);
        if (curr > cmax) {
            cmax = curr;
            cnt = 1;
        } else if (curr == cmax) {
            ++cnt;
        }
    }
    printf("%d", cnt);
}
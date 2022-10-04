#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int cmax = 1;
    int cnt = 1;
    int last;
    scanf("%d", &last);
    for (int i = 0; i < n - 1; ++i) {
        int curr;
        scanf("%d", &curr);
        if (curr > last) {
            ++cnt;
        } else {
            if (cnt > cmax)
                cmax = cnt;
            cnt = 1;
        }
        last = curr;
    }
    if (cnt > cmax)
        cmax = cnt;
    printf("%d", cmax);
}
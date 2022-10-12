#include <stdio.h>
#include <math.h>

typedef long double ld;

const ld EPS = 1e-7;

int main(void) {
    int n;
    scanf("%d", &n);
    ld s[n];
    ld a[n];
    for (int i = 0; i < n; ++i)
        scanf("%Lf", s + i);
    for (int i = 0; i < n; ++i)
        scanf("%Lf", a + i);
    ld curr_t = 0;
    ld curr_v = 0;
    for (int i = 0; i < n; ++i) {
        if (fabsl(a[i]) < EPS) {
            curr_t += s[i] / curr_v;
            continue;
        }
        curr_t += (-curr_v + sqrtl(curr_v*curr_v + 2*a[i]*s[i])) / a[i];
        curr_v = sqrtl(curr_v*curr_v + 2*a[i]*s[i]);
    }
    printf("%.4Lf", curr_t);
}
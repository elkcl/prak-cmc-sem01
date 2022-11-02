#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef unsigned int ui;

int main(void) {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int w[n], u[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", w + i);
        scanf("%d", u + i);
    }
    int ans_w = 0, ans_u = 0;
    for (ui mask = 1; mask < (1 << n); ++mask) {
        int curr_w = 0, curr_u = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                curr_w += w[i];
                curr_u += u[i];
            }
        }
        if (curr_w > m)
            continue;
        if (curr_u > ans_u) {
            ans_u = curr_u;
            ans_w = curr_w;
        } else if (curr_u == ans_u && curr_w < ans_w) {
            ans_w = curr_w;
        }
    }
    printf("%d %d\n", ans_w, ans_u);
}

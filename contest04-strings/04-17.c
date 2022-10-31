#include <stdio.h>
#include <string.h>
#include <math.h>

#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

#define MAXN 2000003

char s[MAXN];
int p[MAXN], p2[MAXN], ca[MAXN], ca2[MAXN], cnt[MAXN];

int main(void) {
    int *c = ca;
    int *c2 = ca2;
    fgets(s, MAXN, stdin);
    size_t n = strlen(s) - 1;
    s[n] = '\0';
    int pos = 0;
    int cl_cnt = 2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            p[pos] = i;
            c[i] = 0;
            ++pos;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            p[pos] = i;
            c[i] = 1;
            ++pos;
        }
    }
    size_t curr_len = 1;
    while (curr_len <= n) {
        for (int i = 0; i < n; ++i) {
            p2[i] = (p[i] - curr_len + n) % n;
        }
        memset(cnt, 0, (cl_cnt + 1) * sizeof(int));
        for (int i = 0; i < n; ++i) {
            ++cnt[c[i] + 1];
        }
        for (int i = 1; i < cl_cnt + 1; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            p[cnt[c[p2[i]]]] = p2[i];
            ++cnt[c[p2[i]]];
        }
        int cl_cnt2 = 0;
        c2[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (c[p[i]] == c[p[i - 1]] && c[(p[i] + curr_len) % n] == c[(p[i - 1] + curr_len) % n]) {
                c2[p[i]] = cl_cnt2;
            } else {
                ++cl_cnt2;
                c2[p[i]] = cl_cnt2;
            }
        }
        ++cl_cnt2;
        SWAP(c, c2);
        cl_cnt = cl_cnt2;
        curr_len *= 2;
    }

    int ans = p[0];
    for (int i = 0; i < n; ++i) {
        putchar(s[(ans + i) % n]);
    }
}
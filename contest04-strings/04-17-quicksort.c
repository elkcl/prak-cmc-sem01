#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))

#define MAXN 4000003

char s[MAXN];
int z[MAXN];

void z_func(int n, int off) {
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = MIN(r - i, z[i - l]);
        if (z[i] < 0)
            z[i] = 0;
        while (i + z[i] < n && s[(z[i] + off) % n] == s[(i + z[i] + off) % n])
            ++z[i];
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
}

int main(void) {
    srand(69420);
    fgets(s, MAXN, stdin);
    int n = strlen(s) - 1;
    memcpy(s + n, s, n * sizeof(char));
    n *= 2;
    int off = 0;
    while (1) {
        z_func(n, off);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[(z[i] + off) % n] > s[(i + z[i] + off) % n])
                ++cnt;
        }
        if (cnt == 0) {
            for (int i = 0; i < n / 2; ++i)
                putchar(s[(i + off) % n]);
            return 0;
        }
        int x = (int) ((long double) rand() / RAND_MAX * (cnt - 1));
        for (int i = 0; i < n; ++i) {
            if (s[(z[i] + off) % n] > s[(i + z[i] + off) % n]) {
                if (x == 0) {
                    off += i;
                    off %= n;
                    break;
                }
                --x;
            }
        }
    }
}
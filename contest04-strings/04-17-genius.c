#include <stdio.h>
#include <string.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))

#define MAXN 4000003

char s[MAXN];
int z[MAXN];

int main(void) {
    fgets(s, MAXN, stdin);
    int n = strlen(s) - 1;
    memcpy(s + n, s, n * sizeof(char));
    z[0] = 2 * n;
    int l = 0, r = 0;
    int rot = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = MIN(r - i, z[i - l + rot]);
        if (z[i] < 0)
            z[i] = 0;
        while (i + z[i] < 2 * n && s[z[i] + rot] == s[i + z[i]])
            ++z[i];
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
        if (s[z[i] + rot] > s[i + z[i]]) {
            rot = i;
            l = r = i;
        }
    }
    for (int i = 0; i < n; ++i)
        putchar(s[i + rot]);
}
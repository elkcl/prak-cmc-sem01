#include <stdio.h>
#include <string.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))

#define MAXN 4000003

char s[MAXN];
int p[MAXN];

int main(void) {
    fgets(s, MAXN, stdin);
    int n = strlen(s) - 1;
    memcpy(s + n, s, n * sizeof(char));
    n *= 2;
    int rot = 0, k = 0;
    for (int i = 1; i < n; ++i) {
        for (k = p[i - rot - 1]; k != 0 && s[k + rot] != s[i]; k = p[k - 1])
            if (s[k + rot] > s[i])
                rot = i - k;
        if (s[k + rot] > s[i])
            rot = i - k;
        else if (s[k + rot] == s[i])
            ++k;
        p[i - rot] = k;
    }
    for (int i = 0; i < n / 2; ++i)
        putchar(s[i + rot]);
}
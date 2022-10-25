#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 3000010

char s[MAXN];

void pref_func(size_t n, const char str[n], int p[n]) {
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int k = p[i - 1];
        while (k > 0 && str[i] != str[k])
            k = p[k - 1];
        if (str[i] == str[k])
            ++k;
        p[i] = k;
    }
}

int main(void) {
    fgets(s, MAXN, stdin);
    size_t n1 = strlen(s) - 1;
    s[n1] = ' ';
    fgets(s + n1 + 1, MAXN, stdin);
    size_t n2 = strlen(s + n1 + 1) - 1;
    s[n1 + 1 + n2] = ' ';
    memcpy(s + n1 + n2 + 2, s, n1);

    int p[n1 + n2 + 1];
    pref_func(n1 + n2 + 1, s, p);
    printf("%d ", p[n1 + n2]);
    pref_func(n1 + n2 + 1, s + n1 + 1, p);
    printf("%d\n", p[n1 + n2]);
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 103

int main(void) {
    char s[MAXN];
    fgets(s, MAXN, stdin);
    size_t n = strlen(s) - 1;
    s[n] = '\0';
    bool found[1000] = {0};
    for (int i = 0; i < n - 2; ++i) {
        if (s[i] == '0')
            continue;
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                size_t num = 100 * (s[i] - '0') + 10 * (s[j] - '0') + (s[k] - '0');
                found[num] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 100; i < 1000; ++i)
        if (found[i])
            ++ans;
    printf("%d", ans);
}
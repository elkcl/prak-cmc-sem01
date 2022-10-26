#include <stdio.h>
#include <string.h>

#define MAXN 1000003

int main(void) {
    char s[MAXN];
    fgets(s, MAXN, stdin);
    int n = strlen(s) - 1;
    s[n] = '\0';
    int suf_even[n], suf_odd[n];
    memset(suf_even, 0, n * sizeof(int));
    memset(suf_odd, 0, n * sizeof(int));
    for (int i = n - 2; i >= 0; --i) {
        suf_even[i] = suf_even[i + 1];
        suf_odd[i] = suf_odd[i + 1];
        if (s[i + 1] == 'A') {
            if (i % 2 == 0)
                ++suf_even[i];
            else
                ++suf_odd[i];
        }
    }
    int curr_even = 0, curr_odd = 0;
    for (int i = 0; i < n; ++i) {
        if (curr_even + suf_even[i] == curr_odd + suf_odd[i])
            printf("%d ", i + 1);
        if (s[i] == 'A') {
            if (i % 2 == 0)
                ++curr_even;
            else
                ++curr_odd;
        }
    }
}
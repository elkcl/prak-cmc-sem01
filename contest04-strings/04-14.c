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

    }
}
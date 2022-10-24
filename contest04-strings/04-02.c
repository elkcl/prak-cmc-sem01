#include <stdio.h>
#include <string.h>

#define MAXN 103
const char VOWELS[] = "aeiouyAEIOUY";

int main(void) {
    int n;
    scanf("%d", &n);
    int syl[n];
    for (int i = 0 ; i < n; ++i) {
        scanf("%d", syl + i);
    }
    while (getchar() != '\n');
    for (int i = 0; i < n; ++i) {
        char s[MAXN];
        fgets(s, MAXN, stdin);
        char *p = s;
        p += strcspn(p, VOWELS);
        size_t curr = strspn(p, VOWELS);
        int ans = 0;
        while (curr) {
            ++ans;
            p += curr;
            p += strcspn(p, VOWELS);
            curr = strspn(p, VOWELS);
        }
        if (ans == syl[i])
            fputs(s, stdout);
    }
}
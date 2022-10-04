#include <stdio.h>

typedef unsigned long long ull;

int main(void) {
    ull n;
    unsigned k;
    scanf("%lld", &n);
    scanf("%d", &k);
    n <<= 32 - k;
    unsigned add = n >> 32;
    unsigned ans = ((unsigned) n) + add;
    printf("%u", ans);
}
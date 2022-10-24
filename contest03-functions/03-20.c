#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ull MOD = 1ull + (ull) UINT_MAX;
const ull F_MAX = 281470681677826;

ull f(ull x) {
    ld xd = x;
    ull ans = (ull) floorl(sqrtl(xd));
    return x * ans;
}

ull bin_search(ll l, ll r, ull y) {
    --l;
    while (l + 1 < r) {
        ll m = l + (r - l) / 2;
        if (f(m) < y)
            l = m;
        else
            r = m;
    }
    return r;
}

unsigned g(unsigned y) {
    ull yl = y;
    do {
        ull res = bin_search(0, F_MAX, yl);
        if ((unsigned) (f((unsigned) res)) == y)
            return res;
        yl += MOD;
    } while (yl < F_MAX);
}

int main(void) {
    unsigned y;
    scanf("%u", &y);
    unsigned ans = g(y);
    printf("%u", ans);
}
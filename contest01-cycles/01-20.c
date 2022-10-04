#include <stdio.h>
#include <math.h>

#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

const long double EPS = 1e-6;

int main(void) {
    long double a, b, c, d;
    scanf("%Lf", &a);
    scanf("%Lf", &b);
    scanf("%Lf", &c);
    scanf("%Lf", &d);

    if (a < b)
        SWAP(a, b);
    if (c < d)
        SWAP(c, d);
    if (c <= a && d <= b) {
        puts("YES");
        return 0;
    }
    if (fabsl(c - d) < EPS) {
        if (b >= c)
            puts("YES");
        else
            puts("NO");
        return 0;
    }
    if (c > a && d <= b && b >= (2*c*d*a + (c*c - d*d) * sqrtl(c*c + d*d - a*a)) / (c*c+d*d)) {
        puts("YES");
        return 0;
    }
    puts("NO");
}
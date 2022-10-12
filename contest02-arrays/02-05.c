#include <stdio.h>
#include <math.h>

typedef long double ld;

const ld EPS = 1e-7;

typedef struct {
    ld x, y, z, r;
} Ball;

ld dist(Ball b1, Ball b2) {
    ld x = b1.x - b2.x;
    ld y = b1.y - b2.y;
    ld z = b1.z - b2.z;
    return sqrtl(x*x + y*y + z*z);
}

int main(void) {
    int n;
    scanf("%d", &n);
    Ball b[n];
    for (int i = 0; i < n; ++i)
        scanf("%Lf %Lf %Lf %Lf", &b[i].x, &b[i].y, &b[i].z, &b[i].r);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (dist(b[i], b[j]) <= b[i].r + b[j].r + EPS) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
}
#include <stdio.h>
#include <math.h>

typedef long double ld;
typedef struct {
    ld x, y;
} Point;

Point plus(Point a, Point b) {
    return (Point){a.x + b.x, a.y + b.y};
}

Point minus(Point a, Point b) {
    return (Point){a.x - b.x, a.y - b.y};
}

Point scale(ld k, Point a) {
    return (Point){k * a.x, k * a.y};
}

ld len(Point a) {
    return sqrtl(a.x * a.x + a.y * a.y);
}

Point bisect(Point a, Point b, Point c) {
    ld ab = len(minus(a, b));
    ld bc = len(minus(b, c));
    Point ac = minus(c, a);
    ld n = ab / (ab + bc);
    return plus(a, scale(n, ac));
}

int main(void) {
    Point a, b, c;
    scanf("%Lf %Lf", &a.x, &a.y);
    scanf("%Lf %Lf", &b.x, &b.y);
    scanf("%Lf %Lf", &c.x, &c.y);

    Point res1 = bisect(a, c, b);
    Point res2 = bisect(b, a, c);
    Point res3 = bisect(a, b, c);

    printf("%.5Lf %.5Lf\n", res1.x, res1.y);
    printf("%.5Lf %.5Lf\n", res2.x, res2.y);
    printf("%.5Lf %.5Lf\n", res3.x, res3.y);
}
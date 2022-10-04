#include <stdio.h>

int main(void) {
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf", &x1);
    scanf("%lf", &y1);
    scanf("%lf", &x2);
    scanf("%lf", &y2);
    scanf("%lf", &x3);
    scanf("%lf", &y3);

    double x = (x1 + x2 + x3) / 3;
    double y = (y1 + y2 + y3) / 3;
    printf("%.4lf %.4lf", x, y);
}
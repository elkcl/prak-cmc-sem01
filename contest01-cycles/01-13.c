#include <stdio.h>

int main(void) {
    double x;
    int n;
    scanf("%lf", &x);
    scanf("%d", &n);
    double res = x;
    int denom = 3;
    double curr = -x*x*x/6;
    for (int i = 0; i < n - 1; ++i) {
        res += curr;
        curr *= -x*x / ((denom + 1) * (denom + 2));
        denom += 2;
    }
    printf("%.6lf", res);
}
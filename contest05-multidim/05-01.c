#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    ll a, b;
} complex;

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 0)
        return 0;
    complex (*m)[n] = malloc(sizeof(complex[n][n]));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%Ld", &m[i][j].a);
            scanf("%Ld", &m[i][j].b);
            m[i][j].b *= -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%Ld %Ld ", m[j][i].a, m[j][i].b);
        }
        putchar('\n');
    }
    free(m);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

typedef long long ll;

int main(void) {
    int n = 3;
    int m = 5;
    int k = 10;
    printf("%lu\n", sizeof(int));
    ll *a = malloc(sizeof(*a));
    printf("%lu\n", sizeof(*a));
    int (*b)[m] = calloc(n, sizeof(*b));
    printf("%lu\n", sizeof(*b));
    ll (*c)[m][k] = calloc(n, sizeof(*c));
    free(a);
    free(b);
    free(c);
}
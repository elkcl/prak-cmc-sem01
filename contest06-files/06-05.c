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
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    ll res = 0;
    fscanf(in, "%lld", &res);
    while (1) {
        char op;
        while ((op = fgetc(in)) == ' ')
            ;
        if (op == EOF)
            break;
        ll op2 = 0;
        fscanf(in, "%lld", &op2);
        if (op == '+')
            res += op2;
        else
            res -= op2;
    }
    fprintf(out, "%lld", res);

    fclose(out);
    fclose(in);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

typedef long long ll;

int main(void) {
    FILE *in = fopen("matrix.in", "rb");
    FILE *out = fopen("trace.out", "wb");
    unsigned char buf[8];
    fread(buf, sizeof(*buf), 2, in);
    int n = (int)buf[0]<<8 | (int)buf[1];
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fread(buf, sizeof(*buf), 4, in);
            if (i == j) {
                uint32_t x = (uint32_t)buf[0]<<24 | (uint32_t)buf[1]<<16 | (uint32_t)buf[2]<<8 | (uint32_t)buf[3];
                ans += *(int32_t*) &x;
            }
        }
    }
    for (int i = 0; i < 8; ++i)
        buf[i] = ans >> (56 - 8 * i);
    fwrite(buf, sizeof(*buf), 8, out);

    fclose(out);
    fclose(in);
}
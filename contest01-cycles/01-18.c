#include <stdio.h>

typedef unsigned int ui;

int main(void) {
    ui mat;
    scanf("%x", &mat);
    ui res = 0;
    ui mask2 = 1;
    for (ui i = 0; i < 4; ++i) {
        ui mask1 = 1 << i;
        for (int j = 0; j < 4; ++j) {
            if (mat & mask1)
                res |= mask2;
            mask1 <<= 4;
            mask2 <<= 1;
        }
    }
    printf("%04x", res);
}
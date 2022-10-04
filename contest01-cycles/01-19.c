#include <stdio.h>
#include <stdbool.h>

typedef unsigned int ui;

#define PASS(_x, _y) (((ca11 && _x) != (ca12 && _y)) == cb1 &&((ca21 && _x) != (ca22 && _y)) == cb2)

int main(void) {
    ui a11, a12, a21, a22, b1, b2;
    scanf("%d", &a11);
    scanf("%d", &a12);
    scanf("%d", &a21);
    scanf("%d", &a22);
    scanf("%d", &b1);
    scanf("%d", &b2);

    ui x = 0;
    ui y = 0;
    for (ui mask = 1; mask != 0; mask <<= 1) {
        bool ca11 = mask & a11;
        bool ca12 = mask & a12;
        bool ca21 = mask & a21;
        bool ca22 = mask & a22;
        bool cb1 = mask & b1;
        bool cb2 = mask & b2;

        if (PASS(false, false)) {

        } else if (PASS(true, false)) {
            x |= mask;
        } else if (PASS(false, true)) {
            y |= mask;
        } else if (PASS(true, true)) {
            x |= mask;
            y |= mask;
        } else {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    printf("%u %u", x, y);
}
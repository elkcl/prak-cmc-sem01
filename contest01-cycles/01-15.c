#include <stdio.h>
#include <stdbool.h>

#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)
#define SHIFT3(_x1, _x2, _x3, _x4) do { _x1 = _x2; _x2 = _x3; _x3 = _x4; } while (0)

bool check3(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x1 - x2) * (y3 - y2) - (x3 - x2) * (y1 - y2) > 0;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int x1, y1, x2, y2, x3, y3, fx1, fy1, fx2, fy2;
    scanf("%d", &x1);
    scanf("%d", &y1);
    scanf("%d", &x2);
    scanf("%d", &y2);
    scanf("%d", &x3);
    scanf("%d", &y3);
    fx1 = x1;
    fy1 = y1;
    fx2 = x2;
    fy2 = y2;
    bool last = check3(x1, y1, x2, y2, x3, y3);

    for (int i = 0; i < n - 3; ++i) {
        int x4, y4;
        scanf("%d", &x4);
        scanf("%d", &y4);
        SHIFT3(x1, x2, x3, x4);
        SHIFT3(y1, y2, y3, y4);
        if (last != check3(x1, y1, x2, y2, x3, y3)) {
            puts("No");
            return 0;
        }
    }
    SHIFT3(x1, x2, x3, fx1);
    SHIFT3(y1, y2, y3, fy1);
    if (last != check3(x1, y1, x2, y2, x3, y3)) {
        puts("No");
        return 0;
    }
    SHIFT3(x1, x2, x3, fx2);
    SHIFT3(y1, y2, y3, fy2);
    if (last != check3(x1, y1, x2, y2, x3, y3)) {
        puts("No");
        return 0;
    }
    puts("Yes");
}
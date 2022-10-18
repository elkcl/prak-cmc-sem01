#include <stdio.h>
#include <stdbool.h>

bool solve(int n) {
    if (n == 0) {
        int x1, y1;
        scanf("%d %d", &x1, &y1);
        return true;
    }
    int x1, y1, x2, y2;
    scanf("%d %d", &x1, &y1);
    bool res = solve(n - 1);
    if (!res)
        return false;
    scanf("%d %d", &x2, &y2);
    if (x1 == -x2 && y1 == y2)
        return true;
    else
        return false;
}

int main(void) {
    int n, x1, y1;
    scanf("%d", &n);
    scanf("%d %d", &x1, &y1);
    bool ans = solve(n / 2 - 1);
    if (ans)
        puts("Yes\n");
    else
        puts("No\n");
}
#include <stdio.h>

typedef unsigned int ui;

int main(void) {
    int n;
    scanf("%d", &n);
    ui res = 0;
    for (int i = 0; i < n; ++i) {
        ui curr;
        scanf("%d", &curr);
        res ^= curr;
    }
    printf("%u", res);
}
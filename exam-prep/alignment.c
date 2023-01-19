#include <stdio.h>

struct a {
    char x[10];
    int y;
};

int main(void) {
    printf("%zu\n", sizeof(long double));
    printf("%zu\n", sizeof(struct a));
}
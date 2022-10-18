#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 0)
        return 0;
    main();
    printf("%d ", n);
}
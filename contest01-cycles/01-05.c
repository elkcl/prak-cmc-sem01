#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int curr;
    scanf("%d", &curr);
    int sum = 0;
    int prod = 1;
    bool add = true;
    while (curr != 0) {
        prod *= curr;
        if (add) {
            sum += prod;
            prod = 1;
            add = false;
        } else {
            add = true;
        }
        scanf("%d", &curr);
    }
    if (add)
        sum += prod;
    printf("%d", sum);
}
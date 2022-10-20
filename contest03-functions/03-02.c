#include <stdio.h>
#include <stdbool.h>

bool isprime(int n) {
    if (n == 1)
        return false;
    for (int d = 2; d * d <= n; ++d) {
        if (n % d == 0)
            return false;
    }
    return true;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while(!isprime(n))
        ++n;
    printf("%d", n);
}
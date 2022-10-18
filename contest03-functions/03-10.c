#include <stdio.h>
#include <stdbool.h>

typedef long long ll;

ll parse(void) {
    int c = getchar();
    while (c == ' ')
        c = getchar();
    if (c == '*') {
        ll a = parse();
        ll b = parse();
        return a * b;
    } else if (c == '/') {
        ll a = parse();
        ll b = parse();
        return a / b;
    } else {
        bool minus = false;
        ll a = 0;
        if (c == '-')
            minus = true;
        else
            a = c - '0';
        c = getchar();
        while (c != ' ' && c != '\n') {
            a *= 10;
            a += c - '0';
            c = getchar();
        }
        if (minus)
            return -a;
        else
            return a;
    }
}

int main(void) {
    printf("%Ld", parse());
}
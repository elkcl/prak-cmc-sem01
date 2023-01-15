#include <stdio.h>
#include <string.h>

int main(void) {
    char h = '2';
    const char e[] = "lestale";
    const char *s = &e[2];

    printf("%d\n", !(strcmp(s, "stale") | memcmp(e, "lest", 4)));
    printf("%d\n", s == h - '0' + e);
    printf("%d\n", sizeof e < 9);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int l;
    scanf("%d", &l);
    char *s1 = malloc((l + 1) * sizeof(char));
    char *s2 = malloc((l + 1) * sizeof(char));
    char *s3 = malloc((l + 1) * sizeof(char));
    while (getchar() != '\n')
        ;
    int c;
    fgets(s1, l + 1, stdin);
    do {
        c = getchar();
    } while (c == ' ' || c == '\n');
    ungetc(c, stdin);
    fgets(s2, l + 1, stdin);
    do {
        c = getchar();
    } while (c == ' ' || c == '\n');
    ungetc(c, stdin);
    fgets(s3, l + 1, stdin);
    for (int i = 0; i < l; ++i)
        putchar(s3[i]);
    for (int i = 0; i < l; ++i)
        putchar(s1[i]);
    for (int i = 0; i < l; ++i)
        putchar(s2[i]);
    free(s1);
    free(s2);
    free(s3);
}
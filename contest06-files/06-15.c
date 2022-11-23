#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <stdint.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

typedef long long ll;

enum Constants {
    MAXN = 103
};

typedef struct {
    char s[MAXN];
    unsigned int ip;
} Entry;

int entry_cmp(const void *a, const void *b) {
    const Entry *ea = a;
    const Entry *eb = b;
    return strcmp(ea->s, eb->s);
}

int main(void) {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int n;
    fscanf(in, "%d", &n);
    Entry *arr = malloc(n * sizeof(*arr));
    for (int i = 0; i < n; ++i) {
        while (fgetc(in) != '\n')
            ;
        fscanf(in, "%102s", arr[i].s);
        fscanf(in, "%u", &arr[i].ip);
    }
    qsort(arr, n, sizeof(*arr), entry_cmp);
    int m;
    fscanf(in, "%d", &m);
    while (m--) {
        char curr[MAXN];
        fscanf(in, "%102s", curr);
        int l = -1;
        int r = n;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (strcmp(arr[mid].s, curr) < 0)
                l = mid;
            else
                r = mid;
        }
        if (r == n || strcmp(arr[r].s, curr) != 0)
            fprintf(out, "%d\n", -1);
        else
            fprintf(out, "%u\n", arr[r].ip);

    }

    free(arr);
    fclose(out);
    fclose(in);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

typedef long long ll;

int main(void) {
    FILE *in = fopen("input.bin", "rb");
    FILE *out = fopen("output.bin", "wb");
    int *arr1 = malloc(1 * sizeof(*arr1));
    int *arr2 = malloc(2 * sizeof(*arr1));
    fread(arr1, sizeof(int), 1, in);
    int ans = 2;
    size_t curr_s = 2;
    size_t n = 0;
    while ((n = fread(arr2, sizeof(int), curr_s, in))) {
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (arr2[i] < arr1[i / 2]) {
                if (ans == 2) {
                    ans = -1;
                } else if (ans == 1) {
                    ans = 0;
                    flag = false;
                    break;
                }
            } else if (arr2[i] > arr1[i / 2]) {
                if (ans == 2) {
                    ans = 1;
                } else if (ans == -1) {
                    ans = 0;
                    flag = false;
                    break;
                }
            }
        }
        if (!flag)
            break;
        SWAP(arr1, arr2);
        curr_s *= 2;
        arr2 = realloc(arr2, curr_s * sizeof(*arr2));
    }

    if (ans == 2)
        ans = 1;
    fwrite(&ans, sizeof(int), 1, out);

    free(arr2);
    free(arr1);
    fclose(out);
    fclose(in);
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 25
#define MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))

typedef struct {
    size_t size;
    char s[MAXN];
} string;

int permutations(int n, const string arr[], bool used[], char last, int curr) {
    if (curr == n)
        return curr;
    int ans = curr;
    for (int i = 0; i < n; ++i) {
        if (used[i] || arr[i].s[0] != last)
            continue;
        used[i] = true;
        int new = permutations(n, arr, used, arr[i].s[arr[i].size - 1], curr + 1);
        ans = MAX(ans, new);
        used[i] = false;
    }
    return ans;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while (getchar() != '\n');
    string arr[n];
    bool used[n];
    memset(used, false, n * sizeof(bool));
    for (int i = 0; i < n; ++i) {
        fgets(arr[i].s, MAXN, stdin);
        arr[i].size = strlen(arr[i].s) - 1;
        arr[i].s[arr[i].size] = '\0';
    }
    int ans[n];
    int max = 0;
    for (int i = 0; i < n; ++i) {
        used[i] = true;
        ans[i] = permutations(n, arr, used, arr[i].s[arr[i].size - 1], 1);
        used[i] = false;
        max = MAX(max, ans[i]);
    }
    printf("%d\n", max);
    for (int i = 0; i < n; ++i)
        if (ans[i] == max)
            puts(arr[i].s);
}
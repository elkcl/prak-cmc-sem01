#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

enum Constants {
    ALPH = 26,
    FIRST = 'a',
    MAXN = 2003
};

typedef long long ll;

typedef struct {
    int next[ALPH];
    int l, r;
} Node;

typedef struct {
    int capacity, size;
    Node *nodes;
} Trie;

void trie_insert(Trie *t, int l, int r, const char *s) {
    int v = 0;
    while (l < r) {
        int c = s[l] - FIRST;
        if (t->nodes[v].next[c] == -1) {
            t->nodes[v].next[c] = t->size;
            memset(t->nodes[t->size].next, -1, ALPH * sizeof(int));
            t->nodes[t->size].l = l;
            t->nodes[t->size].r = r;
            ++t->size;
            break;
        } else {
            int to = t->nodes[v].next[c];
            int j = t->nodes[to].l;
            for (; j < t->nodes[to].r && l < r; ++j, ++l) {
                if (s[j] != s[l])
                    break;
            }
            if (j < t->nodes[to].r && l < r) {
                int mid = t->size;
                ++t->size;
                t->nodes[v].next[c] = mid;
                memset(t->nodes[mid].next, -1, ALPH * sizeof(int));
                t->nodes[mid].l = t->nodes[to].l;
                t->nodes[mid].r = j;

                t->nodes[mid].next[s[j] - FIRST] = to;
                t->nodes[to].l = j;

                t->nodes[mid].next[s[l] - FIRST] = t->size;
                memset(t->nodes[t->size].next, -1, ALPH * sizeof(int));
                t->nodes[t->size].l = l;
                t->nodes[t->size].r = r;
                ++t->size;
                break;
            }
            v = to;
        }
    }
}

Trie trie_build(int n, const char *s) {
    Trie res;
    res.capacity = 2 * n;
    res.nodes = malloc(res.capacity * sizeof(Node));
    res.size = 1;
    res.nodes[0].l = res.nodes[0].r = -1;
    memset(res.nodes[0].next, -1, ALPH * sizeof(int));
    for (int i = 0; i < n; ++i) {
        trie_insert(&res, i, n, s);
    }
    return res;
}

int trie_cnt(Trie *t, int v) {
    int ans = t->nodes[v].r - t->nodes[v].l;
    for (int i = 0; i < ALPH; ++i) {
        if (t->nodes[v].next[i] == -1)
            continue;
        ans += trie_cnt(t, t->nodes[v].next[i]);
    }
    return ans;
}

void trie_free(Trie *t) {
    free(t->nodes);
}

int main(void) {
    char s[MAXN];
    fgets(s, MAXN, stdin);
    int n = strlen(s) - 1;
    s[n] = '\0';
    Trie t = trie_build(n, s);
    int ans = 1 + trie_cnt(&t, 0);
    printf("%d\n", ans);
    trie_free(&t);
}
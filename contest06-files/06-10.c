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

typedef struct Node {
    int key;
    struct Node *l, *r;
} Node;

int main(void) {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    int n, m;
    fscanf(in, "%d", &n);
    fscanf(in, "%d", &m);
    Node *list = malloc(n * sizeof(*list));
    list[0].l = NULL;
    list[0].r = &list[1];
    list[0].key = 0;
    list[n - 1].l = &list[n - 2];
    list[n - 1].r = NULL;
    list[n - 1].key = n - 1;
    for (int i = 1; i < n - 1; ++i) {
        list[i].l = &list[i - 1];
        list[i].r = &list[i + 1];
        list[i].key = i;
    }
    Node *head = &list[0];

    while (m--) {
        int b, c;
        fscanf(in, "%d", &b);
        fscanf(in, "%d", &c);
        --b, --c;
        if (head->key == b)
            continue;
        Node *prev = list[b].l;
        Node *next = list[c].r;
        list[b].l = NULL;
        list[c].r = head;
        head->l = &list[c];
        head = &list[b];
        if (prev != NULL)
            prev->r = next;
        if (next != NULL)
            next->l = prev;
    }

    while (head != NULL) {
        fprintf(out, "%d ", head->key + 1);
        head = head->r;
    }
    fputc('\n', out);

    free(list);
    fclose(out);
    fclose(in);
}
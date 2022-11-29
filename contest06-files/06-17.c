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

typedef struct node {
    int key, val;
    unsigned y;
    struct node *l, *r;
} node;

typedef struct {
    node *l, *r;
} node_pair;

typedef struct {
    int n;
    node *root;
} treap;

node_pair node_split_l(node *t, int k) {
    if (t == NULL)
        return (node_pair){NULL, NULL};
    if (k >= t->key) {
        node_pair p = node_split_l(t->r, k);
        t->r = p.l;
        return (node_pair){t, p.r};
    }
    node_pair p = node_split_l(t->l, k);
    t->l = p.r;
    return (node_pair){p.l, t};
}

node_pair node_split_r(node *t, int k) {
    if (t == NULL)
        return (node_pair){NULL, NULL};
    if (k > t->key) {
        node_pair p = node_split_r(t->r, k);
        t->r = p.l;
        return (node_pair){t, p.r};
    }
    node_pair p = node_split_r(t->l, k);
    t->l = p.r;
    return (node_pair){p.l, t};
}

node* node_merge(node *t1, node *t2) {
    if (t1 == NULL)
        return t2;
    if (t2 == NULL)
        return t1;
    if (t1->y > t2->y) {
        t1->r = node_merge(t1->r, t2);
        return t1;
    }
    t2->l = node_merge(t1, t2->l);
    return t2;
}

node* node_make(int k, int val) {
    node *res = malloc(sizeof(node));
    res->key = k;
    res->val = val;
    res->l = res->r = NULL;
    res->y = ((unsigned) rand() << 16) ^ (unsigned) rand();
    return res;
}

void node_free(node *t) {
    if (t == NULL)
        return;
    node_free(t->l);
    node_free(t->r);
    free(t);
}

treap treap_make(void) {
    return (treap){0, NULL};
}

void treap_free(treap *t) {
    node_free(t->root);
}

void treap_delete(treap *t, int k) {
    if (t->root == NULL)
        return;
    node_pair p1 = node_split_r(t->root, k);
    if (p1.r == NULL) {
        t->root = p1.l;
        return;
    }
    node_pair p2 = node_split_l(p1.r, k);
    node_free(p2.l);
    t->root = node_merge(p1.l, p2.r);
}

void treap_insert(treap *t, int k, int val) {
    treap_delete(t, k);
    if (t->root == NULL) {
        t->root = node_make(k, val);
        t->n = 1;
        return;
    }
    node *new = node_make(k, val);
    node_pair p = node_split_l(t->root, k);
    t->root = node_merge(node_merge(p.l, new), p.r);
}

typedef struct {
    bool found;
    int ans;
} lookup_ans;

lookup_ans treap_lookup(const treap *t, int k) {
    if (t->root == NULL)
        return (lookup_ans){false, -1};
    node *curr = t->root;
    while (curr->key != k) {
        if (k < curr->key) {
            if (curr->l == NULL)
                break;
            curr = curr->l;
        } else {
            if (curr->r == NULL)
                break;
            curr = curr->r;
        }
    }
    if (curr->key == k)
        return (lookup_ans){true, curr->val};
    else
        return (lookup_ans){false, -1};
}

int main(void) {
    treap t = treap_make();
    while (true) {
        int c = getchar();
        while (c == ' ' || c == '\n')
            c = getchar();
        if (c == 'A') {
            int k, v;
            scanf("%d", &k);
            scanf("%d", &v);
            treap_insert(&t, k, v);
        } else if (c == 'D') {
            int k;
            scanf("%d", &k);
            treap_delete(&t, k);
        } else if (c == 'S') {
            int k;
            scanf("%d", &k);
            lookup_ans x = treap_lookup(&t, k);
            if (x.found)
                printf("%d %d\n", k, x.ans);
        } else {
            break;
        }
    }
    treap_free(&t);
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int cnt = 0;

struct node {
    int k, v, h;
    struct node *l, *r;
};
typedef struct node node;

int h(const node *t) {
    if (t == NULL)
        return 0;
    return t->h;
}

int bf(const node *t) {
    return h(t->r) - h(t->l);
}

void fixh(node *t) {
    int hl = h(t->l);
    int hr = h(t->r);
    t->h = (hl > hr) ? hl : hr;
    ++t->h;
}

node* find_key(node *t, int key) {
    if (t == NULL)
        return NULL;
    if (key == t->k)
        return t;
    if (key < t->k)
        return find_key(t->l, key);
    return find_key(t->r, key);
}

node* find_min(node *t) {
    if (t->l == NULL)
        return t;
    return find_min(t->l);
}

node* rot_left(node *a) {
    if (a->k == 33)
        ++cnt;
    node *b = a->r;
    a->r = b->l;
    b->l = a;
    fixh(a);
    fixh(b);
    return b;
}

node* rot_right(node *a) {
    node *b = a->l;
    a->l = b->r;
    b->r = a;
    fixh(a);
    fixh(b);
    return b;
}

node* balance(node *a) {
    fixh(a);
    if (bf(a) == 2) {
        if (bf(a->r) == -1)
            a->r = rot_right(a->r);
        return rot_left(a);
    } else if (bf(a) == -2) {
        if (bf(a->l) == 1)
            a->l = rot_left(a->l);
        return rot_right(a);
    }
    return a;
}

node* insert(node *t, int k, int v) {
    if (t == NULL) {
        node *r = static_cast<node *>(calloc(1, sizeof(*r)));
        r->k = k;
        r->v = v;
        r->h = 1;
        return r;
    }
    if (k == t->k) {
        t->v = v;
        return t;
    }
    if (k < t->k)
        t->l = insert(t->l, k, v);
    else
        t->r = insert(t->r, k, v);
    return balance(t);
}

node* remove_min(node *t) {
    if (t->l == NULL)
        return t->r;
    t->l = remove_min(t->l);
    return balance(t);
}

node* remove_key(node *t, int k) {
    if (t == NULL)
        return NULL;
    if (k < t->k) {
        t->l = remove_key(t->l, k);
    } else if (k > t->k) {
        t->r = remove_key(t->r, k);
    } else {
        node *l = t->l;
        node *r = t->r;
        free(t);
        if (r == NULL)
            return l;
        t = find_min(r);
        t->r = remove_min(r);
        t->l = l;
    }
    return balance(t);
}

void node_free(node *t) {
    if (t == NULL)
        return;
    node_free(t->l);
    node_free(t->r);
    free(t);
}

int main() {
    vector<int> v{69, 58, 62, 87, 75, 98, 15, 77, 33, 80};
    do {
        cnt = 0;
        node *t = nullptr;
        for (auto e : v)
            t = insert(t, e, 0);
        if (cnt == 3) {
            for (auto e : v)
                cout << e << ' ';
            cout << '\n';
            return 0;
        }
        node_free(t);
    } while (next_permutation(v.begin(), v.end()));
}
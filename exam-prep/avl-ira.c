#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node *avl;

struct node {
    int key;
    int height;
    struct node *left;
    struct node *right;
    int data;
};


avl find(avl p, int k) {
    if (!p) return NULL;
    if (p->key == k) {
        return p;
    }
    if (p->key > k) {
        return find(p->left, k);
    }
    if (p->key < k) {
        return find(p->right, k);
    }
    return NULL;
}

int bfactor(avl p) {
    int hl = (p->left != NULL) ? (p->left)->height : 0;
    int hr = (p->right != NULL) ? (p->right)->height : 0;
    int bp = hr - hl;
    return bp;
}

void fixheight(avl p) {
    int hl = (p->left != NULL) ? (p->left)->height : 0;
    int hr = (p->right != NULL) ? (p->right)->height : 0;
    p->height = 1 + (hl > hr ? hl : hr);
}

avl rightrotate(avl p) {
    avl q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

avl leftrotate(avl p) {
    avl q = p->right;
    p->right = q->left;
    q->left = p;
    fixheight(p);
    fixheight(q);
    return q;
}

avl balance(avl p) {
    fixheight(p);
    int bp = bfactor(p);
    // 2 - вправо - влево
    if (bp == 2) {
        if (bfactor(p->right) == -1) {
            p->right = rightrotate(p->right);
        }
        p = leftrotate(p);
        return p;
    }
    // -2 - влево - вправо
    if (bp == -2) {
        if (bfactor(p->left) == 1) {
            p->left = leftrotate(p->left);
        }
        p = rightrotate(p);
        return p;
    }
    return p; // bp != +-2 - ничего делать не нужно
}

avl add(avl p, int key, int data) {
    if (p == NULL) {
        avl q = calloc(1, sizeof(struct node));
        q->key = key;
        q->left = NULL;
        q->right = NULL;
        q->height = 1;
        q->data = data;
        return q;
    }
    if (p->key == key) {
        p->data = data;
        return p;
    }
    (p->key > key) ? (p->left = add(p->left, key, data)) : (p->right = add(p->right, key, data));
    return balance(p);
}

avl findmin(avl p) {
    return (p->left) ? p->left : p;
}

avl delmin(avl p) {
    if (!(p->left)) {
        return p->right;
    }
    p->left = delmin(p->left);
    return balance(p);
}

avl delete(avl p, int k) {
    if (!p) return NULL;
    if (p->key > k) {
        p->left = delete(p->left, k);
    } else if (p->key < k) {
        p->right = delete(p->right, k);
    } else if (p->key == k) {
        avl q = p->left;
        avl r = p->right;
        free(p);
        if (!r) return q;
        avl min = findmin(r);
        min->right = delmin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

void free_node(avl p){
    if (!p) return;
    free_node(p->right);
    free_node(p->left);
    free(p);
}

int main(void) {
    avl p = NULL;
    while (true) {
        int s = getchar();
        while (s == ' ' || s == '\n')
            s = getchar();
        int key, data;
        if (s == 'A') {
            scanf("%d", &key);
            scanf("%d", &data);
            p = add(p, key, data);
        } else if (s == 'D') {
            scanf("%d", &key);
            p = delete(p, key);
        } else if (s == 'S') {
            scanf("%d", &key);
            avl m = find(p, key);
            if (m != NULL) printf("%d %d\n", key, m->data);
        } else break;
    }
    free_node(p);
    return 0;
}
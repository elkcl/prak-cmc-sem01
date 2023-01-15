#include <stdio.h>

struct node {
    int x;
    struct node *l, *r;
};

int find(struct node *t, int k) {
    if (t == NULL)
        return 0;
    if (k == t->x)
        return 1;
    if (k < t->x)
        return find(t->l, k);
    return find(t->r, k);
}

int is_subset(int size, struct node *t1, struct node *t2) {
    if (t1 == NULL)
        return 1;
    return find(t2, t1->x) && is_subset(size, t1->l, t2) && is_subset(size, t1->r, t2);
}

void print_tree(struct node *t) {
    if (t == NULL)
        return;
    print_tree(t->l);
    printf("%d ", t->x);
    print_tree(t->r);
}

int main(void) {
    struct node t1_3 = {3, NULL, NULL};
    struct node t1_2 = {2, NULL, &t1_3};
    struct node t1 = {1, NULL, &t1_2};

    struct node t2_5 = {5, NULL, NULL};
    struct node t2_4 = {4, NULL, &t2_5};
    struct node t2_3 = {3, NULL, &t2_4};
    struct node t2_2 = {2, NULL, &t2_3};
    struct node t2 = {1, NULL, &t2_2};

    print_tree(&t1);
    putchar('\n');
    print_tree(&t2);
    putchar('\n');
    printf("%d\n", is_subset(3, &t1, &t2));
    printf("%d\n", is_subset(5, &t2, &t1));
}
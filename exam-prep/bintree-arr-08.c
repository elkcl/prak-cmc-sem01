#include <stdio.h>
#include <stdlib.h>

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

int tree_to_arr(int n, int arr[n], int i, struct node *t) {
    if (t == NULL)
        return 0;
    int s1 = tree_to_arr(n, arr, i, t->l);
    arr[i + s1] = t->x;
    return s1 + 1 + tree_to_arr(n, arr, i + s1 + 1, t->r);
}

int rec_subset(int n, const int arr1[n], int i, struct node *t2) {
    if (t2 == NULL)
        return i;
    i = rec_subset(n, arr1, i, t2->l);
    if (i == -1 || i == n)
        return i;
    if (t2->x > arr1[i])
        return -1;
    if (t2->x == arr1[i])
        ++i;
    if (i == n)
        return i;
    return rec_subset(n, arr1, i, t2->r);
}

int is_subset(int size, struct node *t1, struct node *t2) {
    int *arr1 = malloc(size * sizeof(*arr1));
    tree_to_arr(size, arr1, 0, t1);
    int ans = rec_subset(size, arr1, 0, t2);
    free(arr1);
    if (ans == size)
        return 1;
    else
        return 0;
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
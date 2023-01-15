#include <stdio.h>

struct Tree {
    int key;
    struct Tree *left, *right;
};

int layer_size(const struct Tree *root, int n) {
    if (root == NULL)
        return 0;
    if (n == 1)
        return 1;
    return layer_size(root->left, n - 1) + layer_size(root->right, n - 1);
}

int main(void) {
    struct Tree arr[] = {
            {0, arr + 1, arr + 2},
            {1, arr + 3, arr + 4},
            {2, NULL, arr + 5},
            {3, NULL, NULL},
            {4, arr + 6, NULL},
            {5, arr + 7, NULL},
            {6, NULL, NULL},
            {7, NULL, arr + 8},
            {8, NULL, NULL}
    };
    printf("%d\n", layer_size(arr, 0));
    printf("%d\n", layer_size(arr, 1));
    printf("%d\n", layer_size(arr, 2));
    printf("%d\n", layer_size(arr, 3));
    printf("%d\n", layer_size(arr, 4));
    printf("%d\n", layer_size(arr, 5));
    printf("%d\n", layer_size(arr, 6));
}
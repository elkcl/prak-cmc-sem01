#include <stdio.h>
#include <stdlib.h>

typedef int key_t;
struct avlnode;
typedef struct avlnode *avltree;
struct avlnode {
    key_t key;
    int data;
    avltree left;
    avltree right;
    int height;
};


static inline int max (int a, int b) {
    return a > b ? a : b;
}
static inline int height (avltree p) {
    return p ? p->height : 0;
}

static avltree SingleRotateWithLeft (avltree k2) {
    avltree k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max (height (k2->left),
                      height (k2->right)) + 1;
    k1->height = max (height (k1->left), k2->height) + 1;
    return k1;
}

static avltree SingleRotateWithRight (avltree k1) {
    avltree k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max (height (k1->left),
                      height (k1->right)) + 1;
    k2->height = max (height (k2->right), k1->height) + 1;
    return k2;
}

static avltree DoubleRotateWithLeft (avltree k3) {
    k3->left = SingleRotateWithRight (k3->left);
    return SingleRotateWithLeft (k3);
}

static avltree DoubleRotateWithRight (avltree k1) {
    k1->right = SingleRotateWithLeft (k1->right);
    return SingleRotateWithRight(k1);
}

avltree insert (key_t x, int y,  avltree t) {
    if (t == NULL) {
        t = malloc (sizeof (struct avlnode));
        if (!t)
            abort();
        t->key = x;
        t->data = y;
        t->height = 1;
        t->left = t->right = NULL;
    }
    else if (x < t->key) {
        t->left = insert (x, y, t->left);
        if (height (t -> left) - height(t -> right) == 2){
            if (x < t->left->key)
                t = SingleRotateWithLeft (t);
            else
                t = DoubleRotateWithLeft (t);
        }
    }
    else if (x > t->key) {
        t->right = insert (x, y, t->right);
        if (height (t -> right) - height(t -> left) == 2){
            if (x > t->right->key)
                t = SingleRotateWithRight (t);
            else
                t = DoubleRotateWithRight (t);
        }
    }
    else
        t -> data = y;
    t->height = max (height (t->left), height (t->right)) + 1;
    return t;
}

avltree find (key_t x, avltree t) {
    if (t == NULL || x == t->key)
        return t;
    if (x < t->key)
        return find (x, t->left);
    return find (x, t->right);
}

avltree minValue(avltree t)
{
    avltree current = t;
    while (current->left != NULL)
        current = current->left;
    return current;
}

int getBalance(avltree t)
{
    if (t == NULL)
        return 0;
    return height(t->left) - height(t->right);
}

avltree dele(avltree t, int key)
{
    if (t == NULL){
        return t;
    }
    if ( key < t->key )
        t->left = dele(t->left, key);

    else if( key > t->key )
        t->right = dele(t->right, key);
    else
    {
        if( (t->left == NULL) || (t->right == NULL) )
        {
            avltree temp = t->left ? t->left : t->right;
            if (temp == NULL)
            {
                temp = t;
                t = NULL;
            }
            else
                *t = *temp;
            free(temp);
        }
        else
        {
            avltree temp = minValue(t->right);
            t->key = temp->key;
            t->data = temp->data;
            t->right = dele(t->right, temp->key);
        }
    }
    if (t == NULL)
        return t;

    int balance = getBalance(t);
    t->height = 1 + max(height(t->left), height(t->right));
    if (balance > 1 && getBalance(t->left) >= 0)
        return SingleRotateWithRight(t);
    if (balance > 1 && getBalance(t->left) < 0)
    {
        t->left =  SingleRotateWithLeft(t->left);
        return SingleRotateWithRight(t);
    }
    if (balance < -1 && getBalance(t->right) <= 0)
        return SingleRotateWithLeft(t);

    if (balance < -1 && getBalance(t->right) > 0)
    {
        t->right = SingleRotateWithRight(t->right);
        return SingleRotateWithLeft(t);
    }
    return t;
}


int main(void){
    char a;
    scanf("%c", &a);
    int key, data;
    avltree t = NULL;
    while (a != 'F'){
        if (a == 'A'){
            scanf("%d %d", &key, &data);
            t = insert(key, data, t);
        }
        else if (a == 'S'){
            scanf("%d", &key);
            avltree found = find(key, t);
            if (found)
                printf("%d %d\n", key, found->data);
        }
        else if (a == 'D'){
            scanf("%d", &key);
            dele(t, key);
        }
        scanf("%c", &a);
    }
}


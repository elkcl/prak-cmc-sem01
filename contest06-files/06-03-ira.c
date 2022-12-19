#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data;

typedef struct Node Node;
struct Node {
    Data data;
    Node * next;
};

void push(Node *plist, Data d) {
    Node *p = malloc(sizeof(Node));
    Node *t = plist;
    if (plist == NULL) {
        plist->data = d;
        plist->next = p;
        return;
    }
    while (t->data < d && t->next != NULL) {
        t=t->next;
    }
    if (t->next == NULL) {
        Node * k = malloc(sizeof(Node));
        t->next = k;
        k->data = d;
        k->next = p;
        return;
    }
    if (t->next->data >= d) {
        Node * k = malloc(sizeof(Node));
        p = t->next;
        t->next = k;
        k->data = d;
        k->next = p;
        return;
    }
}

int main(void) {
    FILE *input = stdin;
    FILE *output = stdout;
    Node *list = NULL;
    int a;
    while(fscanf(input, "%d", &a) != EOF) {
        push(list, a);
    }
    while(list != NULL) {
        fprintf(output, "%d ", list->data);
        list = list->next;
    }
    fclose(input);
    fclose(output);
    return 0;
}
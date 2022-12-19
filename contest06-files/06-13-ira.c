#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum CONSTANTS { size = 105 };

typedef int Data;

typedef struct Node Node;
struct Node {
    char data[size];
    char char_param[size];
    int int_param;
//    int if_int;
    Node * next;
};


Node * merge(Node *a, Node *b, int f) {

    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }
    if (f == 1) {
        if (a->int_param < b->int_param) {
            a->next = merge(a->next, b, f);
            return a;
        } else {
            b->next = merge(a, b->next, f);
            return b;
        }
    } else {
        if (strcmp(a->char_param, b->char_param)<0) {
            a->next = merge(a->next, b, f);
            return a;
        } else {
            b->next = merge(a, b->next, f);
            return b;
        }
    }
}


Node * mergesort(Node *plist, int f, int lena) {
    if (lena == 1) {
        return plist;
    }
    Node *t = plist;
    for (int i=0; i<lena/2 - 1; i++) {
        t = t->next;
    }
    Node *k = t->next;
    t->next = NULL;
    plist = mergesort(plist, f, lena/2);
    k = mergesort(k, f, lena-lena/2);
    return merge(plist, k, f);
}

int main(void) {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    Node *list = NULL;
    int N;
    int lena=0;
    fscanf(input, "%d", &N);
    char s[size];
    fgets(s, size, input);
    int f=0;
    while (fgets(s, size, input) != NULL) {
        Node *t = malloc(sizeof(Node));
        t->next = list;
//        size_t m = strspn((const char *) s, " ");
//        *s = *s + m;

//        t->data = s;
        memcpy(t->data, s, size * sizeof(char));
        //printf("%s   ", (char *) s);
        char *token =  strtok( s, ";");
        for (int i=0; i<N; i++) {
            //puts(token);
            token = strtok(NULL, ";");
        }
        //printf("%s", token);
        if (token[0] == '"') {
            memcpy(t->char_param, token, size * sizeof(char));
            t->int_param = 0;
            f = 0;
        } else {
//            memcpy(t->char_param, NULL, size * sizeof(char));
            t->int_param = atoi(token);
            f = 1;
        }

        ++lena;
        list = t;
    }
    list = mergesort(list, f, lena);
    while(list != NULL) {
        for(int i=0; i<size && list->data[i] != EOF && list->data[i] != '\n' && list->data[i] != '\0'; i++) {
            if ((list->data)[i] != ' ') {
                fprintf(output, "%c", (list->data)[i]);
            }
        }
        fprintf(output, "\n");
        list = list->next;
    }
    fclose(input);
    fclose(output);
    return 0;
}




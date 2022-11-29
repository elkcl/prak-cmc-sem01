#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int key;
    struct list *prev, *next;
} list;

int main(void)
{
    int n, m;
    FILE *fileIn = stdin;
    fscanf(fileIn, "%d %d", &n, &m);
    list **list2 = malloc(n * sizeof(list *));
    for (int i = 0; i < n; i++){
        list2[i] = malloc(sizeof(list));
        list2[i] -> key = i + 1;
    }
    list2[0] -> prev = NULL;
    list2[n - 1] -> next = NULL;
    if (n > 1){
        list2[0] -> next = list2[1];
        list2[n - 1] -> prev = list2[n - 2];
        for (int i = 1; i < n - 1; i++){
            list2[i] -> prev = list2[i - 1];
            list2[i] -> next = list2[i + 1];
        }
    }
    list *firstElem = list2[0];
    list *listStart = malloc(sizeof(list));
    list *listStop = malloc(sizeof(list));
    for (int i = 0; i < m; i++){
        int start, stop;
        fscanf(fileIn, "%d %d", &start, &stop);
        list *curList = firstElem;
        while (curList){ // For the last number
            if (curList -> key == start){
                listStart = curList;
            }
            if (curList -> key == stop){
                listStop = curList;
                break;
            }
            curList = curList -> next;
        }
        if (listStart -> prev == NULL)
            continue;
        listStart -> prev -> next = listStop -> next;
        if (listStop -> next)
            listStop -> next -> prev = listStart -> prev;

        listStart -> prev = NULL;
        listStop -> next = firstElem;
        firstElem -> prev = listStop;
        firstElem = listStart;
    }
    //fclose(fileIn);
    FILE *fileOut = stdout;
    while (firstElem){ //For the last number
        fprintf(fileOut, "%d ", firstElem -> key);
        firstElem = firstElem -> next;
    }
    fclose(fileOut);
    for (int i = 0; i < n; i++){
        free(list2[i]);
    }
    free(list2);
    free(listStart);
    free(listStop);
    return 0;
}

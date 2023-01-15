#include <stdio.h>

struct list {
    int key;
    struct list *next;
    struct list *sublist_head;
};

typedef struct {
    int len, sum;
} res;

res exam_rec(struct list *garland) {
    if (garland == NULL)
        return (res){-1, -1};
    int curr_len = 0;
    int curr_sum = 0;
    int ans_len = 0;
    int ans_sum = 0;
    while (garland != NULL) {
        ++curr_len;
        curr_sum += garland->key;
        res rec = exam_rec(garland->sublist_head);
        if (rec.len == ans_len) {
            ans_sum = (rec.sum > ans_sum) ? rec.sum : ans_sum;
        } else if (rec.len > ans_len) {
            ans_len = rec.len;
            ans_sum = rec.sum;
        }
        garland = garland->next;
    }
    if (curr_len == ans_len) {
        ans_sum = (curr_sum > ans_sum) ? curr_sum : ans_sum;
    } else if (curr_len > ans_len) {
        ans_len = curr_len;
        ans_sum = curr_sum;
    }
    return (res){ans_len, ans_sum};
}

int examine(struct list *garland) {
    return exam_rec(garland).sum;
}

int main(void) {
    struct list arr[] = {
        {1, arr + 1, NULL},
        {2, arr + 2, NULL},
        {3, arr + 3, arr + 5},
        {4, arr + 4, NULL},
        {5, NULL, NULL},

        {1, arr + 6, NULL},
        {2, arr + 7, arr + 8},
        {3, NULL, NULL},

        {1, arr + 9, arr + 12},
        {2, arr + 10, NULL},
        {3, arr + 11, arr + 15},
        {4, NULL, NULL},

        {1, NULL, arr + 13},

        {1, arr + 14, NULL},
        {2, NULL, NULL},

        {10, arr + 16, NULL},
        {1, arr + 17, NULL},
        {2, arr + 18, NULL},
        {3, arr + 19, NULL},
        {4, NULL, NULL}
    };
    res r = exam_rec(arr);
    printf("%d %d", r.len, r.sum); //5 20
}
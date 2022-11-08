#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} point;

// Реализация циклической очереди основана на реализации с лекций А. А. Белеванцева
typedef struct {
    int size, spos, rpos;
    point *mem;
} queue;

queue qinit(int n) {
    queue q = {n, 0, 0, NULL};
    q.mem = malloc(sizeof(point[n]));
    return q;
}

void qfree(queue *q) {
    free(q->mem);
    q->mem = NULL;
}

bool qpush(queue *q, point x) {
    if (q->mem == NULL)
        return false;
    if (q->spos + 1 == q->rpos)
        return false;
    if (q->rpos == 0 && q->spos + 1 == q->size)
        return false;

    q->mem[q->spos++] = x;
    if (q->spos == q->size)
        q->spos = 0;
    return true;
}

point qpop(queue *q) {
    if (q->mem == NULL)
        return (point){-1, -1};
    if (q->rpos == q->spos)
        return (point){-1, -1};
    if (q->rpos == q->size - 1) {
        q->rpos = 0;
        return q->mem[q->size - 1];
    }
    return q->mem[q->rpos++];
}

bool qempty(queue *q) {
    return q->rpos == q->spos;
}

int main(void) {
    int n;
    point p0, p1;
    scanf("%d", &n);
    scanf("%d", &p0.x);
    scanf("%d", &p0.y);
    scanf("%d", &p1.x);
    scanf("%d", &p1.y);
    --p0.x, --p0.y, --p1.x, --p1.y;

    int (*dist)[n] = malloc(sizeof(int[n][n]));
    memset(dist, -1, sizeof(int[n][n]));
    dist[p0.x][p0.y] = 0;
    queue q = qinit(n * n);
    qpush(&q, p0);
    while (!qempty(&q)) {
        point p = qpop(&q);
        for (int i = -2; i < 3; ++i) {
            if (i == 0)
                continue;
            if (p.x + i < 0 || p.x + i >= n)
                continue;
            for (int j = -2; j < 3; ++j) {
                if (j == 0)
                    continue;
                if (abs(i) + abs(j) != 3)
                    continue;
                if (p.y + j < 0 || p.y + j >= n)
                    continue;
                if (dist[p.x + i][p.y + j] != -1)
                    continue;
                dist[p.x + i][p.y + j] = dist[p.x][p.y] + 1;
                qpush(&q, (point){p.x + i, p.y + j});
            }
        }
    }
    printf("%d", dist[p1.x][p1.y]);

    qfree(&q);
    free(dist);
}
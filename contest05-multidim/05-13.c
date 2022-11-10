#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define MAX(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

typedef long long ll;

typedef struct {
    int x, y;
    ll dist;
} vertex;

// Код по мотивам реализации двоичной кучи на викиконспектах (https://neerc.ifmo.ru/wiki/index.php?title=%D0%94%D0%B2%D0%BE%D0%B8%D1%87%D0%BD%D0%B0%D1%8F_%D0%BA%D1%83%D1%87%D0%B0)
typedef struct {
   int size, capacity;
   vertex *mem;
} heap;

heap heap_init(int sz) {
    heap h;
    h.size = 0;
    h.capacity = sz;
    h.mem = calloc(sz, sizeof(*h.mem));
    return h;
}

void heap_free(heap *h) {
    free(h->mem);
    h->mem = NULL;
}

void heap_sift_down(heap *h, int i) {
    while (2 * i + 1 < h->size) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l >= h->size)
            return;
        int min = l;
        if (r < h->size && h->mem[r].dist < h->mem[l].dist)
            min = r;
        if (h->mem[min].dist >= h->mem[i].dist)
            break;
        SWAP(h->mem[min], h->mem[i]);
        i = min;
    }
}

void heap_sift_up(heap *h, int i) {
    while (h->mem[i].dist < h->mem[(i - 1) / 2].dist) {
        SWAP(h->mem[i], h->mem[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heap_push(heap *h, vertex x) {
    ++h->size;
    h->mem[h->size - 1] = x;
    heap_sift_up(h, h->size - 1);
}

vertex heap_pop(heap *h) {
    vertex ans = h->mem[0];
    --h->size;
    h->mem[0] = h->mem[h->size];
    heap_sift_down(h, 0);
    return ans;
}

const ll INF = (ll) 4e18;

int main(void) {
    int n, m, x0, y0, x1, y1;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &x0);
    scanf("%d", &y0);
    scanf("%d", &x1);
    scanf("%d", &y1);

    int (*a)[m] = calloc(n, sizeof(*a));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    ll (*dist)[m] = calloc(n, sizeof(*dist));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j] = INF;
    dist[x0][y0] = 0;
    heap h = heap_init(n * (m - 1) + m * (n - 1) + 1);
    heap_push(&h, (vertex){x0, y0, 0});
    while (h.size != 0) {
        vertex curr = heap_pop(&h);
        if (curr.dist > dist[curr.x][curr.y])
            continue;
        for (int dx = -1; dx < 2; ++dx) {
            if (curr.x + dx < 0)
                continue;
            if (curr.x + dx >= n)
                continue;
            for (int dy = -1; dy < 2; ++dy) {
                if (abs(dx) + abs(dy) != 1)
                    continue;
                if (curr.y + dy < 0)
                    continue;
                if (curr.y + dy >= m)
                    continue;
                if (dist[curr.x + dx][curr.y + dy] > dist[curr.x][curr.y] + llabs(a[curr.x + dx][curr.y + dy] - a[curr.x][curr.y])) {
                    dist[curr.x + dx][curr.y + dy] = dist[curr.x][curr.y] + llabs(a[curr.x + dx][curr.y + dy] - a[curr.x][curr.y]);
                    heap_push(&h, (vertex){curr.x + dx, curr.y + dy, dist[curr.x + dx][curr.y + dy]});
                }
            }
        }
    }
    printf("%Ld\n", dist[x1][y1]);

    heap_free(&h);
    free(dist);
    free(a);
}
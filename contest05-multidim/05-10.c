#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define SWAP(_x, _y) do { typeof(_x) _TEMP = _x; _x = _y; _y = _TEMP; } while (0)

typedef struct {
    int size, capacity;
    bool sign;
    int *mem;
} number;

number num_init(void) {
    number v;
    v.sign = true;
    v.size = 0;
    v.capacity = 2;
    v.mem = calloc(v.capacity, sizeof(*v.mem));
    return v;
}

void num_free(number *v) {
    free(v->mem);
}

void num_resize(number *v, int n) {
    if (n <= v->capacity) {
        if (n > v->size) {
            memset(v->mem + v->size, 0, (n - v->size) * sizeof(*v->mem));
        }
        v->size = n;
        return;
    }
    v->mem = realloc(v->mem, n * sizeof(*v->mem));
    memset(v->mem + v->size, 0, (n - v->size) * sizeof(*v->mem));
    v->capacity = v->size = n;
}

void num_append(number *v, int c) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->mem = realloc(v->mem, v->capacity * sizeof(*v->mem));
    }
    v->mem[v->size] = c;
    ++v->size;
}

void num_flip(number *v) {
    for (int i = 0, j = v->size - 1; i < j; ++i, --j)
        SWAP(v->mem[i], v->mem[j]);
}

void num_carry(number *v) {
    int carry = 0;
    for (int i = 0; i < v->size; ++i) {
        v->mem[i] += carry;
        carry = 0;
        while (v->mem[i] < 0) {
            --carry;
            v->mem[i] += 10;
        }
        while (v->mem[i] > 9) {
            ++carry;
            v->mem[i] -= 10;
        }
    }
    if (carry == 0)
        return;
    if (carry == -1) {
        v->sign = false;
        int i = 0;
        while (v->mem[i] == 0)
            ++i;
        v->mem[i] = 10 - v->mem[i];
        ++i;
        for (; i < v->size; ++i)
            v->mem[i] = 9 - v->mem[i];
        return;
    }
    while (carry > 0) {
        num_append(v, carry);
        carry = 0;
        while (v->mem[v->size - 1] > 9) {
            ++carry;
            v->mem[v->size - 1] -= 10;
        }
    }
}

number num_add_pos(const number *a, const number *b) {
    number c = num_init();
    if (a->size >= b->size) {
        num_resize(&c, a->size);
        for (int i = 0; i < b->size; ++i)
            c.mem[i] = a->mem[i] + b->mem[i];
        for (int i = b->size; i < a->size; ++i)
            c.mem[i] = a->mem[i];
    } else {
        num_resize(&c, b->size);
        for (int i = 0; i < a->size; ++i)
            c.mem[i] = a->mem[i] + b->mem[i];
        for (int i = a->size; i < b->size; ++i)
            c.mem[i] = b->mem[i];
    }
    return c;
}

number num_sub_pos(const number *a, const number *b) {
    number c = num_init();
    if (a->size >= b->size) {
        num_resize(&c, a->size);
        for (int i = 0; i < b->size; ++i)
            c.mem[i] = a->mem[i] - b->mem[i];
        for (int i = b->size; i < a->size; ++i)
            c.mem[i] = a->mem[i];
    } else {
        num_resize(&c, b->size);
        for (int i = 0; i < a->size; ++i)
            c.mem[i] = a->mem[i] - b->mem[i];
        for (int i = a->size; i < b->size; ++i)
            c.mem[i] = -b->mem[i];
    }
    return c;
}

number num_mul_pos(const number *a, const number *b) {
    number c = num_init();
    num_resize(&c, a->size + b->size);
    for (int i = 0; i < a->size; ++i)
        for (int j = 0; j < b->size; ++j)
            c.mem[i + j] += a->mem[i] * b->mem[j];
    return c;
}

number num_add(number *a, number *b) {
    number c;
    if (a->sign) {
        if (b->sign) {
            c = num_add_pos(a, b);
        } else {
            c = num_sub_pos(a, b);
        }
    } else {
        if (b->sign) {
            c = num_sub_pos(b, a);
        } else {
            c = num_add_pos(a, b);
            c.sign = false;
        }
    }
    num_carry(&c);
    return c;
}

number num_sub(number *a, number *b) {
    b->sign = !b->sign;
    number c = num_add(a, b);
    b->sign = !b->sign;
    return c;
}

number num_mul(number *a, number *b) {
    number c = num_mul_pos(a, b);
    num_carry(&c);
    c.sign = a->sign == b->sign;
    return c;
}

int main(void) {
    number a = num_init();
    number b = num_init();
    int ch = getchar();
    while (isdigit(ch)) {
        num_append(&a, ch - '0');
        ch = getchar();
    }
    int op = ch;
    ch = getchar();
    while (isdigit(ch)) {
        num_append(&b, ch - '0');
        ch = getchar();
    }
    num_flip(&a);
    num_flip(&b);
    number c;
    if (op == '+') {
        c = num_add(&a, &b);
    } else if (op == '-') {
        c = num_sub(&a, &b);
    } else {
        c = num_mul(&a, &b);
    }
    int i = c.size - 1;
    while (i >= 0 && c.mem[i] == 0)
        --i;
    if (i < 0) {
        puts("0\n");
    } else {
        if (!c.sign)
            putchar('-');
        for (; i >= 0; --i)
            putchar(c.mem[i] + '0');
        putchar('\n');
    }

    num_free(&a);
    num_free(&b);
    num_free(&c);
}
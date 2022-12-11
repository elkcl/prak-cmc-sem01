//
// Created by elk on 11.12.22.
//
#include <stdio.h>
#include <stdlib.h>


void func(long long k, long long a[k][k], long long b[k][k], long long c[k][k], long long N, long long p, long long t) {
    //printf("%lld\n", t);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            long long Y = 0;
            for (int z=0; z<k; z++) {
                Y += a[i][z]*b[z][j] % p;
            }
            c[i][j] = Y % p;
        }
    }
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++) {
            b[i][j] = c[i][j];
        }
    }
    if (t+k == N) return;
    else func(k, a, b, c, N, p, t+1);
}


int main(void) {
    long long k, N, p;
    scanf("%lld %lld %lld", &k, &N, &p);
    long long (*f) = malloc(k * sizeof(long long));
    long long (*a)[k] = malloc(k * sizeof(*a));
    long long (*R)[k] = malloc(k * sizeof(*R));
    long long (*c)[k] = malloc(k * sizeof(*c));
    for (int i=0; i<k; i++){
        scanf("%lld", &f[i]);
    }
    for (int i=0; i<k; i++){
        scanf("%lld", &a[0][i]);
        a[0][i] = a[0][i] % p;
        R[0][i] = a[0][i];
    }
    for (int i = 1; i<k; i++) {
        for (int j=0; j<k; j++) {
            if (i==j) a[i][j] = 1, R[i][j] = 1;
            else a[i][j] = 0, R[i][j] = 0;
        }
    }
    func(k, a, R, c, N, p, 1);
    long long s = 0;
    for (int i=0; i<k; i++) {
        s += f[i]*R[0][k-i-1] % p;
    }
    printf("%lld", s % p);
    free(a);
    free(R);
    free(c);
    free(f);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
    FILE *input = fopen ("matrix.in", "rb");
    FILE *output = fopen ("trace.out", "wb");

    unsigned int n = 0;
    unsigned char t1, t2;

    fread (&t1, sizeof(unsigned char), 1, input);
    fread (&t2, sizeof(unsigned char), 1, input);
    n = (t1 << 8) + t2;

    unsigned long long int s = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){

            unsigned char t;
            fread (&t, sizeof(unsigned char), 1, input);

            unsigned int a = t;

            for (int b = 0; b < 3; b++){
                a = a << 8;
                fread (&t, sizeof(unsigned char), 1, input);
                a += t;
            }

            if (i == j){
                s += a;
            }
        }
    }

    unsigned char ans;
    for (int i = 0; i < 8; i++){
        ans = s >> (8 * (7 - i));
        fwrite (&ans, sizeof(unsigned char), 1, output);
        ans = ans >> 8;
    }

    fclose (input);
    fclose (output);
}
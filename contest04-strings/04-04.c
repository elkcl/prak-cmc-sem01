#include <stdio.h>
#include <string.h>

#define MAXN 260

int main(void) {
    char s[MAXN];
    fgets(s, MAXN, stdin);
    size_t n = strlen(s) - 1;
    s[n] = '\0';
    for (int i = 0; i < n; ++i) {
        int even = 0, odd = 0;
        for (int j = 0; j < i; j += 2)
            if (s[j] == 'A')
                ++even;
        for (int j = 1; j < i; j += 2)
            if (s[j] == 'A')
                ++odd;
        if (i % 2 == 0) {
            for (int j = i + 1; j < n; j += 2)
                if (s[j] == 'A')
                    ++even;
            for (int j = i + 2; j < n; j += 2)
                if (s[j] == 'A')
                    ++odd;
        } else {
            for (int j = i + 1; j < n; j += 2)
                if (s[j] == 'A')
                    ++odd;
            for (int j = i + 2; j < n; j += 2)
                if (s[j] == 'A')
                    ++even;
        }
        if (even == odd)
            printf("%d ", i + 1);
    }
}
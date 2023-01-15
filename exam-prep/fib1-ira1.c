#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* fibocci(char* s) {
    int len = strlen(s);
    int k1 = 1, k2 = 1, flag = 0, all = 0, m_len = 0;
    char *m = NULL;
    while (all < len) {
        if (flag) {
            if (k1 > len - all) {
                k1 = len - all;
            }
            char *k = realloc(m, (m_len+k1)*sizeof(char));
            m = k;
            for (int i = 0; (i < k1) && (all + i < len); i++) {
                m[m_len+i] = s[all+i];
            }
            m_len += k1;
        }
        all += k1;
        int k3 = k1+k2; k1 = k2; k2 = k3;
        flag = 1 - flag;
    }
    //free(s);
    printf("%d %d ", m_len, all);
    fwrite(m, sizeof(char), m_len, stdout);
    return m;
}


int main(void) {
    char s[1000] = "";
    scanf("%s", s);
    // befgmnop
    free(fibocci(s));
    return 0;
}
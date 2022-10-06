#include <stdio.h>

const int TON = 1e6;

int main(void) {
    int n;
    scanf("%d", &n);
    int curr = 1;
    int k = 0;
    while (curr <= n) {
        curr *= 3;
        ++k;
    }
    curr /= 3;
    int arr[100];
    for (int i = k - 1; i >= 0; --i) {
        if (2 * curr <= n) {
            arr[i] = 2;
            n -= 2 * curr;
        } else if (curr <= n) {
            arr[i] = 1;
            n -= curr;
        } else {
            arr[i] = 0;
        }
        curr /= 3;
    }
    int carry = 0;
    for (int i = 0; i < k; ++i) {
        arr[i] += 1 + carry;
        if (arr[i] >= 3) {
            arr[i] %= 3;
            carry = 1;
        } else {
            carry = 0;
        }
    }
    int cnt = 0;
    curr = 1;
    int left = 0;
    int right = 0;
    for (int i = 0; i < k; ++i) {
        if (arr[i] == 0) {
            left += curr;
            ++cnt;
        } else if (arr[i] == 2) {
            right += curr;
            ++cnt;
        }
        curr *= 3;
    }
    if (carry) {
        ++cnt;
        right += curr;
    }
    if (left > TON || right > TON)
        puts("-1");
    else
        printf("%d", cnt);
}
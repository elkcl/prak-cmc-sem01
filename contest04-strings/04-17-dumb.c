#include <stdio.h>
#include <string.h>

int main(void)
{
    static char str[(int)4e6 + 1], ans[(int)2e6 + 1]; /// string for input and string for answer
    static int arr[(int)4e6 + 1]; /// number of consecutive zeros starting from this index
    scanf("%s", str);
    int len = strlen(str); /// length of a string
    for(int i = 0; i < len; ++i) /// str = scanned string + scanned string, arr = {0, 0, 0,..., 0}
    {                            /// str looks like that because we have the case when after zeros in string's end there are zeros in it's beginning("00100" -> "00001")
        ans[i] = str[i + len] = str[i];
        arr[i] = arr[i + len] = 0;
    }
    ans[len] = arr[2 * len] = str[2 * len] = 0; /// adding zeros to arr and to str and to ans('\0' for correct output)
    for(int i = 2 * len - 1; i >= 0; --i) /// going from right to left and calculating arr values for each index of an str
    {
        if(str[i] == '0') arr[i] = arr[i + 1] + 1;
        else arr[i] = 0;
    }
    int val = 0; /// maximum value of arr
    for(int i = 0; i < 2 * len; ++i)
    {
        if(arr[i] > val) val = arr[i];
    }
    for(int i = 0; i < len; ++i) /// lexicographically the smallest possible string has the most zeros in it's beginning
    {                            /// if we have more than one such string we should compare all of them and choose our answer
        if(arr[i] == val && strcmp(ans, str + i) > 0)
        {
            strncpy(ans, str + i, len);
        }
    }
    printf("%s", ans); /// printing an answer
    return 0;
}
#include <stdio.h>

int htoi(char *hex, int len) {
    int power, int_val, i;
    power = 0;
    int_val = 0;
    i = len;
    while (i >= 0) {
        int_val = ((pow(16, power) * hex_val(hex[i])) + int_val)
    }
}

int main() {
    int ans1,ans2,ans3,len1,len2,len3;
    char *convert1 = "f";
    char *convert2 = "13";
    char *convert3 = "a156";
    ans1 = htoi(convert1, len1);
    printf("%d\n", ans1);
    ans2 = htoi(convert2, len2);
    printf("%d\n", ans2);
    ans3 = htoi(convert3, len3);
    printf("%d\n", ans3);
}
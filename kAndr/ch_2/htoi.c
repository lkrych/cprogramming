#include <stdio.h>
#include <string.h>

void print_string(char *string, int length) {
    int i;
    for (i = 0; i <= length; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}

//raise x ^ n
int mypow(int x, int n) {
    int i = 0;
    int total = 0;
    while (i <= n){
        total = total * x;
        i++;
    }
    return total;
}

int hex_val(char c) {
    switch(c) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'a':
            return 10;
        case 'b':
            return 11;
        case 'c':
            return 12;
        case 'd':
            return 13;
        case 'e':
            return 14;
        case 'f':
            return 15;
        default :
         printf("Invalid input\n" );
         return -1;
    }
}

//convert hexadecimal string to integer
int htoi(char *hex, int len) {
    int power, int_val, i;
    power = 0;
    int_val = 0;
    i = len;
    while (i >= 0) {
        int_val = ((mypow(16, power) * hex_val(hex[i])) + int_val);
        i--;
        power++;
    }
    return int_val;
}

int main() {
    int ans1,ans2,ans3;
    char *convert1 = "f";
    char *convert2 = "13";
    char *convert3 = "a156";
    int len1 = sizeof(convert1)/sizeof(convert1[0]);
    int len2 = sizeof(convert2)/sizeof(convert2[0]);
    int len3 = sizeof(convert3)/sizeof(convert3[0]);

    ans1 = htoi(convert1, len1);
    printf("hex: ");
    print_string(convert1, len1);
    printf("int: %d\n", ans1);

    ans2 = htoi(convert2, len2);
    printf("hex: ");
    print_string(convert2, len2);
    printf("int %d\n", ans2);

    ans3 = htoi(convert3, len3);
    printf("hex: ");
    print_string(convert3, len3);
    printf("int %d\n", ans3);
}
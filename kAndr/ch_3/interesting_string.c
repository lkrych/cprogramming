//  Given a string s consisting of digits 0-9 
//  and lowercase English letters a-z.

//  A string is interesting if you can split it 
//  into several substrings, such that each substring 
//  starts with a number and this number represents the number of characters after it. 
//  Return true if string s is intersting, otherwise false.
//  https://leetcode.com/discuss/interview-question/350312/google-onsite-interesting-string
#include <stdio.h>
#include <stdlib.h> // for atoi
#include <string.h>
#include <stdbool.h> // for true and false

void print_string(char *s, int l) {
    int i;
    for (i = 0; i < l; i++) {
        printf("%c", s[i]);
    }
}

int interesting_string(char *s, int l) {
    int i = 0;
    int char_to_i = 0;
    while (i < l) {
        // check if string is digit
         if(s[i] >= '0' && s[i] <= '9') {
             char_to_i = s[i] - '0'; //once you have a digit, this is the easiest way to convert
             i += char_to_i + 1;
             if (i > l) {
                printf("The string: ");
                print_string(s, l);
                printf(" is not an interesting string ❌ \n");
                return 0;
             }
         } else {
            printf("The string: ");
            print_string(s, l);
            printf(" is not an interesting string ❌ \n");
            return 0;
         }
    }
    printf("The string: ");
    print_string(s, l);
    printf(" is an interesting string ✅ \n");
    return 1;

}

int main() {
    char s1[] = "4g12y6hunter";
    char s2[] = "124gray6hunter";
    char s3[] = "31ba2a";
    int len_1, len_2, len_3;
    len_1 = strlen(s1);
    len_2 = strlen(s2);
    len_3 = strlen(s3);

    interesting_string(s2, len_2);
    interesting_string(s1, len_1);
    interesting_string(s3, len_3);
}
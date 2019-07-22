#include <stdio.h>
#include <string.h>

void print_string(char *string, int length) {
    int i;
    printf("string output: ");
    for (i = 0; i <= length; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}

void reverse(char *s, char *reverse, int length) {
    int i; // start at last character
    int j = 0; // reversed string index

    for (i = length; i >= 0; i--) {
        reverse[j] = s[i];
        j++;
    }
}


int main() {
    int length;
    char *s = "hello world";

    length = strlen(s) - 1;
    char r[length];

    reverse(s, r, length);
    print_string(r, length);
}
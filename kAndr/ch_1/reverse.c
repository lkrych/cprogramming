#include <stdio.h>
#include <string.h>

void print_string(char *reversed, int length) {
    int i;
    printf("string output: ");
    for (i = 0; i < length; i++) {
        printf("%s", reversed[i]);
    }
    printf("\n");
}

char * reverse(char *s, int length) {
    char reversed[length]; //will hold reversed string
    int i; // start at last character
    int j = 0; // reversed string index

    for (i = length; i >= 0; i--) {
        reversed[j] = s[i];
        j++;
    }
    return reversed;
}


int main() {
    int length;
    char *s = "hello world";
    length = strlen(s);
    char *reversed = reverse(s, length);
    print_string(reversed, length);
}
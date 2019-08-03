#include <stdio.h>
#include <string.h>

//swap values at two pointers
void swap(char* x, char* y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Function to print permutations of a string
// this function takes three parameters
// word is the string to permute
// l is the starting index of the string
// end is the ending index of the string

void permute(char *word, int l, int end) {
    int i;
    if (l == end) {
        printf("%s\n", word);
    }
    else  {
        for (i = l; i <= end; i++) {
            swap((word + 1), (word + i));
            permute(word, l+1, end);
            swap((word+1), (word + i)); //backtrack
        }
    }
}

int main() {
    char str[] = "ABCD";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}
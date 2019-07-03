#include <stdio.h>
// write a program to print a histogram of the frequencies of different characters in its input

//helper functions
void read_input(int alpha[]){
    int c, arrIdx;

    // grab characters from input
    while ((c = getchar()) != '!' + 0) {
        // see if character is alpha
        if (c >= 65 && c <= 90) {
            // uppercase
            arrIdx = c%65;
        } else if ( c >= 97 && c <= 122) {
            // lowercase
            arrIdx = c%97;
        } else {
            continue;
        }
        alpha[arrIdx] = alpha[arrIdx] + 1;
    }
}

void create_and_print_histogram(int counts[]){
    char * alpha = "abcdefghijklmnopqrstuvwxyz";
    int i, j, count;
    char c;
    puts("<><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
    puts("<><> histogram of different characters used in input <><>");
    puts("<><><><><><><><><><><><><><><><><><><><><><><><><><><><>");
    for( i = 0; i < 26; i++) {
        c = alpha[i];
        count = counts[i];
        if (count == 0) {
            continue;
        }
        printf("%c:\t", c);
        // one * is a count
        for (j = 0; j < count; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    //store counts of alphabet
    int i;
    int ALPHA[26];
    puts("type ! to create the histogram");
    for (i = 0; i < 26; ++i){
        ALPHA[i] = 0;
    }

    read_input(ALPHA);
    create_and_print_histogram(ALPHA);
}

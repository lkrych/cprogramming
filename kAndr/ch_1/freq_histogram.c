#include <stdio.h>
#include <regex.h>
// write a program to print a histogram of the frequencies of different characters in its input
//  w/ help from https://stackoverflow.com/questions/1085083/regular-expressions-in-c-examples

//helper functions
void read_input(int alpha[]){
    regex_t regex;
    int input, i, reti;
    char c;
    char * regexString = "[:alpha]";
    
    /* Compile regular expression */
    reti = regcomp(&regex, regexString, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    // grab characters from input
    while ((input = getchar()) != EOF) {
        //see if character is alpha
        c = input + '0';
        reti = regexec(&regex, c, 0, NULL, 0);
        if (!reti) {
            puts("Match");
        }
        else if (reti == REG_NOMATCH) {
            puts("No match");
        }
        // printf("%d\n", c);
        // printf("%d\n", c%97);
    }
}

void create_and_print_histogram(int counts[]){
    printf("Nice histogram :) \n");
}

int main(){
    //store counts of alphabet
    int ALPHA[26];
    read_input(ALPHA);
    create_and_print_histogram(ALPHA);
}

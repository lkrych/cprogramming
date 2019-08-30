#include <stdio.h>
#include <string.h>

int main(){
    char string[10];
    int A = -73;
    unsigned int B = 31337;

    strcpy(string, "sample");

    //example of printing with different format string
    printf("[A] Dec: %d, Hex: %x, Unsigned: %u\n", A, A, A);
    printf("[B] Dec: %d, Hex: %x, Unsigned: %u\n", B, B, B);
    printf("[field width on B] 3: '%3u', 10: '%10u', '%08u'\n", B, B, B);
    printf("[string] %s Address %08x\n", string, string);

    //example of unary address operator (dereference)
    printf("Variable A is at address: %08x\n", &A);
}

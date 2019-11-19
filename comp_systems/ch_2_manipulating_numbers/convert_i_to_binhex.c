#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char charVal(int num)
{
    if (num >= 0 && num <= 9) {
        return (char)(num + '0');
    } else {
        return (char)(num - 10) + 'A';
    }
}

char strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++) 
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}


char* itox(int x, int base, char res[]) 
{
    int index = 0;

    while (x > 0) {
        int next_digit = x % base;
        res[index++] = charVal(next_digit);
        x /= base;
    }
    res[index] = '\0'; //how c closes strings
    strev(res);
    return res;
}

// gcc -o convert_i_to_binhex convert_i_to_binhex.c
int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        printf("usage: convert_i_to_binhex 7\n");
    }
    char binres[100];
    char hexres[100];

    int x = atoi(argv[1]);
    itox(x, 2, binres);
    itox(x, 16, hexres);

    printf("dec: %d, bin: %s, hex: 0x%s \n", x, binres, hexres);
}
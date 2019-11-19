#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getVal(char c) {
    int intVal = 0;
    switch (c) {
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
        default:
            intVal = atoi(&c);
            return intVal;
    }
}

int powerup(base, exp) {
    int counter = 1;
    while (exp > 0) {
        counter *= base;
        exp -= 1;
    }
    return counter;
} 

int hextoi(char *hex) {
    int i;
    int counter = 0;
    int power = 0;
    for (i = strlen(hex) - 1; i >= 0; i--) {
        counter += getVal(hex[i]) * powerup(16, power);
        power++;
    }
    return counter;
}

char charVal(int num)
{
    if (num >= 0 && num <= 9) {
        return (char)(num + '0');
    } else {
        return (char)(num - 10) + 'A';
    }
}

void strev(char *str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++) 
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}


char* itox(int x, int base, char res[])  {
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

// gcc -o convert_hex_to_bini convert_hex_to_bini.c
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: convert_hex_to_bini F7\n");
    }
    char binres[100];
    int x = hextoi(argv[1]);
    itox(x, 2, binres);

    printf("dec: %d, bin: %s, hex: 0x%s \n", x, binres, argv[1]);
}
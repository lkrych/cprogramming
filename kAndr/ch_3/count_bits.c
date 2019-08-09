#include <stdio.h>

int count_bits(int x) {
    int num_bits = 0;
    while( x > 0) {
        num_bits += x & 1;
        x >>= 1;
    }
    return num_bits;
}

int main() {
    int x1, x2, x3;
    x1 = count_bits(5);
    x2 = count_bits(4);
    x3 = count_bits(255);

    printf("count_bits of 5 is %d \n", x1);
    printf("count_bits of 4 is %d \n", x2);
    printf("count_bits of 255 is %d \n", x3);
}
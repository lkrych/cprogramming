#include <stdio.h>

//problems taken from practice problem 2.12 in Computer Systems (3rd)
//write C expressions, in terms of variable x for the following rules
// * The least significant byte of x, with all other bits set to 0
// * All but the least significant byte of x complemented, with the least significant byte unchanged.
// * The least significant byte set to all 1s and the other bytes left unchanged

int main() {
    int x = 0x87654321;
    printf("least significant byte of x: 0x%x\n", x & 0xFF);
    printf("all but least significant byte of x complemented, with least significant byte unchanged: 0x%x\n", (~x) ^ 0xFF);
    printf("least significant byte set to all 1s: 0x%x,\n ", x | 0xFF);
}
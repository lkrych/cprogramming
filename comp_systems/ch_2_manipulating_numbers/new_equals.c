#include <stdio.h>

//Using only bit-level and logical operations, write a C expression that is equivalent to x == y. 
//In other words, it will return 1 when x and y are equal, and 0 otherwise.

int new_equals(int x, int y) {
    return !(x ^ y);
}

int main() {
    printf("1 == 0: %d\n",new_equals(1,0));  
    printf("5 == 5: %d\n",new_equals(5,5));  
    printf("1 == 1: %d\n",new_equals(1,1));  
    printf("0 == 0: %d\n",new_equals(0,0));  
}
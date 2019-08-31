#include <stdio.h>

int main() {
    int i;

    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};

    char *char_pointer;
    int *int_pointer;

    // remember "arrays" are really just pointers to the beginning of an array
    char_pointer = char_array;
    int_pointer = int_array;

    // two separate for loops iterate through the arrays using pointer arithmetic to adjust the pointer
    // even though the same value of 1 is added to the pointers
    // the compiler increments the pointer's addresses by different amounts

    for (i = 0; i < 5; i++) {
        printf("[integer pointer] points to %p, which contains the integer %d\n", int_pointer, *int_pointer);
        int_pointer = int_pointer + 1;
    }

    for (i = 0; i < 5; i++) {
        printf("[char pointer] points to %p, which contains the char %c\n", char_pointer, *char_pointer);
        char_pointer = char_pointer + 1;
    }
}
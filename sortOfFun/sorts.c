#include <stdio.h>
#include <stdbool.h> //include true and false

// HELPER FUNCTIONS 
void print_array(int *arr, int length) {
    // bc arrays are passed as pointers
    // you need the length of the array to print the entire array
    int i = 0;
    for (i = 0; i < length; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

int * swap( int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return arr;
}

// SORTING ALGORITHMS

// bubble sort
int * bubble_sort( int *arr, int length){
    bool sorted = false;
    int i = 0;
    while (!sorted) {
        sorted = true;
        for (i = 0; i < length; ++i) {
            if (i + 1 < length) { //only check for swap up to the second to last element
                if (arr[i] > arr[i+1]) {
                    swap(arr, i, i+1);
                    sorted = false;
                }
            }
        }
    }
    return arr;
}
// insertion sort

// merge sort

int main() {
    int sortThisArray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arrSize = sizeof(sortThisArray)/sizeof(int);
    int * sorted = bubble_sort(sortThisArray, arrSize);
    printf("bubble_sort: ");
    print_array(sorted, arrSize);
}
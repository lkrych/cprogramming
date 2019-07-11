#include <stdio.h>
#include <stdbool.h> //include true and false

void print_array(int *arr) {
    int i = 0;
    for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
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

// bubble sort
int * bubble_sort( int *arr){
    bool sorted = false;
    int arrSize = 0;
    int i = 0;
    arrSize = sizeof(arr)/sizeof(int);
    printf("The size of the array is %d \n", arrSize);
    printf("The array at begginning of bubble_sort is: ");
    print_array(arr);
    while (!sorted) {
        sorted = true;
        for (i = 0; i < arrSize; ++i) {
            if (i + 1 < arrSize) { //only check for swap up to the second to last element
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
    printf("before passing to bubble_sort: ");
    print_array(sortThisArray);
    int arrSize = sizeof(sortThisArray)/sizeof(int);
    printf("The size of the array is %d \n", arrSize);
    int * sorted = bubble_sort(sortThisArray);
    printf("bubble_sort: ");
    print_array(sorted);
}
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

int * slice_array( int *arr, int length_arr,  int start, int finish) {
    //slice array is inclusive
    int sliced[finish-start];
    int slice_i = 0;
    int i;
    for (i = start; i <= finish; i++ ) {
        sliced[slice_i] = arr[i];
        slice_i += 1;
    }
    return sliced;
}

// SORTING ALGORITHMS

// bubble sort
int * bubble_sort( int *arr, int length) {
    bool sorted = false;
    int i = 0;
    while (!sorted) {
        sorted = true;
        for (i = 0; i < length; i++) {
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

int * merge(int *arr1, int arr1_len, int *arr2, int arr2_len) {
    int merged[arr1_len + arr2_len];
    int i,j = 0;
    
}

int * merge_sort( int *arr, int length) {
    if (length < 2) {
        return arr;
    }
    int mid = length / 2;
    int *leftArr = slice_array(arr, length, 0, mid);
    int *rightArr = slice_array(arr, length, mid + 1, length - 1);

    int sizeLeft = sizeof(leftArr) / sizeof(int);
    int sizeRight = sizeof(rightArr) / sizeof(int);
    // make recursive call
    int *sortedLeft = merge_sort(leftArr, sizeLeft);
    int *sortedRight = merge_sort(rightArr, sizeRight);

    int *merged = merge(*sortedLeft, sizeLeft, *sortedRight, sizeRight);

    return merged;
}

int main() {
    int sortThisArray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arrSize = sizeof(sortThisArray)/sizeof(int);
    int * sorted = bubble_sort(sortThisArray, arrSize);
    printf("bubble_sort: ");
    print_array(sorted, arrSize);
}
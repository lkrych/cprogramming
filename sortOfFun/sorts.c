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
    printf("sliced array: ");
    print_array(sliced, finish - start);
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
    int i,j,k = 0;

    while (i < arr1_len && j < arr2_len) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of arr1 if there are any
    while (i < arr1_len) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // copy the remaining elements of arr2 if there are any
    while (j < arr2_len) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    return merged;
    
}

int * merge_sort( int *arr, int length) {
    if (length < 2) {
        return arr;
    }
    printf("The array given to merge sort is: ");
    print_array(arr, length);
    int mid = length / 2;
    int *leftArr = slice_array(arr, length, 0, mid);
    int *rightArr = slice_array(arr, length, mid, length);

    int sizeLeft = mid - 0;
    int sizeRight = length - mid;

    printf("The size of the left arr is %d \n", sizeLeft);
    printf("The size of the right arr is %d \n", sizeRight);


    // make recursive call
    int *sortedLeft = merge_sort(leftArr, sizeLeft);
    int *sortedRight = merge_sort(rightArr, sizeRight);

    int *merged = merge(sortedLeft, sizeLeft, sortedRight, sizeRight);

    return merged;
}

int main() {
    int sortThisArray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arrSize = sizeof(sortThisArray)/sizeof(int);
    int * sorted = bubble_sort(sortThisArray, arrSize);
    printf("bubble_sort: ");
    print_array(sorted, arrSize);

    int sortThisArrayWithMergeSort[] = {15, 13, 5, 2, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arrSizeMerge = sizeof(sortThisArrayWithMergeSort)/sizeof(int);
    int * sortedWithMergeSort = merge_sort(sortThisArrayWithMergeSort, arrSizeMerge);

    printf("merge_sort: ");
    print_array(sortedWithMergeSort, arrSizeMerge);
}
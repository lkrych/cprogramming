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

void merge(int arr[], int leftIndex, int midIndex, int rightIndex) {
    int i,j,k;
    int arr1Len = midIndex - leftIndex +1;
    int arr2Len = rightIndex - midIndex;

    int arr1[arr1Len], arr2[arr2Len];
    //copy data to the temp arrays: arr1 and arr2
    for (i = 0; i < arr1Len; i++) {
        arr1[i] = arr[leftIndex + i];
    }
    for (j = 0; j < arr2Len; j++) {
        arr2[j] = arr[midIndex + 1 + j];
    }

    i = 0;
    j = 0;
    k = leftIndex;

    //start merging the arrays
    while (i < arr1Len && j < arr2Len) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of arr1 if there are any
    while (i < arr1Len) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    // copy the remaining elements of arr2 if there are any
    while (j < arr2Len) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
// modifies the incoming array
// https://www.geeksforgeeks.org/c-program-for-merge-sort/
void merge_sort(int arr[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) { //do some sorting
        int midIndex = (leftIndex + (rightIndex)) / 2;

        merge_sort(arr, leftIndex, midIndex);
        merge_sort(arr, midIndex + 1, rightIndex);
        merge(arr, leftIndex, midIndex, rightIndex);
    }
}

int main() {
    int sortThisArray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arrSize = sizeof(sortThisArray)/sizeof(int);
    int * sorted = bubble_sort(sortThisArray, arrSize);
    printf("bubble_sort: ");
    print_array(sorted, arrSize);

    int sortThisArrayWithMergeSort[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arrSizeMerge = sizeof(sortThisArrayWithMergeSort)/sizeof(int);
    printf("The length of the array we are passing into merge sort is: %d \n", arrSizeMerge - 1);
    merge_sort(sortThisArrayWithMergeSort, 0, arrSizeMerge - 1);

    printf("merge_sort: ");
    print_array(sortThisArrayWithMergeSort, arrSizeMerge);
}
#include <stdio.h>

int binary_search(int *arr, int arr_len, int to_find) {
    int low, high, mid;
    low = 0;
    high = arr_len - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (to_find < arr[mid]) {
            high = mid - 1;
        } else if (to_find > arr[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1; //no match
}

int main() {
    int ans1, ans2, ans3, ans4;
    int arr1[] = {0,1,2,3,4,5,6};
    int arr2[] = {0,1,2,3,4,5,6};
    int arr3[] = {0,1,2,3,4,5,6};
    int arr4[] = {0,1,2,3,4,5,6};

    size_t size1 = sizeof(arr1)/sizeof(arr1[0]);
    size_t size2 = sizeof(arr2)/sizeof(arr2[0]);
    size_t size3 = sizeof(arr3)/sizeof(arr3[0]);
    size_t size4 = sizeof(arr4)/sizeof(arr4[0]);

    ans1 = binary_search(arr1, size1, 1);
    ans2 = binary_search(arr1, size2, -1);
    ans3 = binary_search(arr1, size3, 18);
    ans4 = binary_search(arr1, size4,  3);

    printf("The index of 1 in arr1 is %d\n", ans1);
    printf("The index of -1 in arr1 is %d\n", ans2);
    printf("The index of 18 in arr1 is %d\n", ans3);
    printf("The index of 3 in arr1 is %d\n", ans4);
}
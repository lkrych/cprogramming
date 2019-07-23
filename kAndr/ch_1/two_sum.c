#include <stdio.h>

void two_sum(int *nums, int nums_length, int target) {
    int i, j;
    for (i = 0; i < nums_length -1; i++) {
        for (j = 1; j < nums_length; j++) {
            if (nums[i] + nums[j] == target) {
                printf("The indices for two sum are [%d, %d]\n", i, j);
                return;
            }
        }
    }
    printf("No two indices added up to %d\n", target);
}

int main() {
    int nums[] = {1,2,3,4,5,6};
    int length = sizeof(nums) / sizeof(nums[0]);
    two_sum(nums, length, 9);
    return 0;
}
#include <stdio.h>
// Generate a sequence using the following algorithm:
// start with an integer n
// if n is even, divide by 2
// if n is odd, multiply by 3 and add 1
// repeat this until n = 1

// a cycle-length of n is the number of numbers generated including the final number
int threeNPlusOne(int i) {
    int count = 0;
    int current = i;
    while (current != 1) {
        count++;
        if (current % 2 == 0) {
            current = current / 2;
        } else {
            current = (current * 3) + 1;
        }
    }
    return count + 1;
}

//cycle through all of the inputs and see which has the largest cycle number
int threeNRange(int i, int j) {
    int maxCount = 0;
    int currentInt = i;
    int currentCount = 0;

    while(currentInt <= j) {
        currentCount = threeNPlusOne(currentInt);
        if (currentCount > maxCount) {
            maxCount = currentCount;
        }
        currentInt++;
    }

    return maxCount;
}

int main() {
    int ans;

    ans = threeNRange(1, 10);
    if (ans != 20) {
        printf("The algorithm is incorrect");
    }

    ans = threeNRange(100, 200);
    if (ans != 125) {
        printf("The algorithm is incorrect");
    }

    ans = threeNRange(201, 210);
    if (ans != 89) {
        printf("The algorithm is incorrect");
    }

    ans = threeNRange(900, 1000);
    if (ans != 174) {
        printf("The algorithm is incorrect");
    }
    printf("Program has finished evaluating :) \n");
}
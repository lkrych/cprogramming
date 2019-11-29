#include <stdio.h>

// determine whether arguments can be added without overflow
int uadd_ok(unsigned x, unsigned y) {
    unsigned sum = x+y;
    // if it overflows the sum will be greater than x
    return sum >= x;
}

int tadd_ok(int x, int y) {
    //overflow can happen in two directions with twos complement
    int sum = x + y;
    if (x > 0 && y > 0 && sum < 0) {
        return false;
    } else if (x < 0 && y < 0 && sum >= 0)
    {
        return false;
    }
    return true;
}


int main(){

}
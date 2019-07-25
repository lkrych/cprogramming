#include <stdio.h>

// time for fibonacci of 41:  0m1.074s
int fibonacci(int n) {
    if (n <= 1) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
// time for fibonacci_dynamic of 41: 0m0.005s
// time for fibonacci_dynamic of 1000: 0m0.003s
long double fibonacci_dynamic(n) {
    long double current, new_current, prev_val; 
    int i;
    current = 1;
    prev_val = 0;
    i = 0;
    while (i < n) {
        new_current = prev_val + current;
        prev_val = current;
        current = new_current;
        i++;
    }
    return current;
}

int main() {
    int n = 1000;
    long double ans;
    ans = fibonacci_dynamic(n);
    printf("Fibonacci of %d is %Lf \n", n, ans);
}
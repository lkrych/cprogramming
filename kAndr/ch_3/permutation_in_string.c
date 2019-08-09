#include <stdio.h>
#include <string.h>

ALPHA_LEN = 26;

void zero(int *arr, int arr_len) {
    int i;
    for (i = 0; i < arr_len; i++) {
        arr[i] = 0;
    }
}

int get_char_index(char c) {
    return c - '0';
}

void get_window(char *s, int i, int j, int *arr) {
    int window_len = j - i;

}

void find_permutation_in_string(char *s1, int l1, char *s2, int l2) {
    int i;
    int window1[ALPHA_LEN];
    int window2[ALPHA_LEN];
    get_window(s1, 0, l1, window1);
    for (i = 0; i < l2 - l1; i++) {
        //reset window2
        zero(window2, ALPHA_LEN);
        
        //iterate through all windows and compare windows
        get_window(s2, i, i + l1, window2);
    }
}

int main() {

}
#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include <ctype.h> //tolower

int ALPHA_LEN = 26;

void zero(int *arr, int arr_len) {
    int i;
    for (i = 0; i < arr_len; i++) {
        arr[i] = 0;
    }
}

int get_char_index(char c) {
    int lower; // will only work for lowercase
    lower = tolower(c); 
    return lower - 97;
}

void get_window(char *s, int i, int j, int *arr) {
    int k,c,c_index;
    int window_len = j - i;
    for (k = i; k < j; k++) {
        c = s[k]; // grab char
        c_index = get_char_index(c);
        arr[c_index]++;
    }
}

int compare_windows(int *w1, int *w2) {
    int j;
    for (j = 0; j < ALPHA_LEN; j++) {
        if (w1[j] != w2[j]) {
            return false;
        }
    }
    return true;
}

void find_permutation_in_string(char *s1, int l1, char *s2, int l2) {
    int i, comp;
    int window1[ALPHA_LEN];
    int window2[ALPHA_LEN];
    get_window(s1, 0, l1, window1);
    for (i = 0; i < l2 - l1; i++) {
        //reset window2
        zero(window2, ALPHA_LEN);
        
        //iterate through all windows and compare windows
        get_window(s2, i, i + l1, window2);

        comp = compare_windows(window1, window2);

        if (comp) {
            printf("A permutation exists \n");
        }
    }
}

int main() {
    char c1[] = "ab";
    char s1[] = "eidbaooo";
    char s2[] = "eidboaoo";
    int c1l, s1l, s2l;
    c1l = strlen(c1);
    s1l = strlen(s1);
    s2l = strlen(s2);

    find_permutation_in_string(c1, c1l, s2, s2l);
}
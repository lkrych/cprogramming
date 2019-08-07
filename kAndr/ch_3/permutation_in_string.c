#include <stdio.h>
#include <string.h>

void find_permutation_in_string(char *s1, int l1, char *s2, int l2) {
    int i;
    int window1[26];
    int window2[26];
    get_window(s1, 0, l1, window1);
    for (i = 0; i < l2 - l1; i++) {
        //reset window2
        zero(window2);
        
        //iterate through all windows and compare windows
        get_window(s2, i, i + l1, window2);
    }
}

int main() {

}
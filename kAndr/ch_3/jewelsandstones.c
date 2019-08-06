// You're given strings J representing the types of stones that are jewels,
//  and S representing the stones you have.  
// Each character in S is a type of stone you have.  
// You want to know how many of the stones you have are also jewels.

// The letters in J are guaranteed distinct, and all characters in J and S are letters. 
// Letters are case sensitive, so "a" is considered a different type of stone from "A".

#include <stdio.h>
#include <string.h>



// #include "uthash.h"

// struct my_dict {
//     char id; // use this as the key
//     char truthy[10];
//     UT_hash_handle hh; // make this structure hashable
// };

// struct my_dict *jewels = NULL;

// void add_jewel(struct my_dict *s) {
//     HASH_ADD_INT(jewels, id, s);
// }

// struct my_dict *find_user(char id) {
//     struct my_dict *s;

//     HASH_FIND_INT( jewels, &id, s);
//     return s;
// }

void jewels_and_stones_naive(char *j, int jl, char *s, int sl) {
    int jewel_count = 0;
    int i, k;
    for (i= 0; i < jl; i++) {
        for (k = 0; k < sl; k++) {
            if (j[i] == s[k]) {
                jewel_count++;
            }
        }
    }
    printf("The jewel count is %d\n", jewel_count);
}


int main() {
    char j1[] = "aA";
    char s1[] = "aAAbbbb";
    char j2[] = "z";
    char s2[] = "ZZ";
    int j1l,s1l,j2l,s2l;
    j1l = strlen(j1);
    j2l = strlen(j2);
    s1l = strlen(s1);
    s2l = strlen(s2);

    jewels_and_stones_naive(j1, j1l, s1, s1l);
    jewels_and_stones_naive(j2, j2l, s2, s2l);
}


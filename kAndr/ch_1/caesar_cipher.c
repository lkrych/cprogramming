#include <stdio.h>

//use alpha const for mapping index to char
const char ALPHA[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void print_string(char *string, int length) {
    int i;
    for (i = 0; i <= length; i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}

void caesar_cipher(char *s, int s_len, int shift) {
  char shifted[s_len];
  int i; // index
  int ascii; // store the ascii val of each char
  for (i = 0; i < s_len; i++) {
    ascii = (int) s[i];
    if (ascii < 97 || ascii > 122) {
      //not a lowercase character
      shifted[i] = s[i];
    } else {
      ascii = ascii + shift - 97;
      if (ascii > 25) {
        ascii = (ascii % 26);
      }
      shifted[i] = ALPHA[ascii];
    }
  }
  printf("The shifted val is: ");
  print_string(shifted, s_len);
}

int main() {
  char *s = "hello world";
  int shift = 4;
  int s_len = sizeof(s)/ sizeof(s[0]);
  printf("The string is length %d \n", s_len);
  caesar_cipher(s, s_len, shift);
}
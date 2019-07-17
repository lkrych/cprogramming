#include <stdio.h>
#include <stdlib.h> // For exit()
#include <string.h> // to split each line 

#define MAX_WORD_LENGTH 30 //arbitrary

void longest_word(char file_name[]) {
  FILE *fptr;
  char *longest_word = (char*) malloc (MAX_WORD_LENGTH);
  char line[255];
  int largest_len = 0;

  //init longest_word
  longest_word = "";

  // open file
  fptr = fopen(file_name, "r");
  if (fptr == NULL) {
    printf("There was an error opening the file. \n");
    exit(0);
  }

  //read from file
  while(fgets(line, 255, fptr) != NULL) {
    //split line by word
      char *temp = strtok(line, " ");
      while (temp != NULL) {
        if (strlen(temp) > largest_len) {
          strcpy(longest_word, temp);
          largest_len = strlen(longest_word);
        }
        temp = strtok(NULL, " ");
      }
  }

  printf("The largest word in the file is: %s\n", longest_word);

  //close file pointer
  fclose(fptr);

}

int main() {
  longest_word("hamlet.txt");
}
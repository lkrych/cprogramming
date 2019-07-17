#include <stdio.h>
#include <stdlib.h> // For exit()
#include <string.h> // to split each line 

#define MAX_WORD_LENGTH 60 //arbitrary

// strings in c are character arrays
// line 16: allocate space for largest possible word
// line 17: allocate space for each line read from file
// line 28: use fgets to read from file pointer into line
// line 30: use strtok to split each line by spaces
// line 34: copy current word into longest word

void longest_word(char file_name[]) {
  FILE *fptr;
  char *longest_word = (char*) malloc (MAX_WORD_LENGTH);
  char line[255];
  int largest_len = 0;

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
        printf("%s, length: %lu\n", temp, strlen(temp));
        if (strlen(temp) > largest_len) {
          strcpy(longest_word, temp);
          largest_len = strlen(longest_word);
        }
        temp = strtok(NULL, " ");
      }
  }

  printf("The largest word in the file is: %s\n", longest_word);

  //close file pointer and free malloc'd space
  free(longest_word);
  fclose(fptr);

}

int main() {
  longest_word("hamlet.txt");
}
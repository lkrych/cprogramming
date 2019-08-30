#include <stdio.h>
#include <string.h>

int main() {
    char message[20];
    int count, i;

    strcpy(message, "Hello, world!");
    
    // use scanf to set the count variable
    printf("Repeat how many times? ");
    scanf("%d", &count);

    for (i=0; i < count; i++) {
        printf("%3d - %s\n", i, message);
    }
}
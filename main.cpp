#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INPUT_BUFFER_SIZE 40 // The maximum length of a GH username is 39 characters, plus EOS character
int main() {
    char input[INPUT_BUFFER_SIZE];
    while (true) { // Main super loop for the program
        printf("github-user-activity> ");
        fgets(input, sizeof(input), stdin);
        size_t len = strlen(input);
        if ((len!=0) && (input[len - 1] == '\n')) //Trims the new line characters off of the input (prevents double new line)
            input[len - 1] = '\0';
    }
    return 0;
}
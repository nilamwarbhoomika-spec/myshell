// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("myshell> ");          // print prompt
        fflush(stdout);

        if (!fgets(input, MAX_INPUT, stdin)) break;  // read input

        input[strcspn(input, "\n")] = 0;  // remove newline

        if (strcmp(input, "exit") == 0) break;  // exit on "exit"

        printf("You typed: %s\n", input);  // just echo for now
    }
    return 0;
}
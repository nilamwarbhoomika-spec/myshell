// parser.c
#include <string.h>
#include <stdlib.h>
#define MAX_ARGS 64

char **parse_input(char *input) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    char *token;
    int i = 0;

    token = strtok(input, " \t");   // split by space/tab
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " \t");
    }
    args[i] = NULL;   // NULL terminate the array
    return args;
}
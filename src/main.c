
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

char **parse_input(char *input);
void execute(char **args);

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (!fgets(input, MAX_INPUT, stdin)) break;

        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) continue;

        if (strcmp(input, "exit") == 0) break;

        char **args = parse_input(input);
        execute(args);
        free(args);
    }
    return 0;
}
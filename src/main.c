#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

char **parse_input(char *input);
void execute(char **args);
int handle_builtin(char **args);

int main() {
    char input[MAX_INPUT];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (!fgets(input, MAX_INPUT, stdin)) break;

        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) continue;

        char **args = parse_input(input);

        // Check builtins first
        if (handle_builtin(args) == 0) {
            execute(args);  // not a builtin, run normally
        }

        free(args);
    }
    return 0;
}
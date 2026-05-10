#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

char **parse_input(char *input);
void execute(char **args);
int handle_builtin(char **args);
void execute_pipe(char **cmd1, char **cmd2);
void add_to_history(char *cmd);

int has_pipe(char *input, char *cmd1, char *cmd2) {
    char *pipe_pos = strchr(input, '|');
    if (pipe_pos == NULL) return 0;

    int len1 = pipe_pos - input;
    strncpy(cmd1, input, len1);
    cmd1[len1] = '\0';
    strcpy(cmd2, pipe_pos + 1);

    while (*cmd2 == ' ') cmd2++;

    return 1;
}

int main() {
    char input[MAX_INPUT];
    char cmd1[MAX_INPUT];
    char cmd2[MAX_INPUT];

    while (1) {
        printf("myshell> ");
        fflush(stdout);

        if (!fgets(input, MAX_INPUT, stdin)) break;

        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) continue;

        // save every command to history
        add_to_history(input);

        if (has_pipe(input, cmd1, cmd2)) {
            char **args1 = parse_input(cmd1);
            char **args2 = parse_input(cmd2);
            execute_pipe(args1, args2);
            free(args1);
            free(args2);

        } else {
            char **args = parse_input(input);
            if (handle_builtin(args) == 0) {
                execute(args);
            }
            free(args);
        }
    }
    return 0;
}
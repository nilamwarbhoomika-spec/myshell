#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define HISTORY_SIZE 10

char *history[HISTORY_SIZE];
int history_count = 0;

void add_to_history(char *cmd) {
    if (history_count < HISTORY_SIZE) {
        history[history_count++] = strdup(cmd);
    } else {
        // remove oldest, shift everything up
        free(history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i-1] = history[i];
        }
        history[HISTORY_SIZE-1] = strdup(cmd);
    }
}

void print_history() {
    if (history_count == 0) {
        printf("No commands in history\n");
        return;
    }
    for (int i = 0; i < history_count; i++) {
        printf("%d  %s\n", i+1, history[i]);
    }
}

int handle_builtin(char **args) {
    if (args[0] == NULL) return 1;

    if (strcmp(args[0], "exit") == 0) {
        exit(0);

    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL)
            fprintf(stderr, "cd: missing argument\n");
        else if (chdir(args[1]) != 0)
            perror("cd failed");
        return 1;

    } else if (strcmp(args[0], "help") == 0) {
        printf("MyShell — Built-in commands: cd, exit, help, history\n");
        return 1;

    } else if (strcmp(args[0], "history") == 0) {
        print_history();
        return 1;
    }

    return 0;   // not a builtin
}
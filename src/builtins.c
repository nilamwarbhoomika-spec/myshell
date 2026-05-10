#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
        printf("MyShell — Built-in commands: cd, exit, help\n");
        return 1;
    }

    return 0;   // not a builtin
}
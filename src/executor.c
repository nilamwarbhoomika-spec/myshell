#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

void handle_redirection(char **args) {
    for (int i = 0; args[i] != NULL; i++) {

        if (strcmp(args[i], ">") == 0) {
            int fd = open(args[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) {
                perror("open failed");
                exit(1);
            }
            dup2(fd, STDOUT_FILENO);   // redirect stdout to file
            close(fd);
            args[i] = NULL;            // remove > from args

        } else if (strcmp(args[i], "<") == 0) {
            int fd = open(args[i+1], O_RDONLY);
            if (fd < 0) {
                perror("open failed");
                exit(1);
            }
            dup2(fd, STDIN_FILENO);    // redirect stdin from file
            close(fd);
            args[i] = NULL;
        }
    }
}

void execute(char **args) {
    pid_t pid = fork();

    if (pid == 0) {
        // Inside child process
        handle_redirection(args);    // handle > and < before running

        if (execvp(args[0], args) == -1) {
            perror("myshell: command not found");
        }
        exit(1);

    } else if (pid > 0) {
        waitpid(pid, NULL, 0);

    } else {
        perror("fork failed");
    }
}
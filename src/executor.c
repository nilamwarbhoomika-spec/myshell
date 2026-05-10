#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void execute(char **args) {
    pid_t pid = fork();        // create child process

    if (pid == 0) {
        // Inside child process
        if (execvp(args[0], args) == -1) {
            perror("myshell: command not found");
        }
        exit(1);

    } else if (pid > 0) {
        // Inside parent process — wait for child to finish
        waitpid(pid, NULL, 0);

    } else {
        perror("fork failed");
    }
}
# MyShell 🐚
A Unix shell built from scratch in C, implementing core OS concepts
like process management, piping, and I/O redirection.

## Features
- Command execution (ls, pwd, echo, etc.)
- Built-in commands: cd, exit, help, history
- I/O Redirection (> and <)
- Piping between commands (|)
- Command history (last 10 commands)

## Tech Stack
C, Linux System Calls (fork, exec, pipe, dup2, waitpid)

## How to Run
git clone https://github.com/nilamwarbhoomika-spec/myshell
cd myshell
make
./myshell

## Demo
[https://github.com/user-attachments/assets/aff93e19-3725-447a-ae45-5ed42c219355]

## OS Concepts Demonstrated
- Process creation with fork/exec
- File descriptor manipulation
- Inter-process communication via pipes
- Signal handling
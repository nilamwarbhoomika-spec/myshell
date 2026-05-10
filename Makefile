CC = gcc
CFLAGS = -Wall -Iinclude

myshell: src/main.c src/parser.c src/executor.c src/builtins.c src/pipes.c
	$(CC) $(CFLAGS) -o myshell $^

clean:
	rm -f myshell
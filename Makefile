CC=gcc
CFLAGS=-Iinclude

# Assuming all your .c files are in the src/ directory
SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)

tic-tac-toe: $(OBJ)
    $(CC) -o $@ $^

%.o: %.c
    $(CC) $(CFLAGS) -c -o $@ $<

clean:
    rm -f src/*.o tic-tac-toe

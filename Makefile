CC=gcc              # Compiler
CFLAGS=-Iinclude    # Compiler flags

# Automatically find all .c files in the src/ directory
SRC=$(wildcard src/*.c)
# Convert .c filenames to .o
OBJ=$(SRC:.c=.o)

# The default target: build the tic-tac-toe executable
tic-tac-toe: $(OBJ)
	$(CC) -o $@ $^

# Rule for building object files from C source files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up the build: remove object files and the executable
clean:
	rm -f src/*.o tic-tac-toe

CC=gcc              # Compiler
CFLAGS=-Iinclude    # Compiler flags

# Automatically find all .c files in the src/ directory
SRC=$(wildcard src/*.c)
# Convert .c filenames to .o
OBJ=$(SRC:.c=.o)

# Test source files
TEST_SRC=$(wildcard tests/*.c)
# Convert .c filenames to .o for tests
TEST_OBJ=$(TEST_SRC:.c=.o)
# Test executable name
TEST_EXEC=test-tic-tac-toe

# The default target: build the tic-tac-toe executable
tic-tac-toe: $(OBJ)
	$(CC) -o $@ $^

# Rule for building object files from C source files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Target for running tests
test: $(TEST_OBJ)
	$(CC) -o $(TEST_EXEC) $(TEST_OBJ)
	./$(TEST_EXEC)


# Clean up the build: remove object files and the executable
clean:
	rm -f src/*.o tests/*.o $(TEST_EXEC) tic-tac-toe

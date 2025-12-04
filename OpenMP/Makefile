# Simple Makefile for OpenMP Matrix Multiplication

# Compiler and flags
CC = gcc
CFLAGS = -Wall -O3 -fopenmp
TARGET = openmp_matrixmul
SOURCE = openmp_matrixmul.c

# Default target
all: $(TARGET)

# Build the program
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $<

# Debug build
debug: $(SOURCE)
	$(CC) -Wall -g -fopenmp -o $(TARGET)_debug $<

# Clean build files
clean:
	rm -f $(TARGET) $(TARGET)_debug

# Rebuild
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Test with different thread counts
test: $(TARGET)
	@echo "Testing OpenMP matrix multiplication..."
	@for threads in 1 2 4 8; do \
		echo "Testing with $$threads threads (matrix size 500):"; \
		printf "500\n$$threads\n" | ./$(TARGET) | grep "Execution time" || true; \
		echo ""; \
	done

# Help
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  debug   - Build debug version"
	@echo "  clean   - Remove build files"
	@echo "  rebuild - Clean and build"
	@echo "  run     - Build and run the program"
	@echo "  test    - Test with different thread counts"
	@echo "  help    - Show this help"

.PHONY: all debug clean rebuild run test help

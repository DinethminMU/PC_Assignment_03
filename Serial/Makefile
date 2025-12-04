# Simple Makefile for Sequential Matrix Multiplication

# Compiler and flags
CC = gcc
CFLAGS = -Wall -O3
TARGET = matrixmul
SOURCE = matrixmul.c

# Default target
all: $(TARGET)

# Build the program
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $@ $<

# Debug build
debug: $(SOURCE)
	$(CC) -Wall -g -o $(TARGET)_debug $<

# Clean build files
clean:
	rm -f $(TARGET) $(TARGET)_debug

# Rebuild
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Test with different matrix sizes
test: $(TARGET)
	@echo "Testing sequential matrix multiplication..."
	@for size in 100 200 500 1000; do \
		echo "Testing with matrix size: $$size"; \
		printf "$$size\n" | ./$(TARGET) | grep -E "(time|Time)" || true; \
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
	@echo "  test    - Test with different matrix sizes"
	@echo "  help    - Show this help"

.PHONY: all debug clean rebuild run test help

# Simple Makefile for MPI Matrix Multiplication

# Compiler and flags
MPICC = mpicc
CFLAGS = -Wall -O3
TARGET = mpi_matrixmul
SOURCE = mpi_matrixmul.c

# Default target
all: $(TARGET)

# Build the program
$(TARGET): $(SOURCE)
	$(MPICC) $(CFLAGS) -o $@ $<

# Debug build
debug: $(SOURCE)
	$(MPICC) -Wall -g -o $(TARGET)_debug $<

# Clean build files
clean:
	rm -f $(TARGET) $(TARGET)_debug

# Rebuild
rebuild: clean all

# Run the program with 4 processes
run: $(TARGET)
	mpirun -np 4 ./$(TARGET)

# Test with different process counts
test: $(TARGET)
	@echo "Testing MPI matrix multiplication..."
	@for np in 1 2 4; do \
		echo "Running with $$np processes:"; \
		mpirun -np $$np ./$(TARGET); \
		echo ""; \
	done

# Help
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  debug   - Build debug version"
	@echo "  clean   - Remove build files"
	@echo "  rebuild - Clean and build"
	@echo "  run     - Build and run with 4 processes"
	@echo "  test    - Run with different process counts"
	@echo "  help    - Show this help"

.PHONY: all debug clean rebuild run test help

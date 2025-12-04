# Sequential Matrix Multiplication

Basic sequential matrix multiplication implementation.

## Description

This program multiplies two square matrices using a simple triple-nested loop approach. Serves as a baseline for performance comparison with parallel implementations.

## Requirements

- C compiler (GCC, Clang)

## Compilation

### Using Makefile (recommended):
```bash
make              # Build the program
make run          # Build and run the program
make test         # Test with different matrix sizes
make clean        # Clean build files
```

### Manual compilation:
```bash
gcc -O3 -o matrixmul matrixmul.c
```

## Usage

Run the program and enter matrix size when prompted:

```bash
./matrixmul
Enter matrix size: 1000
```

## Algorithm

Standard matrix multiplication:
```
C[i][j] = Σ(k=0 to N-1) A[i][k] * B[k][j]
```

Simple triple-nested loop implementation with no parallelization.

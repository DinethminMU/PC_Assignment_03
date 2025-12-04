# OpenMP Matrix Multiplication

Parallel matrix multiplication using OpenMP for shared-memory systems.

## Description

This program multiplies two square matrices using OpenMP to parallelize the computation across multiple CPU cores. Uses `collapse(2)` directive for efficient loop parallelization.

## Requirements

- GCC with OpenMP support
- Multi-core processor

## Compilation

### Using Makefile (recommended):
```bash
make              # Build the program
make run          # Build and run the program
make test         # Test with different thread counts
make clean        # Clean build files
```

### Manual compilation:
```bash
gcc -fopenmp -O3 -o openmp_matrixmul openmp_matrixmul.c
```

## Usage

Run the program and enter matrix size and number of threads:

```bash
./openmp_matrixmul
Enter matrix size N: 1000
Enter number of threads: 4
```

## Algorithm

Standard matrix multiplication with parallel execution:
```
C[i][j] = Σ(k=0 to N-1) A[i][k] * B[k][j]
```

Uses `#pragma omp parallel for collapse(2)` to parallelize nested loops.

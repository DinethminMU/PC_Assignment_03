# MPI Matrix Multiplication

Distributed matrix multiplication using MPI for multi-node systems.

## Description

This program multiplies two square matrices using MPI for distributed computing. Uses row-wise decomposition where matrix A is distributed among processes while matrix B is broadcast to all.

## Requirements

- MPI implementation (OpenMPI, MPICH)
- C compiler with MPI support

## Compilation

### Using Makefile (recommended):
```bash
make              # Build the program
make run          # Build and run with 4 processes  
make test         # Test with 1, 2, and 4 processes
make clean        # Clean build files
```

### Manual compilation:
```bash
mpicc -O3 -o mpi_matrixmul mpi_matrixmul.c
```

## Usage

Run with multiple processes:

```bash
# Single node with 4 processes
mpirun -np 4 ./mpi_matrixmul

# Multi-node execution
mpirun -np 8 --hostfile hosts ./mpi_matrixmul
```

## Algorithm

Standard matrix multiplication with distributed computation:
```
C[i][j] = Σ(k=0 to N-1) A[i][k] * B[k][j]
```

- Matrix A: Distributed row-wise among processes
- Matrix B: Broadcast to all processes
- Matrix C: Result gathered at process 0

Fixed matrix size: 100×100 (defined by `#define N 100`)

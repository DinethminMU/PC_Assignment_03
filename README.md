# PC Assignment 03 - Matrix Multiplication Implementations

Four different implementations of matrix multiplication demonstrating various parallel programming approaches.

## Implementations

### 1. Serial (`Serial/`)
- Sequential single-threaded implementation
- Baseline for performance comparison
- Compile: `gcc -O3 -o matrixmul matrixmul.c`

### 2. OpenMP (`OpenMP/`)
- Shared-memory parallelization using OpenMP
- Parallelizes loops across CPU cores
- Compile: `gcc -fopenmp -O3 -o openmp_matrixmul openmp_matrixmul.c`

### 3. MPI (`MPI/`)
- Distributed-memory parallelization using MPI
- Row-wise matrix decomposition
- Compile: `mpicc -O3 -o mpi_matrixmul mpi_matrixmul.c`
- Run: `mpirun -np 4 ./mpi_matrixmul`

### 4. CUDA (`CUDA/`)
- GPU-accelerated implementation using NVIDIA CUDA
- 8×8 thread blocks for parallel computation
- Compile: `nvcc -arch=sm_75 -O3 -o cuda_matrixmul cuda_matrixmul.cu`

## Requirements

- **Serial/OpenMP/MPI**: C compiler, MPI library
- **CUDA**: NVIDIA GPU, CUDA Toolkit

Each directory contains detailed README files with specific compilation and usage instructions.

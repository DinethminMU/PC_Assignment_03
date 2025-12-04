# CUDA Matrix Multiplication

GPU-accelerated matrix multiplication using NVIDIA CUDA.

## Description

This program multiplies two square matrices using CUDA for parallel computation on GPU. Each thread computes one element of the result matrix using an 8×8 thread block configuration.

## Requirements

- NVIDIA GPU with CUDA support
- CUDA Toolkit
- For Google Colab: T4 GPU runtime

## Compilation

### Google Colab (T4 GPU):
```bash
nvcc -arch=sm_75 -O3 -o cuda_matrixmul cuda_matrixmul.cu
```

### Local System:
```bash
nvcc -O3 -o cuda_matrixmul cuda_matrixmul.cu
```

## Usage

Run the program and enter the matrix size when prompted:

```bash
./cuda_matrixmul
Enter matrices size: 1024
```

## Algorithm

Each thread computes one element of the result matrix:
```
C[y][x] = Σ(k=0 to N-1) A[y][k] * B[k][x]
```

Thread organization: 8×8 thread blocks, grid size calculated as `(N+7)/8`.

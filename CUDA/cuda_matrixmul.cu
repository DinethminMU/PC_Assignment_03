%%writefile cuda_matrixmul.cu
#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>


//Kernel function
__global__ void matrixMul(float *A, float *B, float *C, int N){
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;

    if(x < N && y < N){
        float sum = 0.0;
        for(int k = 0; k < N; k++){
            sum += A[y*N + k] * B[k*N + x];
        }
        C[y*N + x] = sum;
    }



}

int main(){
    int N;
    printf("Enter matrices size N: ");
    scanf("%d",&N);

    long size = N * N * sizeof(float);

    //Allocate host memory
    float *h_A = (float*)malloc(size);
    float *h_B = (float*)malloc(size);
    float *h_C = (float*)malloc(size);

    //Initialize matrices
    for(int i = 0; i < N*N; i++){
        h_A[i] = (float)(rand() % 100);
        h_B[i] = (float)(rand() % 100);
    }

    //Allocate device memory
    float *d_A, *d_B, *d_C;
    cudaMalloc((void**)&d_A,size);
    cudaMalloc((void**)&d_B,size);
    cudaMalloc((void**)&d_C,size);

    //Copy from host to device
    cudaMemcpy(d_A,h_A,size,cudaMemcpyHostToDevice);
    cudaMemcpy(d_B,h_B,size,cudaMemcpyHostToDevice);

    dim3 threadsPerBlock(8,8);
    dim3 blocksPerGrid((N + threadsPerBlock.x - 1)/threadsPerBlock.x, (N + threadsPerBlock.y - 1)/threadsPerBlock.y);

    //Timing the kernel execution
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    cudaEventRecord(start);

    //Launch Kernel
    matrixMul<<<blocksPerGrid, threadsPerBlock>>>(d_A,d_B,d_C,N);
    cudaDeviceSynchronize();

    cudaEventRecord(stop);
    cudaEventSynchronize(stop);

    float ms;
    cudaEventElapsedTime(&ms,start,stop);

    printf("Execution Time: %f ms\n",ms);

    //Copy from device to host
    cudaMemcpy(h_C,d_C,size,cudaMemcpyDeviceToHost);

    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N;j++){
            printf("%.4f\n",h_C[i*N + j]);
        }
    }

    

    //Free Memory
    free(h_A);
    free(h_B);
    free(h_C);
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);



    return 0;
}
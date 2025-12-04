#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
	int N, threads;
	printf("Enter matrix size N: ");
	scanf("%d",&N);

	printf("Enter number of threads: ");
	scanf("%d",&threads);

	omp_set_num_threads(threads);
	

	//Allocate Memory
	double *A = (double*)malloc((long)N*N*sizeof(double));
	double *B = (double*)malloc((long)N*N*sizeof(double));
	double *C = (double*)malloc((long)N*N*sizeof(double));

	//Initialize Matrices
	for(long i = 0; i < N*N; i++){
		A[i] = (double)(rand() % 100);
		B[i] = (double)(rand() % 100);
		C[i] = 0.0;

	}

	//start time measurement
	double start = omp_get_wtime();
	
	//Parallel Matrix Multiplication
	#pragma omp parallel for collapse(2)
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
		double sum = 0.0;
		for(int k = 0; k < N; k++){
			sum += A[i*N + k] * B[k*N + j];
		}
		C[i*N + j] = sum;
		
		

		}
		

	}


	//end time measurement
	double end = omp_get_wtime();


	//Print Matrix C
	for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        printf("%.2f\n", C[i*N + j]);
    }
    
}

	printf("Execution time: %.4f seconds\n",end-start);
	

	return 0;




} 

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define N 5


int main(int argc, char **argv){
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	double *A = NULL;
	double *B = malloc(N*N*sizeof(double));
	double *C = NULL;

	
	if(rank == 0){
	
	//Allocate Matrices
	A = malloc(N*N*sizeof(double));
	C = malloc(N*N*sizeof(double));

	//Initialize matrices
	for(int i = 0; i < N*N; i++){
		A[i] = (double)(rand() % 100);
		B[i] = (double)(rand() % 100);
		C[i] = 0.0;
	}


	}

	//Broadcast B to all processes
	MPI_Bcast(B,N*N,MPI_DOUBLE,0,MPI_COMM_WORLD);

	//Scatter rows of A to each process
	int rows_per_proc = N / size;
	int remainder = N % size;

	int local_rows;
	local_rows = rows_per_proc + (rank < remainder ? 1:0);

	//Prepare counts and displacements for Scatterv/Gatherv

	int *sendcounts = malloc(size * sizeof(int));
	int *range = malloc(size * sizeof(int));

	int offset = 0;
	for(int i = 0; i < size; i++){
	int rows;
	if (i < remainder){
		rows = rows_per_proc + 1;
	}

	else 
		rows = rows_per_proc;
	
	sendcounts[i] = rows*N;
	range[i] = offset;
	offset += sendcounts[i];


	}
	
	double *local_A = malloc(local_rows * N * sizeof(double));
	double *local_C = malloc(local_rows * N * sizeof(double));

	MPI_Barrier(MPI_COMM_WORLD);
    double start_time = MPI_Wtime();

	//Scatter rows of A
	MPI_Scatterv(A,sendcounts,range,MPI_DOUBLE,local_A,local_rows*N,MPI_DOUBLE,0,MPI_COMM_WORLD);

	//Local Matrix Multiplication
	for(int i = 0; i < local_rows; i++){
		for(int j = 0; j < N; j++){
			double sum = 0.0;
			for(int k = 0; k < N; k++){
				sum += local_A[i*N + k] * B[k*N + j];
			}
			local_C[i*N + j] = sum;
		}
	}

	//Gather results to C
	MPI_Gatherv(local_C,local_rows*N,MPI_DOUBLE,C,sendcounts,range,MPI_DOUBLE,0,MPI_COMM_WORLD);

	MPI_Barrier(MPI_COMM_WORLD);
    double end_time = MPI_Wtime();


	if(rank ==0){
	for(int i = 0; i < N*N; i++){
		printf("%.4f\n",C[i]);
	}

	printf("Execution Time: %.6f seconds\n",end_time - start_time);
}



	

	//Free Memory
	free(B);
	free(local_A);
	free(local_C);
	free(sendcounts);
	free(range);
	if(rank == 0){
		free(A);
		free(C);
	}
	MPI_Finalize();
	return 0;


}

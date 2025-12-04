#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int N;
    printf("Enter matrix size N: ");
    scanf("%d",&N);

    
    float A[N][N];
    float B[N][N];
    float C[N][N];


    //Populate the matrices
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0.0; 
        }
    }

    //start clock
    clock_t start = clock();

    //Matrix Multipliocation
    for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++) {
                C[i][j] = 0;
                for (int k = 0; k < N; k++)
                    C[i][j] += A[i][k] * B[k][j];
            } 
        }   

    //end clock    
    clock_t end = clock();
        
        
    //Print Resultant Matrix
    for(int i =0; i < N; i++){
        for(int j = 0; j < N ; j++){
            printf("%.2f\n",C[i][j]);
        }
    }

    //Print Execution Time
    double time = ((double)(end - start)/CLOCKS_PER_SEC);
    printf("Execution time: %.6f seconds\n",time);


    return 0;
}
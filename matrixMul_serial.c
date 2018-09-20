#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define N 1000


void multiply(float mat1[][N], float mat2[][N], float *res[N]) 
{ 
    int i, j, k; 
    for (i = 0; i < N; i++){ 
        for (j = 0; j < N; j++){ 
	    res[i][j] = 0; 
	    for (k = 0; k < N; k++) 
                res[i][j] += mat1[i][k]*mat2[k][j]; 
	} 
    }
}


void main(){ 
    double timeStrt, timeEnd;
    float mat1[N][N];
    float mat2[N][N]; 
    float *res[N]; // To store result 
    int i,j;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            mat1[i][j]=rand()%100;
            mat2[i][j]=rand()%100;
         }
    }
    for(i = 0; i < N; i++) {
    res[i] = (void*)malloc(sizeof(float*));
    }
    timeStrt=omp_get_wtime();
    multiply(mat1, mat2, res); 
    timeEnd=omp_get_wtime();

    /*printf("Result matrix is \n"); 

    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
           printf("%f", res[i][j]); 
        printf("\n"); 
    }*/
    printf("Time taken to run this code = %f\n",timeEnd-timeStrt);

 
} 

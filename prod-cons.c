#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define N 1000
int flag = 0;
void fill_rand(int n, int *arr) {
	for(int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	flag = 1;
	#pragma omp flush (flag)
}

int sum_array(int n, int *arr) {
	int sum = 0;
	
	while(!flag);

	for(int i = 0; i < n; i++)
		sum+=arr[i];
	return sum;
}
int main()
{
	int *A, sum;
       	double runtime;
	A = (int *)malloc(N*sizeof(int));
	#pragma omp parallel
	{
		runtime = omp_get_wtime();
		#pragma omp sections
		{
			#pragma omp section
			fill_rand(N, A);

			#pragma omp section
			sum = sum_array(N, A);
		}
		runtime = omp_get_wtime() - runtime;
	}
	printf(" In %lf seconds, The sum is %d \n",runtime,sum);
}

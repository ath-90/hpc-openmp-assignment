#include<stdio.h>
#include<stdlib.h>
#include"omp.h"

int main(){

	static long num_steps = 300000;
	
	double  pi=0.0;
	
	double step = 1.0/(double)num_steps;
	int numberOfThreads;

	double s_time=omp_get_wtime();
 	
	printf("Serial code Start:%lf\n",s_time) ;
	
		double x, sum = 0.0;
		
		for( int i=0; i<num_steps;i++){
			x=(0.5+i)*step;
			sum+=4.0/(1.0+x*x);		
		}		
		pi=sum*step;

	double e_time=omp_get_wtime();	
	printf("Serial code End:%lf",e_time) ;
	printf("\nSerially Execution Time:%lf",e_time-s_time) ;
	 
	
	printf("\nSerially Calculated pi value:%lf\n",pi);
	


	pi=0.0;
	s_time=omp_get_wtime();
 	

	printf("\nParallel code Start:%lf",s_time) ;
	#pragma omp parallel 
	{	double x, sum = 0.0;
		int id=omp_get_thread_num();
		int nTh= omp_get_num_threads();
		if(id==0)numberOfThreads=nTh;
		for(int i=0; i<num_steps;i=i+nTh){
			
			x=(0.5+i)*step;
			sum+=4.0/(1.0+x*x);
		
		}
		
		#pragma omp atomic
			pi=pi+sum*step;
		
	}
 	e_time=omp_get_wtime();

	printf("\nParallel code End:%lf",e_time) ;
	printf("\nParallelExecution Time:%lf",e_time-s_time) ;
	printf("\nParallelly calculated pi value:%lf\n",pi);
	return 0;
}

#include<stdio.h>
#include<math.h>
#include "omp.h"
#define N 65536
#define A 2

void main()
{
    double a[N],b[N];
    double timeStrt, timeEnd;
    int i=0;
    for(i=0;i<N;i++){
        a[i]=rand()%100;
	b[i]=rand()%100;
	}

   timeStrt=omp_get_wtime();

   for(i=0;i<N;i++){
      a[i]=A*a[i]+b[i];
   }
   timeEnd = omp_get_wtime();
   printf("Time taken to run this code = %f\n",timeEnd-timeStrt);
}

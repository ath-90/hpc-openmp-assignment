#include<stdio.h>
#include<math.h>
#include "omp.h"
#define N 65536
#define A 2
#define NT 10

void main()
{
    double a[N],b[N];
    double timeStrt, timeEnd;
    int i=0;
    for(i=0;i<N;i++){
        a[i]=rand()%100;
	b[i]=rand()%100;
	}
   //omp_set_dynamic(0);     // Explicitly disable dynamic teams
   omp_set_num_threads(NT);
   timeStrt=omp_get_wtime();
   #pragma omp parallel
   {
   // Variable declaration
   int id, i, Nthreads, istart, iend;
   id = omp_get_thread_num();
   // Gets number of threads in the machine
   Nthreads = omp_get_num_threads();
   //printf("%d",Nthreads);
   istart = N/Nthreads*id;
   iend = N/Nthreads*(id+1);
   if (id==Nthreads-1)
       iend=N;
   for(i=istart;i<iend;i++){
      a[i]=A*a[i]+b[i];
      }
   }
   timeEnd = omp_get_wtime();
   printf("Time taken to run this code is = %f (for number of threads = %d)\n",timeEnd-timeStrt, NT);
}

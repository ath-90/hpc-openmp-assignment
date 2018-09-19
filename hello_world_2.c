#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void printHello(int tid) {
	printf("Hello World from thread = %d\n", tid);
}
int main (int argc, char *argv[]) 
{
int nthreads, tid;

/* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel private(nthreads, tid)
  {

  /* Obtain thread number */
  tid = omp_get_thread_num();
  printHello(tid);

  }  /* All threads join master thread and disband */

}

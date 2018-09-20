#include <stdio.h>
#include "omp.h" /* OpenMP compiler directives, APIs are declared here */
void printHello(int threadID)
{
    printf("hello world from thread (%d)\n", threadID);
}

void main()
{
/* Parallel region begins here */
#pragma omp parallel
{
int ID = omp_get_thread_num();
printHello(ID);
}
}


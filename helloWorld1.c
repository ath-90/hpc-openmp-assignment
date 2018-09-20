#include <stdio.h>
#include "omp.h" 
void main()
{
/* Parallel region begins here */
#pragma omp parallel
{
   printf("hello world\n");
}
}


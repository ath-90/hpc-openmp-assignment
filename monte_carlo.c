#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
#include"omp.h"

int random_gg() {
	static int c = 0;
	int a[] = {5,4,2,8,9,0,1,3,7,6};

	return a[(c++)%10];
}
int main(){

    static long interval = 1000000;
    double  pi=0.0;
    double c_point=0.0;
    double s_point=0.0;



    double s_time=omp_get_wtime();
     srand(time(NULL)); 

    printf("Serial code Start:%lf",s_time) ;
    
    for(long int i=0; i<interval;i++){

        double r_x=(double)(random_gg() % (interval + 1)) / interval; 
        double r_y=(double)(random_gg() % (interval + 1)) / interval; 

        double tot= (r_x*r_x)+(r_y*r_y);

        if(tot<=1.0)
            c_point++;
	s_point++;
        
    }
    

    double e_time=omp_get_wtime();

    printf("\nSerial code End:%lf",e_time) ;
    printf("\nExecution Time:%lf",e_time-s_time) ;

    pi= (double)c_point/s_point * 4;


    printf("\nCalculated pi value Serial:%lf\n",pi);


    




   /* pi=0.0;
    c_point=0.0;
    s_point=0.0;



    s_time=omp_get_wtime();
     srand(time(NULL)); 

    printf("Parallel code Start:%lf",s_time) ;
    #pragma omp parallel for reduction(+:c_point,s_point)
    
    for(long int i=0; i<interval*interval;i++){

        double r_x=(double)(random() % (interval + 1)) / interval; 
        double r_y=(double)(random() % (interval + 1)) / interval; 

        double tot= r_x*r_x+r_y*r_y;

        if(tot<=1.0)
            c_point++;
        s_point++;
        
    }
    

     e_time=omp_get_wtime();

    printf("\nParallel code End:%lf",e_time) ;
    printf("\nExecution Time:%lf",e_time-s_time) ;

    pi= 4*c_point/s_point;


    printf("\nCalculated pi value:%lf\n",pi);*/
    return 0;
}

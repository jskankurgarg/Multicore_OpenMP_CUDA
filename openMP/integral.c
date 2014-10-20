#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
double global_area=0.0;

/**
f(x)=x*x which is a parabolic equation
sample I/O
from a(x=2) to b(x=4) with thread count=4 and n=32000
the calculated result is 18.663948 and the actual result is 18.666667
*/
double f(double x){
	 return x*x;
}

void Trapezium(double a,double b,int n){
	 double local_area ,h ,x;
	 double local_a ,local_b;
	 int i ,local_n;
	 int my_rank=omp_get_thread_num();
	 int thread_count=omp_get_num_threads();

	 h=(b-a)/n;
	 local_n=n/thread_count;
	 local_a=a + my_rank * local_n * h;
	 local_b=local_a + local_n * h;
	 local_area= (f(local_a) + f(local_b))/2;
	 for(i=1;i<local_n-1;i++){
		  x=local_a + i*h;
		  local_area=local_area+f(x);
	 }
	 local_area=local_area*h;

	 #pragma omp critical
	 	global_area=global_area + local_area;
}
void main(int argc,char* argv[]){
	 double a,b;
	 int n,thread_count;
	 if(argc!=2){
		  fprintf(stderr,"Usage: ./a.out thread_Count_value\n");
		  exit(0);
	 }
	 thread_count=strtol(argv[1],NULL,10);
	 printf("enter a,b, and n:\n");
	 scanf("%lf%lf%d",&a,&b,&n);
	 if(n%thread_count!=0){
		  fprintf(stderr,"n must be evenly divisible by thread_count\n");
		  exit(0);
	 }
	 #pragma omp parallel num_threads(thread_count)
	 	Trapezium(a,b,n);
	 printf("\nwith n = %d trapezoids, our estimated area of the integral from %lf to %lf is %.10lf\n",		n,a,b,global_area);
}
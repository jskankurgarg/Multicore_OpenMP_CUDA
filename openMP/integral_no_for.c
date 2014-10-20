#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

/**
 * FFFFFFUUUUUUUUURRRRRRRJJJJJJJJJIIIIIIII
f(x)=x*x which is a parabolic equation
sample I/O
from a(x=2) to b(x=4) with thread count=4 and n=32000
the calculated result is 18.663948 and the actual result is 18.666667
*/
double f(double x){
	 return x*x;
}
void main(int argc,char* argv[]){
	 double a,b,h,global_area=0.0;
	 int n,thread_count,i,x;
	 if(argc!=2){
		  fprintf(stderr,"Usage: ./a.out thread_Count_value\n");
		  exit(0);
	 }
	 thread_count=strtol(argv[1],NULL,10);
	 printf("enter a,b, and n:\n");
	 scanf("%lf%lf%d",&a,&b,&n);

	 h=(b-a)/n;
	 global_area=global_area+(f(a)+f(b))/2;
	 #pragma omp parallel for num_threads(thread_count) reduction(+:global_area)
	 	for(i=1;i<=n-1;i++)
		{
		   	x = a + i * h ;
		  	global_area=global_area+f(x);
		}
	 global_area=h*global_area;
	 printf("\nwith n = %d trapezoids, our estimated area of the integral from %lf to %lf is %.10lf\n",		n,a,b,global_area);
}
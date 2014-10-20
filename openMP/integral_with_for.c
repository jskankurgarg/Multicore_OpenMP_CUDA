#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
double f(double x){return x*x;}
void main(int argc,char*argv[]){
	 int tc=strtol(argv[1],NULL,10);
	 double a,b,area=0.0,h;
	 int n;
	 printf("enter a , b and n:\n");
	 scanf("%lf %lf %d",&a,&b,&n);
	 printf("\ntc=%d\n",tc);
	 h=(b-a)/n;
	 area=h*((f(a)+f(b))/2);
	 int i=0;
	 double start=0.0,end=0.0,sum=0.0,x;
	 double limit=(double)n/tc;
	 printf("\nhello\n");
	 #pragma omp parallel for num_threads(tc) reduction(+:sum)
	 	for(i=1;i<n;i++)
		{
		  x=a+(i*h);
		  sum+=f(x);
		}
	area+=h*sum;
	 printf("\ntotal area: %.10lf\n",area);
}
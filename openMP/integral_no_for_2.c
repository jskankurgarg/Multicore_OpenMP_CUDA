#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
double f(double x){return x*x;}

void calc_area(double start,double end,double h,double* area)
{
	 double i;
	 double x,local_area=0.0;
// 	 #pragma omp critical not required
	 for(i=start;i<end;i=i+h)
	 {
		  local_area+=f(i);
	 }
	 local_area=local_area*h;
	 printf("\nlocal area[%d]: %.10lf\n",omp_get_thread_num(),local_area);
	 #pragma omp critical
	 	*area+=local_area;
}

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
	 double start=0.0,end=0.0;
	 double limit=(double)n/tc;
	 printf("\nhello\n");
	 #pragma omp parallel for num_threads(tc) firstprivate(start,end,limit)
	 	for(i=0;i<tc;i++)
		{
		  	start=a+(i*limit*h);
			end=start+(limit*h);
			calc_area(start,end,h,&area);
			printf("\t%d,%d\t",omp_get_thread_num(),omp_get_num_threads());
		}
	 printf("\ntotal area: %.10lf\n",area);
}
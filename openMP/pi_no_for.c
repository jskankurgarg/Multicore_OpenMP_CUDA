#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

/**
sample I/O
with thread_count = 4 and n = 32000
the calculated PI is 3.141561 and the actual PI is 3.141592654
*/
void calc(int n,double* pi);

void main(int argc,char* argv[]){
	 double factor,sum=0.0,pi=0.0;
	 int n,thread_count;
	 if(argc!=2){
		  fprintf(stderr,"Usage: ./a.out thread_Count_value\n");
		  exit(0);
	 }
	 thread_count=strtol(argv[1],NULL,10);
	 printf("enter n:\n");
	 scanf("%d",&n);
	 if(n%thread_count!=0){
		  fprintf(stderr,"n must be evenly divisible by thread_count\n");
		  exit(0);
	 }
	 int k=0;
	 factor=1;
	 #pragma omp parallel num_threads(thread_count)
		calc(n,&pi);
	 printf("value PI with n = %d  : %.10lf\n",n,pi);
}
void calc(int n,double * pi){
	 int thread_count=omp_get_num_threads();
	 int local_n,start,end,k;
	 int my_rank=omp_get_thread_num();
	 
	 local_n=n/thread_count;
	 start=my_rank*local_n;
	 end=start+local_n;
	 double factor=1.0,sum=0.0;
	 
	 for(k=start;k<end;k++){
		  factor=(k%2==0)?1.0:-1.0;
		  sum+=factor/(2*k+1);
	 }
	 sum=sum*4;
	 #pragma omp critical
	 {
		  *pi+=sum;
	 }
}
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

/**
sample I/O
with thread_count = 4 and n = 32000
the calculated PI is 3.141561 and the actual PI is 3.141592654
*/
void main(int argc,char* argv[]){
	 double factor,sum,pi;
	 int n,thread_count;
	 if(argc!=2){
		  fprintf(stderr,"Usage: ./a.out thread_Count_value\n");
		  exit(0);
	 }
	 thread_count=strtol(argv[1],NULL,10);
	 printf("enter n:\n");
	 scanf("%d",&n);
	 int k=0;
	 factor=1;
	 #pragma omp parallel for num_threads(thread_count) reduction(+:sum) firstprivate(factor)
		  for(k=0;k<n;k++){
			   factor=(k%2==0)?1.0:-1.0;
			   sum+=factor/(2*k+1);
		  }
	 pi=4.0*sum;
	 printf("value PI with n = %d  : %.10lf\n",n,pi);
}
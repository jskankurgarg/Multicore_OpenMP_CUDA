#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main(int argc,char* argv[]){
	 double factor,sum=0.0,pi;
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
	 #pragma omp parallel for num_threads(thread_count) reduction(+:sum)
		  for(k=0;k<n;k++){
			   factor=(k%2==0)?1.0:-1.0;
			   sum+=factor/(2*k+1);
		  }
	 pi=4.0*sum;
	 printf("value PI with n = %d  : %lf\n",n,pi);
	 //NOTE:factor should made private to get precise value of PI
}
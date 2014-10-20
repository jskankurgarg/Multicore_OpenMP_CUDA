#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main(int argc,char*argv[]){
	 int tid=omp_get_thread_num();
	 printf("main thread: %d total-threads: %d\n",tid,omp_get_num_threads());
	 #pragma omp parallel num_threads(strtol(argv[1],NULL,10))
	 {
		  printf("thread: %d total-threads: %d\n",omp_get_thread_num(),omp_get_num_threads());
	 }
}
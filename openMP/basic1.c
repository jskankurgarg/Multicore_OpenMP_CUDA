#include<stdio.h>
#include<stdlib.h>
void hello(){
	int id=omp_get_thread_num();
	printf("Hello world== %d\n",id);
}
void main(int argc,char* argv[]){
	 int thread_count=strtol(argv[1],NULL,10);
	 #pragma omp parallel/** num_threads(thread_count)*/
	 {
		  hello();
	 }
}
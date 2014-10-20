#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main(int argc,char* argv[]){
	 if(argc!=2){
		  printf("Usage: ./a.out no_of_elements\n");
		  exit(0);
	 }
	 int n=atoi(argv[1]),i,sum=0;//NOTE:sum must be initialized before using in reduction
	 int *arr=(int*)malloc(n*sizeof(int));
	 printf("enter %d array elements \n",n);
	 for(i=0;i<n;i++)
	 {
	 	scanf("%d",&arr[i]);
	 }
	 i=0;
	 sum=0;
	 #pragma omp parallel  num_threads(n) default(shared)
	 {
		  #pragma omp critical
		  {
			   sum+=arr[omp_get_thread_num()];
			   printf("sum=%d and arr_element= %d and tid : %d\n",sum,arr[omp_get_thread_num()],omp_get_thread_num());
		  }
		   
	 }
}
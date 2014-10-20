#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main(int argc,char* argv[]){
	 if(argc!=2){
		  printf("Usage: ./a.out no_of_elements\n");
		  exit(0);
	 }
	 printf("omp_get_thread_num() : %d\tomp_get_num_threads() : %d\n",omp_get_thread_num(),omp_get_num_threads());
	 int n=atoi(argv[1]),i,sum=0;//NOTE:sum must be initialized before using in reduction
	 int *arr=(int*)malloc(n*sizeof(int));
	 printf("enter %d array elements \n",n);
	 for(i=0;i<n;i++)
	 {
	 	scanf("%d",&arr[i]);
	 }
/**	 printf("\nentered elements: \n");
	 for(i=0;i<n;i++)
		  printf("%d\n",arr[i]);
*/
	#pragma omp parallel for// reduction(+:sum)//if critical not used inside for loop
		for(i=0;i<n;i++){
	 	#pragma omp critical
	 	{
		  sum+=arr[i];
// 		  sleep(1);
		}
#pragma omp single
		  printf("\nsum = %d and arr[%d]= %d\n",sum,i,arr[i]);
		}
	 printf("\nsum of array elements: %d\n",sum);
}
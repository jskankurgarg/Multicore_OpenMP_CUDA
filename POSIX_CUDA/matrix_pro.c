#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>

int **m1,*m2,*m3,n,tc;
pthread_t *th;
void* dotProduct(void * parameter){
	 int j=0,i;
	 i=*(int*)parameter;
	 i*=(n/tc);
	 int upto=i + (n/tc); 
	 if(upto==n-1 && n%2!=0 && tc!=n){/**this condition is helpful in case of odd order matrix multiplication*/
		  upto++;
	 }
	 for(;i<upto;i++){
		  for(j=0;j<n;j++){
			   m3[i]+=m1[i][j]*m2[j];
		  }
	 }
}
void main(){
	 printf("\nenter the order for matrix1[n][n] * matrix2[n][1] :");
	 scanf("%d",&n);
	 m1=malloc(n*sizeof(int));
	 m2=malloc(n*sizeof(int));
	 m3=malloc(n*sizeof(int));
	 int i,j;
	 printf("\n enter the element-value for matrix2[n][1]\n");
	 for(i=0;i<n;i++){
		  m1[i]=malloc(n*sizeof(int));
		  m3[i]=0;/**initialization of resultant matrix*/
		  printf("\nm2[ %d ] : ",i);
		  scanf("%d",&m2[i]);
	 }
	 printf("\n  enter the element-value for matrix1[n][n]\n");
	 for(i=0;i<n;i++){
		  for(j=0;j<n;j++){
			   printf("\nm1[ %d ][ %d ] : ",i,j);
			   scanf("%d",&m1[i][j]);
		  }
	 }
	 printf("\n enter the thread count : ");
	 scanf("%d",&tc);
	 tc=((tc>n)?n:tc);
	 th=malloc(tc*sizeof(pthread_t));
	 for(i=0;i<tc;i++){
		  pthread_create(&th[i],NULL,dotProduct,(void*)&i);
		  printf("\nthread no. %d created",i+1);
	 }
	 for(i=0;i<tc;i++)
		  pthread_join(th[i],NULL);
	 printf("\nresultant matrix[ %d ][ 1 ]  \n",n);
	 for(i=0;i<n;i++){
		  printf("%d\n",m3[i]);
	 }
}
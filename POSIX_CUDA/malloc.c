#include<stdio.h>
#include<stdlib.h>
void main(){
	 int n,i;
	 scanf("%d",&n);
	 int *arr=malloc(n*sizeof(int));
// 	 arr[n]=90;
	 for(i=0;i<n;i++){
		  printf("\n%d",arr[i]);
	 }
	 int **da;
	 da=malloc(3*sizeof(int));
	 for(i=0;i<3;i++)
		  da[i]=malloc(4*sizeof(int));
	 da[1][2]=78;	da[2][3]=9999;
	 printf("\nda[1][2]=%d and da[2][3]=%d\n",da[1][2],da[2][3]);
}
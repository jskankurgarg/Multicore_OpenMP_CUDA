#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main(){
	 int a=1,b=2;
	 printf("shared(a,b)\n");
	 #pragma omp parallel shared(a,b)
	 /** by default shared [shared(a,b) not required] among all threads(total 4 threads)*/
	 {
	 	a++;b++;
	 	printf("a=%d b=%d\n",a,b);
	 }
	 printf("----------------------------\n");
	 printf("a=%d b=%d\n",a,b);
	 printf("----------------------------\n");
	 printf("private(a)\n");
	 #pragma omp parallel private(a)
	 /**private makes the variable local to a thread with undefined value*/
	 {
		  a++;
		  #pragma omp critical
		  	{b++;/**sleep(1);*/}
		  printf("a=%d b=%d\n",a,b);
	 }
	 printf("----------------------------\n");
	 printf("a=%d b=%d\n",a,b);
	 printf("----------------------------\n");
	 printf("firstprivate(a) private(b)\n");
	 #pragma omp parallel firstprivate(a) private(b)
	 /**private makes the variable local to a thread with undefined value*/
	 {
		  a++;b++;
		  printf("a=%d b=%d\n",a,b);
	 }
	 printf("----------------------------\n");
	 printf("a=%d b=%d\n",a,b);
	 printf("----------------------------\n");
	 int i;
	 /** by default lastprivate variable have undefined value*/
	 printf("lastprivate(a) firstprivate(b)\n");
	 #pragma omp parallel for lastprivate(a) firstprivate(b)
	 	for(i=0;i<4;i++){
			 a=i;b++;//a++ then undefined value for a
			 printf("a=%d b=%d i=%d\n",a,b,i);
			 
	 	}
	 printf("----------------------------\n");
	 printf("a=%d b=%d\n",a,b);
	 printf("----------------------------\n");
/**
	#pragma omp parallel lastprivate(a,b) private(c,d)
error:‘lastprivate’ is not valid for ‘#pragma omp parallel’
	 {
		  printf("a=%d b=%d c=%d d=%d \n",a,b,c,d);
	 }
*/
}
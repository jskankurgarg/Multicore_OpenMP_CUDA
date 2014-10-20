#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int argc,char* argv[]){
    int a[20];
    int n,i,tc,sum=0;
    tc=strtol(argv[1],NULL,10);
    printf("enter the no of elements to be entered..\n");
    scanf("%d",&n);
    printf("enter the elements..\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
#pragma omp parallel for num_threads(tc)\
reduction(+: sum)
for(i=0;i<n;i++)
sum+=a[i];
printf("summation is %d",sum);
return 0;
}

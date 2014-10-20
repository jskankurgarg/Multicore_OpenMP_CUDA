#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
# define n_thread 4
# define n 800                      //as the number of n increases our answer becomes more acurate for ex: for n=40 value of area for range from 2-4 is 17.292,
float h;                            //for n=400 it is 18.529 and for n=400 it is 18.597
float s[n];
float area=0.0;
int a,b;
struct limit
{
int y,z;
}l[4];
void *trap(int m,int i)
{
int j;
#pragma omp critical
for(j=m+1;j<i;j++)
{
s[j]=a+j*h;
s[j]=s[j]*s[j];                     //since function is y=x*x
area+=h*s[j];
}

}
int main()
{
printf("the function used is y=x*x\n");
void * status;
printf("enter the starting value of a");
scanf("%d",&a);
printf("enter the value of b");
scanf("%d",&b);
h=(b-a);
h=h/n;
s[0]=a*a;
s[n]=b*b;
area=h*(s[0]/2+s[n]/2);
int k=0;
int p=n/n_thread;
#pragma omp parallel for num_threads(4)               //creates 4 threads which calculate the area
for(k=0;k<n_thread;k++)
{
l[k].y=k*p;
l[k].z=(k+1)*p;
trap(l[k].y,l[k].z);
}
printf("%lf\n",area);
}

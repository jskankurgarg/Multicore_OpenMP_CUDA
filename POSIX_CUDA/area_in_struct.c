#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#define NUM_THREADS 5

struct Triangle{
	 float base,height,area;
};
struct SemiCircle{
	 float radius,area;
};
struct Rectangle{
	 float breadth,length,area;
};
struct Square{
	 float side,area;
};
struct Trapezium{
	 float p1,p2,height,area;
};
void *AreaOfSemiCircle(void *dimension){
   struct SemiCircle* temp = (struct SemiCircle *)dimension;
   temp->area=3.141592654*temp->radius*temp->radius/2;
   printf("AreaOfSemiCircle: %f\n",temp->area);
}
void *AreaOfTriangle(void * dimension){
	struct Triangle* temp=(struct Triangle*)dimension;
	temp->area=(temp->base*temp->height)/2;
	printf("AreaOfTriangle: %f\n",temp->area);
}
void *AreaOfTrapezium(void * dimension){
	 struct Trapezium* temp=(struct Trapezium*)dimension;
	 float sum=( temp->p1) +( temp->p2 );
	 printf("\nsum=   %f   and p1=%f,p2=%f,height=%f,sum* height=  %f\n",sum,temp->p1,temp->p2,temp->height,sum*temp->height);
	 temp->area= sum* (temp->height/2);
	 printf("AreaOfTrapezium: %f\n",temp->area);
}
void main (void){
   	pthread_t th[6];
	struct Triangle t1,t2;
	t1.base=50;	t1.height=20;
	t2.base=100;	t2.height=20;
	struct SemiCircle sc1;
	sc1.radius=45/2;
	struct Trapezium tz1,tz2,tz3;
	tz1.p1=50;	tz1.p2=80;	tz1.height=20;
	tz2.p1=80;	tz2.p2=65;	tz2.height=45;
	tz3.p1=65;	tz3.p2=100;	tz3.height=30;
	pthread_create(&th[0],NULL,AreaOfTriangle,(void*)&t1);
	pthread_create(&th[1],NULL,AreaOfTriangle,(void*)&t2);

	pthread_create(&th[2],NULL,AreaOfSemiCircle,(void*)&sc1);

	pthread_create(&th[3],NULL,AreaOfTrapezium,(void*)&tz1);
	pthread_create(&th[4],NULL,AreaOfTrapezium,(void*)&tz2);
	pthread_create(&th[5],NULL,AreaOfTrapezium,(void*)&tz3);
	
	pthread_join(th[0],NULL);
	pthread_join(th[1],NULL);
	pthread_join(th[2],NULL);
	pthread_join(th[3],NULL);
	pthread_join(th[4],NULL);
	pthread_join(th[5],NULL);
	float totalArea=t1.area+t2.area+sc1.area+tz1.area+tz2.area+tz3.area;
	printf("total area of given geometrical figure : %f\n",totalArea);
}
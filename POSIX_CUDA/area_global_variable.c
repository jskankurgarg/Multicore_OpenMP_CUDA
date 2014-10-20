#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define PIE 3.141592654
struct Triangle{
	 float base,height;
};
struct SemiCircle{
	 float radius;
};
struct Rectangle{
	 float breadth,length;
};
struct Square{
	 float side;
};
struct Trapezium{
	 float p1,p2,height;
};
float totalArea=0;


void *AreaOfSemiCircle(void *dimension){
   float area;
   struct SemiCircle temp = *((struct SemiCircle *) dimension);
   area=PIE*temp.radius*temp.radius/2;
   totalArea+=area;
   printf("AreaOfSemiCircle: %f and totalArea: %f\n",area,totalArea);
   pthread_exit("success");
}
void *AreaOfTriangle(void * dimension){
	struct Triangle temp=*(struct Triangle*)dimension;
	float area=(temp.base*temp.height)/2;
	totalArea+=area;
	printf("AreaOfTriangle: %f and totalArea: %f\n",area,totalArea);
 	pthread_exit("success");
}
void *AreaOfTrapezium(void * dimension){
	 struct Trapezium temp=*(struct Trapezium*)dimension;
	 float area=((temp.p1+temp.p2)*temp.height)/2;
	 totalArea+=area;
	 printf("AreaOfTrapezium: %f and totalArea: %f\n",area,totalArea);
 	 pthread_exit("success");
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
	/**totalArea value is not guaranteed to be same always in the below statement*/
	printf("\nNow totalArea=%f\n",totalArea);
}
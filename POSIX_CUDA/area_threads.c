#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
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
void *AreaOfSemiCircle(void *dimension){
   struct SemiCircle temp = *((struct SemiCircle *) dimension);
   static float area1=0;
   area1=3.141592654*temp.radius*temp.radius/2;
   printf("AreaOfSemiCircle: %f\n",area1);
   pthread_exit((void*)&area1);
}
void *AreaOfTriangle(void * dimension){
	struct Triangle temp=*(struct Triangle*)dimension;
	static float area2=0;
	area2=(temp.base*temp.height)/2;
	printf("AreaOfTriangle: %f\n",area2);
	pthread_exit((void *)&area2);
}
void *AreaOfTrapezium(void * dimension){
	 struct Trapezium temp=*(struct Trapezium*)dimension;
	 static float area3=0;
	 area3=((temp.p1+temp.p2)*temp.height)/2;
	 printf("AreaOfTrapezium: %f\n",area3);
	 pthread_exit((void *)&area3);
}
void main (void){
   	pthread_t th[6];
	void *at1,*at2,*asc1,*atz1,*atz2,*atz3;
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
	
	pthread_join(th[0],&at1);
	pthread_join(th[1],&at2);
	pthread_join(th[2],&asc1);
	pthread_join(th[3],&atz1);
	pthread_join(th[4],&atz2);
	pthread_join(th[5],&atz3);
	float a1=*(float*)at1,a2=*(float*)at2,a3=*(float*)asc1,a4=*(float*)atz1,a5=*(float*)atz2,a6=*(float*)atz3;
	float totalArea=0;
	printf("\ncircle=%f\ttriangle1=%f\ttriangle2=%f\ttrap1=%f\ttrap2=%f\ttrap3=%f\n",a1,a2,a3,a4,a5,a6);
	totalArea=a1+a2+a3+a4+a5+a6;
	printf("total area of given geometrical figure : %f\n",totalArea);
}
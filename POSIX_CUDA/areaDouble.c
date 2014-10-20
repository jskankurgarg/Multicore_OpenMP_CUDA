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
   /**float area;/* why this gives an error but an int doesn't?*/
   static double area;
   struct SemiCircle temp = *((struct SemiCircle *) dimension);
   area=3.141592654*temp.radius*temp.radius/2;
   //printf("AreaOfSemiCircle: %d\n",area);/** %f */
   pthread_exit((void*)&area);/**compiler error: cannot convert to a pointer type*/
}
void *AreaOfTriangle(void * dimension){
	struct Triangle temp=*(struct Triangle*)dimension;
	static double area=(temp.base*temp.height)/2;
// 	printf("AreaOfTriangle: %d\n",area);
	pthread_exit((void *)&area);
}
void *AreaOfTrapezium(void * dimension){
	 struct Trapezium temp=*(struct Trapezium*)dimension;
	 static double area=((temp.p1+temp.p2)*temp.height)/2;
// 	 printf("AreaOfTrapezium: %d\n",area);
	 dimension=(void*)&area;
	 pthread_exit((void *)&area);
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
	/** float str=(float*)asc1;/*compiler error: incompatible types when initializing type ‘float’ using type ‘float *’ */
	double a1=*(double*)at1,a2=*(double*)at2,a4=*(double*)atz1,a5=*(double*)atz2,a6=*(double*)atz3;
	double a3=*(double*)asc1;
	/**above works fine but with an warning*/
	double totalArea=a1+a2+a3+a4+a5+a6;
	printf("total area of given geometrical figure : %f\n",totalArea);
}
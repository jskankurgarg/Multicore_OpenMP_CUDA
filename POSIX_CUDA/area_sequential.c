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
void AreaOfSemiCircle(struct SemiCircle temp){
   float area;
   area=PIE*temp.radius*temp.radius/2;
   totalArea+=area;
   printf("AreaOfSemiCircle: %f and totalArea: %f\n",area,totalArea);
}
void AreaOfTriangle(struct Triangle temp){
	float area=(temp.base*temp.height)/2;
	totalArea+=area;
	printf("AreaOfTriangle: %f and totalArea: %f\n",area,totalArea);
}
void AreaOfTrapezium(struct Trapezium temp){
	 float area=((temp.p1+temp.p2)*temp.height)/2;
	 totalArea+=area;
	 printf("AreaOfTrapezium: %f and totalArea: %f\n",area,totalArea);
}
void main (void){
	struct Triangle t1,t2;
	t1.base=50;	t1.height=20;
	t2.base=100;	t2.height=20;
	struct SemiCircle sc1;
	sc1.radius=45/2;
	struct Trapezium tz1,tz2,tz3;
	tz1.p1=50;	tz1.p2=80;	tz1.height=20;
	tz2.p1=80;	tz2.p2=65;	tz2.height=45;
	tz3.p1=65;	tz3.p2=100;	tz3.height=30;
	
	AreaOfTriangle(t1);
	AreaOfTriangle(t2);

	AreaOfSemiCircle(sc1);

	AreaOfTrapezium(tz1);
	AreaOfTrapezium(tz2);
	AreaOfTrapezium(tz3);
	
	printf("\nNow totalArea=%f\n",totalArea);
}
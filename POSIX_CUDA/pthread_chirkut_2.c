#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
void *TaskCode(void *argument)
{
   int tid;
   tid = ((int ) argument);
   printf("\nargumnet= %d\n",tid);
   tid*=2;
	pthread_exit((void*)tid);
}

int main (int argc, char *argv[])
{
   pthread_t td;
   int rc, i=12;
   rc = pthread_create(&td,NULL,TaskCode,(void *)i);
   assert(0 == rc);//if condition is false then it aborts the program.
   printf("\nthread ID[%d] = %ld and rc- %d\n",i,td,rc);
   void * status;
   rc = pthread_join(td, &status);
   int j=(int)status;
   printf("\ntid = %d\n",j);
   exit(EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>



int main()
{

  pthread_t tid0;
  pthread_t tid1;
  pthread_t tid2;
  pthread_t tid3;
  pthread_t tid4;
  pthread_t * pthreads[] = {&tid0,&tid1,&tid2,&tid3,&tid4};


    pthread_create(pthreads[0],NULL,./date,(void *) pthreads[0]);
    pthread_create(pthreads[1],NULL,./mkdir,(void *) pthreads[1]);
    pthread_create(pthreads[2],NULL,./cat,(void *) pthreads[2]);
    pthread_create(pthreads[3],NULL,./mkdir,(void *) pthreads[3]);
    pthread_create(pthreads[4],NULL,./ls,(void *) pthreads[4]);    
   
    pthread_join(pthreads[0],NULL);
    pthread_join(pthreads[1],NULL);
    pthread_join(pthreads[2],NULL);
    pthread_join(pthreads[3],NULL);
    pthread_join(pthreads[4],NULL);
    return 0;
}

#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 5

void *PrintHello(void *threadid){
	long tid;
	tid=(long)threadid;
	printf("hello world from %ld\n", tid);
	pthread_exit(NULL); // this returns a void pointer to null? This also kills the thread running this function

}

int main(int argc, char *argv[]){

	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	for(t=0; t<NUM_THREADS; t++){
		printf("In main: creating thread: %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if(rc){
			printf("ERROR: return code from pthread)create() is %d\n", rc);
			exit(-1);
		}
	}
	pthread_exit(NULL);
}

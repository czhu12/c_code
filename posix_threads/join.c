#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_THREADS 5;

void *BusyWork(void *t){

	int i;
	double result = 0.0;
	int tid = (long)t;
	printf("Thread #%ld starting...\n",tid);
	for(i = 0; i < 1000000; i++){
		result = result + 1;
	}
	printf("Thread #%ld is done. Result: %e\n", tid, result); 
	pthread_exit((void*)&result);
}

int main(int argc, char* argv[])
{

	pthread_t threads[5];
	pthread_attr_t attr;
	int rc;
	long t;
	void *status;
	//set thread attributes
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


	for(t=0; t< 5; t++){
		//throws status upon thread creation ( != 0 is an error)
		rc = pthread_create(&threads[t], &attr, BusyWork, (void *) t);
	
	}
	pthread_attr_destroy(&attr);
	for(t=0;t< 5; t++){
		rc = pthread_join(threads[t], &status);
		printf("Main: completed join with thread %ld having a status of %ld\n", t, status);
	}
	pthread_exit(NULL);
}


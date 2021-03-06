#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function( void *ptr);


main(){
	pthread_t thread1, thread2;
	char *message1 = "thread1";
	char *message2 = "thread2";

	int iret1, iret2;

	iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
	iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("thread 1 returns %d\n", iret1);
	printf("thread 2 returns %d\n", iret2);

	}

void *print_message_function( void *ptr){
	char *message;
	message = (char *) ptr;
	printf("%s \n", message);
}

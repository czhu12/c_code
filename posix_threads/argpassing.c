#include <stdio.h>
#include <pthread.h>

struct thread_data{
	int thread_id;
	int sum;
	char *message;
};

void *PrintHello(void* threadArg){
	struct thread_data *my_data;
	int thread_id;
	int sum;
	char *message;
	my_data = (struct thread_data *)threadArg;
	thread_id = my_data->thread_id;
	sum = my_data->thread_id;
	message = my_data->message;

	printf("hello everyone! this is Thread #%d, I would like to say %s\n", thread_id, message);
	pthread_exit(NULL);

}
int main(int argc, char* argv[]){
	int i;
	int rc;
	struct thread_data array_of_thread_data[5];
	pthread_t pthreads[5];
	for(i = 0; i < 5; i++){
		array_of_thread_data[i].thread_id = i;
		array_of_thread_data[i].sum = 100;
		array_of_thread_data[i].message = "HELLO WORLD";
		rc = pthread_create(&pthreads[i], NULL, PrintHello, (void *)&array_of_thread_data[i]);
				
	} 
	pthread_exit(NULL);

}

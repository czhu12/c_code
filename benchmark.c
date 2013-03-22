#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

//works for unix based systems only
void do_work();

double get_time(){
	struct timeval t;
	struct timezone tzp;
	gettimeofday(&t, &tzp);
	return t.tv_sec + t.tv_usec*1e-6;
}

int main(){
	
	double start_time = get_time();
	do_work();
	double end_time = get_time();
	double total_time = end_time - start_time;
	printf("%f",total_time); 
}

void do_work(){
	printf("doing work...");
	int i;
	int random_work = 0;
	for(i = 0; i < 10000; i++){
		random_work++;
		random_work--;
	}
}

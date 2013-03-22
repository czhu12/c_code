typedef struct Test{
	int start;
	int end;
} Test;

int main(){
	Test* ptr;
	ptr = malloc(sizeof(Test));
	ptr->start = 5;
	ptr->end = 4;
	printf("Start is equal to %d", ptr->start);
	printf("End is equal to %d", ptr->end);
	

	return 0;	
}

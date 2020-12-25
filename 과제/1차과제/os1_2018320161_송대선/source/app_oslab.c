#include <unistd.h>
#include <stdio.h>

#define my_stack_push 335
#define my_stack_pop 336

int main(){
	int a;
	int index;

	for(index = 1; index <=3; index++){
		a = syscall(my_stack_push, index);
		printf("push: ");
		printf("%d\n", a);
	}

	for(index=3; index>=1; index--){	
		a = syscall(my_stack_pop, index);
		printf("pop: ");
		printf("%d\n", a);
	}

	
	a = syscall(my_stack_push, 1);
	printf("push: ");
	printf("%d\n", a);

	a = syscall(my_stack_push, 2);
	printf("push: ");
	printf("%d\n", a);

	a = syscall(my_stack_push, 2);
	printf("push: ");
	printf("%d\n", a);


	return 0;
}


#include <stdio.h>
#include <stdio.h>
#include <stddef.h>
#include "Stack_DS_Array.h"

uint32 max_size = 0;
stack_t* stack1 = NULL;

int main()
{
	StackStatus_t stack_status = Stack_NOK;

	printf("Please Enter Size For Stack\n");
	scanf("%i", &max_size);
	stack1 = CreatStack(max_size, &stack_status);
	if(stack1)
	{
		printf("Stack 1 Created\n");
	}
	stack1 = DestroyStack(stack1, &stack_status);
	if(!stack1)
	{
		printf("Stack 1 Destroed\n");
	}


	return (0);
}

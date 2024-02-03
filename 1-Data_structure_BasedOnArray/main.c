#include <stdio.h>
#include <stdio.h>
#include <stddef.h>
#include "Stack_DS_Array.h"

uint32 max_size = 0;
stack_t* stack1 = NULL;
uint32 var1 = 0x11;
float32 var2 = 2.14;
char var3 = 'a';
uint32 stack_count = 0;
void* ptr = NULL;

int main()
{
	StackStatus_t stack_status = Stack_NOK;

	printf("Please Enter Size For Stack\n");
	scanf("%i", &max_size);
	stack1 = CreatStack(max_size, &stack_status);
	if(stack1)
	{
		printf("Stack 1 Created\n");
		stack_status = PushStack(stack1, &var1); printf("Stack Status is = %i\n", stack_status);
		stack_status = PushStack(stack1, &var2); printf("Stack Status is = %i\n", stack_status);
		stack_status = PushStack(stack1, &var3); printf("Stack Status is = %i\n", stack_status);
                stack_status = PushStack(stack1, &var3); printf("Stack Status is = %i\n", stack_status);
		stack_status = StackCount(stack1, &stack_count); printf("Stack Status is = %i\n", stack_status);
		printf("Stack Counter is = %i\n", stack_count);
		ptr = StackTop(stack1, &stack_status); printf("Stack Status is = %i\n", stack_status);
		printf("Stack Top = %c\n", *((char *)ptr));
		ptr = PopStack(stack1, &stack_status); printf("Stack Status is = %i\n", stack_status);
                printf("Stack Pop = %c\n", *((char *)ptr));
		ptr = PopStack(stack1, &stack_status); printf("Stack Status is = %i\n", stack_status);
                printf("Stack Pop = %0.2f\n", *((float32 *)ptr));
		ptr = PopStack(stack1, &stack_status); printf("Stack Status is = %i\n", stack_status);
                printf("Stack Pop = 0x%X\n", *((uint32 *)ptr));
		stack_status = StackCount(stack1, &stack_count); printf("Stack Counter is = %i\n", stack_count);
                ptr = PopStack(stack1, &stack_status); printf("Stack Status is = %i\n", stack_status);


	}
	stack1 = DestroyStack(stack1, &stack_status);
	if(!stack1)
	{
		printf("Stack 1 Destroed\n");
	}


	return (0);
}

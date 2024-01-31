#include <stdio.h>
#include <stdlib.h>
#include "stack_ds.h"

stack_ds_t stack1;
stack_ds_t stack2;



int main ()
{
	return_status_t ret = R_NOK;

	ret = stack_init (&stack1);
	if (R_NOK == ret)
	{
		printf("stack1 failed to be initalized!!\n");
	}
	else
	{
		ret = stack_push (&stack1, 11);
		ret = stack_push (&stack1, 22);
		ret = stack_push (&stack1, 33);
		ret = stack_push (&stack1, 44);
		ret = stack_push (&stack1, 55);
		ret = stack_push (&stack1, 66);
		ret = stack_push (&stack1, 77);

		printf("Initialization Success\n");
	}
	ret = stack_init (&stack2);
	if (R_NOK == ret)
        {
                printf("stack2 failed to be initalized!!\n");
        }
        else
        {
		printf("Initialization Success\n");

        }





	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include "plat_form.h"
#include "QueueArray.h"

uint32 max_size = 0;
queue_status_t Queue_Return = QUEUE_NOK;
Queue_t * Queue = NULL;
uint32 var1 = 0x11, var2 = 0x22, var3 = 0x33, var4 = 0x44, var5 = 0x55, var6 = 0x66;
void *ret_val = NULL;

int main()
{
	printf("Please Enter The Number Of elements In Queue\n");
	scanf("%i", &max_size);
	Queue = CreatQueue(max_size, &Queue_Return);
	printf("0x%X\n", Queue);
	Queue_Return = EnqueueElement(Queue, &var1); printf("=>%i\n", Queue_Return);
	Queue_Return = EnqueueElement(Queue, &var2); printf("=>%i\n", Queue_Return);
	Queue_Return = EnqueueElement(Queue, &var3); printf("=>%i\n", Queue_Return);
	Queue_Return = EnqueueElement(Queue, &var4); printf("=>%i\n", Queue_Return);
	Queue_Return = EnqueueElement(Queue, &var5); printf("=>%i\n", Queue_Return);
	Queue_Return = EnqueueElement(Queue, &var6); printf("=>%i\n", Queue_Return);
	ret_val = DqueueElement(Queue, &Queue_Return); printf("=>%i\n", Queue_Return);
	printf("Value is (0x%X)\n", *((uint32 *)ret_val));
	ret_val = DqueueElement(Queue, &Queue_Return); printf("=>%i\n", Queue_Return);
	printf("Value is (0x%X)\n", *((uint32 *)ret_val));
	ret_val = DqueueElement(Queue, &Queue_Return); printf("=>%i\n", Queue_Return);
	printf("Value is (0x%X)\n", *((uint32 *)ret_val));
	ret_val = DqueueElement(Queue, &Queue_Return); printf("=>%i\n", Queue_Return);
	printf("Value is (0x%X)\n", *((uint32 *)ret_val));
	ret_val = DqueueElement(Queue, &Queue_Return); printf("=>%i\n", Queue_Return);
	printf("Value is (0x%X)\n", *((uint32 *)ret_val));
	ret_val = DqueueElement(Queue, &Queue_Return); printf("=>%i\n", Queue_Return);
	if(ret_val)
	{
		printf("Value is (0x%X)\n", *((uint32 *)ret_val));
	}
	return (0);
}

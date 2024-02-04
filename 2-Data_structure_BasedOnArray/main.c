#include <stdio.h>
#include <stdlib.h>
#include "plat_form.h"
#include "QueueArray.h"

uint32 max_size = 0;
queue_status_t Queue_Return = QUEUE_NOK;
Queue_t * Queue = NULL;

int main()
{
	printf("Please Enter The Number Of elements In Queue\n");
	scanf("%i", &max_size);
	Queue = CreatQueue(max_size, &Queue_Return);
	printf("0x%X\n", Queue);

	return (0);
}

#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include "plat_form.h"

typedef struct
{
	void **QueueArray;   /* Pointer to array of void pointer */
	uint32 QueueMaxSize; /* Maximum elements in the queue    */
	sint32 ElementCount; /* Number of elements in the queue  */
	sint32 QueueFront;   /* Index of a front element         */
	sint32 QueueRear;    /* Index of a rear element          */
}Queue_t;

typedef enum
{
	QUEUE_NOK,
	QUEUE_OK
}queue_status_t;

#endif // QUEUE_ARRAY_H

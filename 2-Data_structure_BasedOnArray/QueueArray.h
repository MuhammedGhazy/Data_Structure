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

Queue_t *CreatQueue (uint32 max_size, queue_status_t *ret_status);
queue_status_t EnqueueElement (Queue_t *queue_obj, void *Item_ptr);
void *DqueueElement (Queue_t *queue_obj, queue_status_t *ret_status);
void *QueueFront (Queue_t *queue_obj, queue_status_t *ret_status);
void *QueueRear (Queue_t *queue_obj, queue_status_t *ret_status);
queue_status_t GetQueueCount (Queue_t *queue_obj, uint32 *QueueCount);
queue_status_t DestroyQueue (Queue_t *queue_obj);
#endif // QUEUE_ARRAY_H

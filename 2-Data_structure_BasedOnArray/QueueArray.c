#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "QueueArray.h"

Queue_t *CreatQueue (uint32 max_size, queue_status_t *ret_status)
{
	Queue_t* My_Queue = NULL;
	
	/* Creat a queue object in the heap, to hold the queue information */	
	My_Queue = (Queue_t *)malloc(sizeof(Queue_t));
	if((NULL == ret_status) || (NULL == My_Queue))
	{
		*ret_status = QUEUE_NOK;
		My_Queue = NULL;
		printf("Erorr!! This Is Invalid Address, Please Enter Valid Address.\n");
	}
	else
	{
		/* creat array of void*, to hold the addresses of the queue data */
		My_Queue->QueueArray = (void **) calloc(max_size, sizeof(void *));
		if(My_Queue->QueueArray == NULL)
		{
			*ret_status = QUEUE_NOK;
			My_Queue = NULL;
			printf("Something Errors!!, During Allocated Space In The Memory.\n");
		}
		else
		{
			My_Queue->ElementCount = 0;
			My_Queue->QueueFront = -1;
			My_Queue->QueueRear = -1;
			My_Queue->QueueMaxSize = max_size;
			*ret_status = QUEUE_OK;
			printf("Memory Allocated Successfuly.\n");
		}
		*ret_status = QUEUE_OK;
		printf("Okay, Valid Address.\n");
	}
	return (My_Queue);

}
queue_status_t EnqueueElement (Queue_t *queue_obj, void *Item_ptr)
{
	queue_status_t status = QUEUE_NOK;

	if((NULL == queue_obj) || (NULL == Item_ptr))
	{
		status = QUEUE_NOK;
		printf("Erorr!! This Is Invalid Address, Please Enter Valid Address.\n");
	}
	else
	{
		/*Valdite The Queue Is Not Full */
		if(queue_obj->QueueMaxSize == queue_obj->ElementCount)
		{
			status = QUEUE_FULL;
			printf("Queue Is Full!!\n");
		}
		else
		{
			/* increment queue reae index */
			(queue_obj->QueueRear)++;
			/* queue wraps to element 0 */
			if(queue_obj->QueueRear == queue_obj->QueueMaxSize)
			{
				queue_obj->QueueRear = 0;
			}
			/* insert the input data in to the rear position */
			queue_obj->QueueArray[queue_obj->QueueRear] = Item_ptr;
			if(queue_obj->ElementCount == 0)
			{
				queue_obj->ElementCount = 1;
				queue_obj->QueueFront = 0;

			}
			else
			{
				(queue_obj->ElementCount)++;
			}

			status = QUEUE_OK;
			printf("Okay, Valid Address.\n");
		}
	}
	return (status);

}
void *DqueueElement (Queue_t *queue_obj, queue_status_t *ret_status)
{
	*ret_status = QUEUE_NOK;
	void * Return_Value = NULL;

        if((NULL == queue_obj) || (NULL == ret_status))
        {
                *ret_status = QUEUE_NOK;
                printf("Erorr!! This Is Invalid Address, Please Enter Valid Address.\n");
        }
        else
        {	/* check if the queue is empty */
		if(!queue_obj->ElementCount)
		{
			Return_Value = NULL;
			*ret_status = QUEUE_EMPTY; /* queue is empty */
		}
		else
		{
			/* queue is not empty */
			Return_Value = queue_obj->QueueArray[queue_obj->QueueFront];
			/* increment queue front index */
			(queue_obj->QueueFront)++;
			/* queue front has wrapped to element 0 (Circular Queue) */
			if(queue_obj->QueueFront == queue_obj->QueueMaxSize)
			{
				queue_obj->QueueFront = 0;
			}
			else{/* Nothing */}
			if(1 == queue_obj->ElementCount)
			{
				queue_obj->QueueFront = -1; /* queue is empty */
				queue_obj->QueueRear = -1; /* queue is empty */
			}
			else{/* Nothing */}
			(queue_obj->ElementCount)--;
			*ret_status = QUEUE_OK;
		}
		
		printf("Okay, Valid Address.\n");

        }


	return (Return_Value);
}
void *QueueFront (Queue_t *queue_obj, queue_status_t *ret_status)
{
	void * Return_Value = NULL;

        if((NULL == queue_obj) || (NULL == ret_status))
        {
               *ret_status = QUEUE_NULL_POINTER;
                printf("Erorr!! This Is Invalid Address, Please Enter Valid Address.\n");
        }
        else
        {
		/* check if the queue is empty */
                if(!queue_obj->ElementCount)
                {
                        Return_Value = NULL;
                        *ret_status = QUEUE_EMPTY; /* queue is empty */
                }
                else /* queue is not empty */
                {
			Return_Value = queue_obj->QueueArray[queue_obj->QueueFront];
                	*ret_status = QUEUE_OK;
		}
                printf("Okay, Valid Address.\n");
        }
        return (Return_Value);

}
void *QueueRear (Queue_t *queue_obj, queue_status_t *ret_status)
{
        void * Return_Value = NULL;

        if((NULL == queue_obj) || (NULL == ret_status))
        {
               *ret_status = QUEUE_NULL_POINTER;
                printf("Erorr!! This Is Invalid Address, Please Enter Valid Address.\n");
        }
        else
        {
                /* check if the queue is empty */
                if(!queue_obj->ElementCount)
                {
                        Return_Value = NULL;
                        *ret_status = QUEUE_EMPTY; /* queue is empty */
                }
                else /* queue is not empty */
                {
                        Return_Value = queue_obj->QueueArray[queue_obj->QueueRear];
                        *ret_status = QUEUE_OK;
                }
                printf("Okay, Valid Address.\n");
        }
        return (Return_Value);


}
queue_status_t GetQueueCount (Queue_t *queue_obj, uint32 *QueueCount)
{
	 queue_status_t status = QUEUE_NOK;

        if((NULL == queue_obj) || (NULL == QueueCount))
        {
                status = QUEUE_NOK;
                printf("Erorr!! This Is Invalid Address, Please Enter Valid Address.\n");
        }
        else
        {
		/* check if the queue is empty */
                if(!queue_obj->ElementCount)
                {
                        status = QUEUE_EMPTY;
                        *QueueCount = 0; /* queue is empty */
                }
                else /* queue is not empty */
                {
                       
                       *QueueCount = queue_obj->ElementCount;
		       status = QUEUE_OK;
                }

                printf("Okay, Valid Address.\n");

        }
        return (status);

}
queue_status_t DestroyQueue (Queue_t *queue_obj)
{
	 queue_status_t status = QUEUE_NOK;

        if(NULL == queue_obj)
        {
                status = QUEUE_NULL_POINTER;
                printf("Erorr!! This Is Invalid Address, Please Enter Valid Address.\n");
        }
        else
        {
		free(queue_obj->QueueArray);
		free(queue_obj);
                status = QUEUE_OK;
                printf("Okay, Queue Destroed.\n");
        }
        return (status);

}

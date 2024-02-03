#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "QueueArray.h"

Queue_t *CreatQueue (uint32 max_size, queue_status_t *ret_status)
{
	Queue_t* My_Queue = NULL;
	
	My_Queue = (Queue_t *)malloc(sizeof(Queue_t));
	if((NULL == ret_status) || (NULL == My_Queue))
	{
		*ret_status = QUEUE_NOK;
		printf("Erorr!! This Is Invalid Adress, Please Enter Valid Adress.\n");
	}
	else
	{
		My_Queue->QueueArray = (void **) calloc (void *);
		*ret_status = QUEUE_OK;
		printf("Okay, Valid Adress.\n");
	}
	return (My_Queue);

}
queue_status_t EnqueueElement (Queue_t *queue_obj, void *Item_ptr)
{
	queue_status_t status = QUEUE_NOK;

	if((NULL == queue_obj) || (NULL == Item_ptr))
	{
		status = QUEUE_NOK;
		printf("Erorr!! This Is Invalid Adress, Please Enter Valid Adress.\n");
	}
	else
	{
		status = QUEUE_OK;
		printf("Okay, Valid Adress.\n");
	}
	return (status);

}
void *DqueueElement (Queue_t *queue_obj, queue_status_t *ret_status)
{
	 queue_status_t status = QUEUE_NOK;

        if((NULL == queue_obj) || (NULL == ret_status))
        {
                status = QUEUE_NOK;
                printf("Erorr!! This Is Invalid Adress, Please Enter Valid Adress.\n");
        }
        else
        {
                status = QUEUE_OK;
                printf("Okay, Valid Adress.\n");
        }



}
void *QueueFront (Queue_t *queue_obj, queue_status_t *ret_status)
{
	queue_status_t status = QUEUE_NOK;

        if((NULL == queue_obj) || (NULL == ret_status))
        {
                status = QUEUE_NOK;
                printf("Erorr!! This Is Invalid Adress, Please Enter Valid Adress.\n");
        }
        else
        {
                status = QUEUE_OK;
                printf("Okay, Valid Adress.\n");
        }
        

}
void *QueueRear (Queue_t *queue_obj, queue_status_t *ret_status)
{
	 queue_status_t status = QUEUE_NOK;

        if((NULL == queue_obj) || (NULL == ret_status))
        {
                status = QUEUE_NOK;
                printf("Erorr!! This Is Invalid Adress, Please Enter Valid Adress.\n");
        }
        else
        {
                status = QUEUE_OK;
                printf("Okay, Valid Adress.\n");
        }
        

}
queue_status_t GetQueueCount (Queue_t *queue_obj, uint32 *QueueCount)
{
	 queue_status_t status = QUEUE_NOK;

        if((NULL == queue_obj) || (NULL == QueueCount))
        {
                status = QUEUE_NOK;
                printf("Erorr!! This Is Invalid Adress, Please Enter Valid Adress.\n");
        }
        else
        {
                status = QUEUE_OK;
                printf("Okay, Valid Adress.\n");
        }
        return (status);

}
queue_status_t DestroyQueue (Queue_t *queue_obj)
{
	 queue_status_t status = QUEUE_NOK;

        if(NULL == queue_obj)
        {
                status = QUEUE_NOK;
                printf("Erorr!! This Is Invalid Adress, Please Enter Valid Adress.\n");
        }
        else
        {
                status = QUEUE_OK;
                printf("Okay, Valid Adress.\n");
        }
        return (status);

}

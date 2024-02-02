#include <stddef.h>
#include "Stack_DS_Array.h"

static uint8 StackIsFull (stack_t* stack_obj);
static uint8 StackIsEmpty (stack_t* stack_obj);
/**
 * CreatStack - This algorithm creats an empty stack by allocating in the head,
 *		structure and the array from the dynamic memory.
 * @MaxSize: Stack maximum number of elements
 *
 * @ret_status: Status returned while performing this opretion
 *
 * Return: Pointer to the allocated stack in the heap
*/
stack_t* CreatStack (uint32 MaxSize, StackStatus_t *ret_status)
{
	stack_t *my_pointer = NULL;

	if(NULL == ret_status)
	{
		*ret_status = Stack_Null_Pointer;
		my_pointer = NULL;

	}
	else
	{
		my_pointer = (stack_t *) malloc (sizeof(stack_t));
		if(!my_pointer)
		{
			*ret_status = Stack_NOK;
			my_pointer = NULL;
		}
		else
		{
			my_pointer->StackTop = -1;
			my_pointer->ElementCounter = 0;
			my_pointer->StackMaxSize = MaxSize;
			my_pointer->StackArray = (void **)calloc(my_pointer->StackMaxSize, sizeof(void *));
			if(!my_pointer->StackArray)
			{
				free (my_pointer);
				*ret_status = Stack_NOK;
				my_pointer = NULL;
			}
			else
			{
				*ret_status = Stack_OK;
			}

		}
	}
	return (my_pointer);

}
/**
 * DestroyStack -
 *
 * @stack_obj:
 *
 * @ret_status: Status returned while performing this opretion
 *
 * Return:
*/
stack_t* DestroyStack (stack_t* stack_obj, StackStatus_t *ret_status)
{
	if((NULL == ret_status) || (NULL == stack_obj))
        {
                *ret_status = Stack_Null_Pointer;
        }
        else
        {
		free(stack_obj->StackArray);
		free(stack_obj);
		*ret_status = Stack_OK;

        }
	return (NULL);

}
/**
 * PushStack -
 *
 * @stack_obj:
 *
 * @ItemPtr:
 *
 * Return:
*/
StackStatus_t PushStack (stack_t* stack_obj, void* ItemPtr)
{
	StackStatus_t StackStatus = Stack_NOK;

	if((NULL == stack_obj) || (NULL == ItemPtr))
        {
		StackStatus = Stack_Null_Pointer;
        }
        else
        {
		if(StackIsFull(stack_obj))
		{
			StackStatus = Stack_Full;
		}
		else
		{
			(stack_obj->StackTop)++;
			stack_obj->StackArray[stack_obj->StackTop] = ItemPtr;
			(stack_obj->ElementCounter)++;
		}
		StackStatus = Stack_OK;

        }
	return (StackStatus);

}
/**
 * PopStack -
 *
 * @stack_obj:
 *
 * @ret_status:
 *
 * Return:
*/
void* PopStack (stack_t* stack_obj, StackStatus_t *ret_status)
{
	void* data_ptr_out = NULL;

	if((NULL == stack_obj) || (NULL == ret_status))
        {
                *ret_status = Stack_Null_Pointer;
		data_ptr_out = NULL;
	}
        else
        {
		if(StackIsEmpty(stack_obj))
		{
			*ret_status = Stack_Empty;
			data_ptr_out = NULL;
		}
		else
		{
			data_ptr_out = stack_obj->StackArray[stack_obj->StackTop];
			(stack_obj->StackTop)--;
			(stack_obj->ElementCounter)--;
			*ret_status = Stack_OK;
		}
        }
	return (data_ptr_out);
}
/**
 * StackTop -
 *
 * @stack_obj:
 *
 * @ret_status:
 *
 * Return:
*/
void* StackTop (stack_t* stack_obj, StackStatus_t *ret_status)
{
	void* data_ptr_out = NULL;

	if((NULL == stack_obj) || (NULL == ret_status))
        {
                *ret_status = Stack_Null_Pointer;
                data_ptr_out = NULL;
        }
        else
        {
                if(StackIsEmpty(stack_obj))
                {
                        *ret_status = Stack_Empty;
                        data_ptr_out = NULL;
                }
                else
                {
                        data_ptr_out = stack_obj->StackArray[stack_obj->StackTop];
                        *ret_status = Stack_OK;
                }
        }
        return (data_ptr_out);

}
/**
 * StackCount -
 *
 * @stack_obj:
 *
 * @stack_count:
 *
 * Return:
*/
StackStatus_t StackCount (stack_t* stack_obj, uint32 *stack_count)
{
	StackStatus_t StackStatus = Stack_NOK;

        if((NULL == stack_obj) || (NULL == stack_count))
        {
                StackStatus = Stack_Null_Pointer;
        }
        else
        {
		*stack_count = stack_obj->ElementCounter;
                StackStatus = Stack_OK;
        }
        return (StackStatus);

}
/**
 * StackIsFull -
 *
 * @stack_obj:
 *
 * Return:
*/
static uint8 StackIsFull (stack_t* stack_obj)
{
	return (stack_obj->ElementCounter == stack_obj->StackMaxSize);
}
/**
 * StackIsEmpty -
 *
 * @stack_obj:
 *
 * Return:
*/
static uint8 StackIsEmpty (stack_t* stack_obj)
{
	return (stack_obj->ElementCounter == 0);
}


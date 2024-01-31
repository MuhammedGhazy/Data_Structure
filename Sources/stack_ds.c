#include "stack_ds.h"
#include <stddef.h>
#include <stdio.h>

/**
 * @brief - check stack is full
 *
 * @param - my_stack pointer to the stack
 *
 * @retval - status of the stack
*/


static stack_status_t stack_full (stack_ds_t *my_stack)
{
	if (my_stack->stack_pointer == STACK_MAX_SIZE - 1)
	{
		return (STACK_FULL);
	}
	else
	{
		return (STACK_NOT_FULL);
	}
}

/**
 * @brief - check stack is empty
 *
 * @param - my_stack pointer to the stack
 *
 * @retval - status of the stack
*/


static stack_status_t stack_empty (stack_ds_t *my_stack)
{
	if (my_stack->stack_pointer == -1)
	{
		return (STACK_EMPTY);
	}
	else
	{
		return (STACK_NOT_FULL);
	}
}


/**
 * @brief - initialize the stack pointer
 *
 * @param - my_stack pointer to the stack
 *
 * @retval - status of a initialization process
*/

return_status_t stack_init (stack_ds_t *my_stack)
{
	return_status_t ret = R_NOK;
	if (NULL == my_stack)
	{
		ret = R_NOK;
	}
	else
	{
		my_stack->stack_pointer = -1;
		ret = R_OK;
	}
	return (ret);
}
/**
 * @brief - 
 *
 * @param - my_stack pointer to the stack
 *
 * @retval - 
*/


return_status_t stack_push (stack_ds_t *my_stack, uint32 value)
{
	return_status_t ret = R_NOK;

	if((NULL == my_stack) || (STACK_FULL == stack_full(my_stack)))
	{
		#ifdef STACK_DEBUG
                printf("Erorr!! Stack Is Full, Can't Push Value (%i).\n", value);
                #endif // STACK_DEBUG

		ret = R_NOK;
	}
	else
	{
		my_stack->stack_pointer++;
		my_stack->data[my_stack->stack_pointer] = value;
		#ifdef STACK_DEBUG
		printf("Value (%i) Pushed To The Stack.\n", value);
		#endif // STACK_DEBUG
		ret = R_OK;
	}

	return (ret);
}

/**
 * @brief -
 *
 * @param - my_stack pointer to the stack
 *
 * @retval -
*/
return_status_t stack_pop (stack_ds_t *my_stack, uint32 *value)
{

}

/**
 * @brief -
 *
 * @param - my_stack pointer to the stack
 *
 * @retval -
*/
return_status_t stack_top (stack_ds_t *my_stack, uint32 *value)
{

}

/**
 * @brief -
 *
 * @param - my_stack pointer to the stack
 *
 * @retval -
*/
return_status_t stack_size (stack_ds_t *my_stack, uint32 *stack_size)
{

}

/**
 * @brief -
 *
 * @param - my_stack pointer to the stack
 *
 * @retval -
*/
return_status_t stack_display (stack_ds_t *my_stack)
{

}



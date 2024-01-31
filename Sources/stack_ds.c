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
 * @brief - add new elements to the stack
 *
 * @param - my_stack pointer to the stack
 *
 * @param - value elements to be add to the stack
 *
 * @retval - status of the stack_push 
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
 * @brief - get the last element pushed in the stack
 *
 * @param - my_stack pointer to the stack
 *
 * @param - value hold the top of the stack
 *
 * @retval - status of the stack_pop
*/
return_status_t stack_pop (stack_ds_t *my_stack, uint32 *value)
{
	return_status_t ret = R_NOK;
	
	if((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_empty(my_stack)))
	{
		#ifdef STACK_DEBUG
		printf("Erorr!! Stack Is Empty, Can't Pop Any Value.\n");
		#endif
		ret = R_NOK;
	}
	else
	{
		*value = my_stack->data[my_stack->stack_pointer];
		my_stack->stack_pointer--;
		#ifdef STACK_DEBUG
		printf("Value (%i) Popped From The Stack.\n", *value);
                #endif

		ret = R_OK;
	}

	return (ret);

}

/**
 * @brief - get the last element pushed in the stack
 *
 * @param - my_stack pointer to the stack
 *
 * @param - value hold the top of the stack
 *
 * @retval - status of the stack_top 
*/
return_status_t stack_top (stack_ds_t *my_stack, uint32 *value)
{
	return_status_t ret = R_NOK;

	if ((NULL == my_stack) || (NULL == value) || (STACK_EMPTY == stack_empty(my_stack)))
	{
		#ifdef STACK_DEBUG
                printf("Value (%i) Popped From The Stack.\n", *value);
                #endif


		ret = R_NOK;
	}
	else
	{
		*value = my_stack->data[my_stack->stack_pointer];
		#ifdef STACK_DEBUG
                printf("Stack Top Value = (%i).\n", my_stack->data[my_stack->stack_pointer]);
                #endif

		ret = R_OK;
	
	}


	return (ret);

}

/**
 * @brief - get the size of the stack -> number of elements
 *
 * @param - my_stack pointer to the stack
 *
 * @param - stack_size hold the size of the stack -> number of elements
 *
 * @retval - status of the stack_size
*/
return_status_t stack_size (stack_ds_t *my_stack, uint32 *stack_size)
{
	return_status_t ret = R_NOK;

	if (NULL == my_stack || NULL == stack_size)
	{
		ret = R_NOK;
	}
	else
	{
		*stack_size = my_stack->stack_pointer + 1;
		#ifdef STACK_DEBUG
		printf("Size Of The Stack Is (%i) Element.\n", my_stack->stack_pointer - 1);
		#endif
		ret = R_OK;
	}
	return (ret);

}

/**
 * @brief - dispaly elements at the stack
 *
 * @param - my_stack pointer to the stack
 *
 * @retval - status of the stack_display
*/
return_status_t stack_display (stack_ds_t *my_stack)
{
	return_status_t ret = R_NOK;
	sint32 l_counter = ZERO_INIT;

	if ((NULL == my_stack) || (STACK_EMPTY == stack_empty(my_stack)))
	{
		ret = R_NOK;
		#ifdef STACK_DEBUG
                printf("Erorr!! Stack Is Empty, Can't Display Any Value.\n");
                #endif
	}
	else
	{
		printf("Stack Data : ");
		for(l_counter = my_stack->stack_pointer; l_counter >= ZERO; l_counter--)
		{
			printf("%i\t", my_stack->data[l_counter]);
		}
	}	
	putchar('\n');
	ret = R_OK;
	return (ret);


}



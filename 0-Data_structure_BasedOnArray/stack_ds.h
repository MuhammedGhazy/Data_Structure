#ifndef STACK_DS_H
#define STACK_DS_H

#include "plat_form.h"
#include "std_types.h"
#define STACK_MAX_SIZE 5
typedef struct stack_ds
{
	uint32 stack_pointer;
	uint32 data[STACK_MAX_SIZE];
}stack_ds_t;

return_status_t stack_init (stack_ds_t *my_stack);

typedef enum stack_status
{
	STACK_EMPTY,
	STACK_FULL,
	STACK_NOT_FULL
}stack_status_t;

return_status_t stack_push (stack_ds_t *my_stack, uint32 value);
return_status_t stack_pop (stack_ds_t *my_stack, uint32 *value);
return_status_t stack_top (stack_ds_t *my_stack, uint32 *value);
return_status_t stack_size (stack_ds_t *my_stack, uint32 *stack_size);
return_status_t stack_display (stack_ds_t *my_stack);

#define STACK_DEBUG

#endif // STACK_DS_H

#ifndef STACK_DS_ARRAY_H
#define STACK_DS_ARRAY_H

#include <stdlib.h>
#include "plat_form.h"


typedef struct
{
        void **StackArray;     /* points to the array that allocated in the heap */
        sint32 ElementCounter; /* has the actual number of elements of the stack */
        uint32 StackMaxSize;   /* has the maximum number of elements of the stack */
        sint32 StackTop;       /* has the index of the top element of the stack */
}stack_t;

typedef enum
{
        Stack_NOK,         /* stack operation not performed successfully */
        Stack_OK,          /* stack operation performed successfully */
        Stack_Full,        /* stack is full */
        Stack_Empty,       /* stack is empty */
        Stack_Null_Pointer /* null pointer passed to the stack operation */
}StackStatus_t;

stack_t* CreatStack (uint32 MaxSize, StackStatus_t *ret_status);
stack_t* DestroyStack (stack_t* stack_obj, StackStatus_t *ret_status);
StackStatus_t PushStack (stack_t* stack_obj, void* ItemPtr);
void* PopStack (stack_t* stack_obj, StackStatus_t *ret_status);
void* StackTop (stack_t* stack_obj, StackStatus_t *ret_status);
StackStatus_t StackCount (stack_t* stack_obj, uint32 *stack_count);

#endif // STACK_DS_ARRAY_H

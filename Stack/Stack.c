#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Include header file of SingleLinkList
#include "Stack.h"

void main ()
{
    STACK * head1StackPtr = NULL;
    STACK * head2StackPtr = NULL;
    int data;

    push_in_stack(&head1StackPtr, 1);
    push_in_stack(&head1StackPtr, 2);
    push_in_stack(&head1StackPtr, 3);

    pop_from_stack(&head1StackPtr, &data);
    data = stack_size(head1StackPtr);
    printf(" data : %d\n", data);

    push_in_stack(&head2StackPtr, 91);
    push_in_stack(&head2StackPtr, 92);
    push_in_stack(&head2StackPtr, 93);

    swap_stack(&head2StackPtr, &head1StackPtr);

    print_stack(head1StackPtr);
    print_stack(head2StackPtr);

}

STACK * create_new_stock (int data)
{
    STACK * newStackPtr = (STACK *) calloc (1, sizeof(STACK));
    if(newStackPtr)
    {
        newStackPtr->data = data;
        newStackPtr->next = NULL;
    }
    return newStackPtr;
}

bool is_stack_empty (STACK * stackHeadPtr)
{
    return (stackHeadPtr) ? TRUE : FALSE;
}

unsigned int stack_size (STACK * stackHeadPtr)
{
    STACK * currentStackPtr = stackHeadPtr;
    int count = 0;
    while(currentStackPtr)
    {
        currentStackPtr = currentStackPtr->next;
        count += 1;
    }
    return count;
}

int top_from_stack (STACK * stackHeadPtr)
{
    return (stackHeadPtr) ? (stackHeadPtr->data) : (-1);
}

bool push_in_stack (STACK ** stackHeadPtr, int data)
{
    if(stackHeadPtr)
    {
        STACK * newStackPtr = create_new_stock(data);
        if(newStackPtr)
        {
            newStackPtr->next = (*stackHeadPtr);
            (*stackHeadPtr) = newStackPtr;
            return SUCCESS;
        }
        else
        {
            printf(" Memory allocation failed");
            return FAIL;
        }
    }
    else
    {
        return FAIL;
    }
}

bool pop_from_stack (STACK ** stackHeadPtr, int * poppedDataPtr)
{
    if(stackHeadPtr && *stackHeadPtr && poppedDataPtr)
    {

        STACK * tempStackPtr = (*stackHeadPtr);
        (*stackHeadPtr) = tempStackPtr->data;
        (*stackHeadPtr) = (*stackHeadPtr)->next;
        (*poppedDataPtr) = tempStackPtr->data;
        FREE_STACK(tempStackPtr);
        return SUCCESS;
    }
    else
    {
        return FAIL;
    }
}

bool swap_stack (STACK ** stackHeadPtr1, STACK ** stackHeadPtr2)
{
    if( (stackHeadPtr1 && *stackHeadPtr1) &&
        (stackHeadPtr2 && *stackHeadPtr2))
    {
        
        STACK * tempStackPtr = (*stackHeadPtr1);
        (*stackHeadPtr1) = (*stackHeadPtr2);
        (*stackHeadPtr2) = tempStackPtr;
        return SUCCESS;
    }
    else
    {
        return FAIL;
    }
}

void print_stack (STACK * stackHeadPtr)
{
    printf(" Stack : ");
    while(stackHeadPtr)
    {
        printf("%d-->", stackHeadPtr->data);
        stackHeadPtr = stackHeadPtr->next;
    }
    printf("NULL\n");
}

bool clear_stack (STACK ** stackHeadPtr)
{
    if(stackHeadPtr)
    {
        STACK * tempStackPtr = NULL;
        while(*stackHeadPtr)
        {
            tempStackPtr = (*stackHeadPtr);
            FREE_STACK(tempStackPtr);
            (*stackHeadPtr) = (*stackHeadPtr)->next;
        }
        return SUCCESS;
    }
    else
    {
        return FAIL;
    }
}

bool clear_stack_r (STACK ** stackHeadPtr)
{
    if(*stackHeadPtr)
    {
        clear_stack_r(&(*stackHeadPtr)->next);
        FREE_STACK(*stackHeadPtr);
        return SUCCESS;
    }
    else
    {
        return FAIL;
    }
}
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
    if(newStackPtr) {
        newStackPtr->data = data;
        newStackPtr->next = NULL;
    }
    return newStackPtr;
}

bool is_stack_empty (STACK * headStackPtr)
{
    return (headStackPtr) ? TRUE : FALSE;
}

unsigned int stack_size (STACK * headStackPtr)
{
    STACK * currentStackPtr = headStackPtr;
    int count = 0;
    while(currentStackPtr) {
        currentStackPtr = currentStackPtr->next;
        count += 1;
    }
    return count;
}

int top_from_stack (STACK * headStackPtr)
{
    return (headStackPtr) ? (headStackPtr->data) : (-1);
}

bool push_in_stack (STACK ** headStackPtr, int data)
{
    if(headStackPtr) {
        STACK * newStackPtr = create_new_stock(data);
        if(newStackPtr) {
            newStackPtr->next = (*headStackPtr);
            (*headStackPtr) = newStackPtr;
            return SUCCESS;
        }
        else {
            printf(" Memory allocation failed");
            return FAIL;
        }
    }
    else {
        return FAIL;
    }
}

bool pop_from_stack (STACK ** headStackPtr, int * poppedDataPtr)
{
    if(headStackPtr && *headStackPtr && *poppedDataPtr) {

        STACK * tempStackPtr = (*headStackPtr);
        (*headStackPtr) = tempStackPtr->data;
        (*headStackPtr) = (*headStackPtr)->next;
        (*poppedDataPtr) = tempStackPtr->data;
        FREE_STACK(tempStackPtr);
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

bool swap_stack (STACK ** headStackPtr1, STACK ** headStackPtr2)
{
    if( (headStackPtr1 && *headStackPtr1) &&
        (headStackPtr2 && *headStackPtr2)) {
        
        STACK * tempStackPtr = (*headStackPtr1);
        (*headStackPtr1) = (*headStackPtr2);
        (*headStackPtr2) = tempStackPtr;
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

void print_stack (STACK * headStackPtr)
{
    printf(" Stack : ");
    while(headStackPtr) {
        printf("%d-->", headStackPtr->data);
        headStackPtr = headStackPtr->next;
    }
    printf("NULL\n");
}
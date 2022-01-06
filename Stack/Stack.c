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

bool is_stack_empty (STACK * headPtr)
{
    return (headPtr) ? TRUE : FALSE;
}

unsigned int stack_size (STACK * headPtr)
{
    STACK * currentStackPtr = headPtr;
    int count = 0;
    while(currentStackPtr) {
        currentStackPtr = currentStackPtr->next;
        count += 1;
    }
    return count;
}

int top_from_stack (STACK * headPtr)
{
    return (headPtr) ? (headPtr->data) : (-1);
}

bool push_in_stack (STACK ** headPtr, int data)
{
    if(headPtr) {
        STACK * newStackPtr = create_new_stock(data);
        if(newStackPtr) {
            newStackPtr->next = (*headPtr);
            (*headPtr) = newStackPtr;
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

bool pop_from_stack (STACK ** headPtr, int * poppedDataPtr)
{
    if(headPtr && *headPtr && *poppedDataPtr) {

        STACK * tempStackPtr = (*headPtr);
        (*poppedDataPtr) = tempStackPtr->data;
        (*headPtr) = (*headPtr)->next;
        FREE_STACK(tempStackPtr);
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

bool swap_stack (STACK ** ptr1, STACK ** ptr2)
{
    if((ptr1 && *ptr1) && (ptr2 && *ptr2)) {
        STACK * tempStackPtr = (*ptr1);
        (*ptr1) = (*ptr2);
        (*ptr2) = tempStackPtr;
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

void print_stack (STACK * headPtr)
{
    printf(" Stack : ");
    while(headPtr) {
        printf("%d-->", headPtr->data);
        headPtr = headPtr->next;
    }
    printf("NULL\n");
}
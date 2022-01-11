#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "StackUsingQueue.h"

void main (void)
{
    STACK * headPtr = NULL;
	
	push(&headPtr, 2);
	push(&headPtr, 3);
	print_stack(headPtr);
	push(&headPtr, 4);
	push(&headPtr, 6);
	print_stack(headPtr);
	pop(&headPtr);
	push(&headPtr,10);
	print_stack(headPtr);
}

STACK * create_stack (int data)
{
    STACK * newStackPtr = (STACK *) calloc(1, sizeof(STACK));
    if(newStackPtr) {
        newStackPtr->data = data;
        newStackPtr->next = NULL;
    }
    return newStackPtr;
}

bool enqueue (STACK ** headPtr, STACK * newStackPtr)
{
    if(headPtr && newStackPtr) {
        newStackPtr->next = NULL;
        if(NULL == (*headPtr)) {
            (*headPtr) = newStackPtr;
        }
        else {
            STACK * currentStackPtr = *headPtr;
            while(currentStackPtr->next) {
                currentStackPtr = currentStackPtr->next;
            }
            currentStackPtr->next = newStackPtr;
        }
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

STACK * dequeue (STACK ** stackHeadPtr)
{
    if(stackHeadPtr && (*stackHeadPtr)) {
        STACK * tempStackPtr = (*stackHeadPtr);
        (*stackHeadPtr) = (*stackHeadPtr)->next;
        return tempStackPtr;
    }
    else {
        return NULL;
    }
}

bool push (STACK ** firstQueuePtr, int data)
{
    if(firstQueuePtr) {
        STACK * newStackPtr = create_stack(data);
        if(newStackPtr){

            STACK * secondQueuePtr = NULL;

            while(enqueue(&secondQueuePtr, dequeue(firstQueuePtr)));   

            enqueue(firstQueuePtr, newStackPtr);

            while(enqueue(firstQueuePtr, dequeue(&secondQueuePtr)));

            return SUCCESS;
        }
        else {
            printf(" Memory Allocation Failed\n");
            return FAIL;
        }
    }
    else {
        return FAIL;
    }
}

int pop (STACK ** headPtr)
{
    int data = 0;
    if(headPtr) {
        STACK * tmpPtr = DeQueue(headPtr);
        if(tmpPtr) {
            data = tmpPtr->data;
            FREE_STACK(tmpPtr);
            free(tmpPtr);
            tmpPtr = NULL;
        }
    }
    return data;
}

void print_stack (STACK * stackHeadPtr)
{
    printf(" Stack : ");
    while (stackHeadPtr) {
        printf("%d ", stackHeadPtr->data);
        stackHeadPtr = stackHeadPtr->next;
    }
    printf("NULL\n");
}

bool clear_stack (STACK ** stackHeadPtr)
{
    if(stackHeadPtr) {

        STACK * tempStackPtr = NULL;
        while(*stackHeadPtr) {
            tempStackPtr = (*stackHeadPtr);
            FREE_STACK(tempStackPtr);
            (*stackHeadPtr) = (*stackHeadPtr)->next;
        }
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

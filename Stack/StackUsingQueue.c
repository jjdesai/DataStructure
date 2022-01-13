#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "StackUsingQueue.h"

void main (void)
{
    STACK * queueHeadPtr = NULL;

    push(&queueHeadPtr, 10);
    push(&queueHeadPtr, 20);
    push(&queueHeadPtr, 30);
    push(&queueHeadPtr, 40);

    print_stack(queueHeadPtr);
    pop(&queueHeadPtr);
    pop(&queueHeadPtr);
    print_stack(queueHeadPtr);

    clear_stack_r(&queueHeadPtr);
    print_stack(queueHeadPtr);
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

bool enqueue (STACK ** stackHeadPtr, STACK * newStackPtr)
{
    if(stackHeadPtr && newStackPtr) {
        newStackPtr->next = NULL;
        if(NULL == (*stackHeadPtr)) {
            (*stackHeadPtr) = newStackPtr;
        }
        else {
            STACK * currentStackPtr = *stackHeadPtr;
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

bool push (STACK ** stackHeadPtr, int data)
{
    if(stackHeadPtr) {
        STACK * newStackPtr = create_stack(data);
        if(newStackPtr){

            STACK * dummyQueuePtr = NULL;

            while(enqueue(&dummyQueuePtr, dequeue(stackHeadPtr)));   

            enqueue(stackHeadPtr, newStackPtr);

            while(enqueue(stackHeadPtr, dequeue(&dummyQueuePtr)));

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

int pop (STACK ** stackHeadPtr)
{
    int data = 0;
    if(stackHeadPtr) {
        STACK * tmpPtr = dequeue(stackHeadPtr);
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

bool clear_stack_r (STACK ** stackHeadPtr)
{
    if(*stackHeadPtr) {
        clear_stack_r(&(*stackHeadPtr)->next);
        FREE_STACK(*stackHeadPtr);
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}
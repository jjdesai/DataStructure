#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "QueueUsingStack.h"

void main (void)
{
    QUEUE * queueHeadPtr = NULL;

    enqueue(&queueHeadPtr, 10);
    enqueue(&queueHeadPtr, 20);
    enqueue(&queueHeadPtr, 30);
    enqueue(&queueHeadPtr, 40);

    print_queue(queueHeadPtr);
    dequeue(&queueHeadPtr);
    dequeue(&queueHeadPtr);
    print_queue(queueHeadPtr);

    clear_queue_r(&queueHeadPtr);
    print_queue(queueHeadPtr);
}

QUEUE * create_queue (int data)
{
    QUEUE * newQueuePtr = calloc(1, sizeof(QUEUE));
    if(newQueuePtr) {
        newQueuePtr->data = data;
        newQueuePtr->next = NULL;
    }
    return newQueuePtr;
}

bool push (QUEUE ** queueHeadPtr, QUEUE * newQueuePtr)
{
    if(newQueuePtr) {
        newQueuePtr->next = (*queueHeadPtr);
        (*queueHeadPtr) = newQueuePtr;
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

QUEUE * pop (QUEUE ** queueHeadPtr)
{
    QUEUE * popPtr = NULL;
    if(*queueHeadPtr) {
        popPtr = *queueHeadPtr;
        (*queueHeadPtr) = (*queueHeadPtr)->next;
    }
    return popPtr;
}

bool enqueue (QUEUE ** queueHeadPtr, int data)
{
    if(queueHeadPtr) {
        QUEUE * newQueuePtr = create_queue(data);
        if(newQueuePtr) {

            QUEUE * dummyStackPtr = NULL;

            while(push(&dummyStackPtr, pop(queueHeadPtr)));

            push(queueHeadPtr, newQueuePtr);

            while(push(queueHeadPtr, pop(&dummyStackPtr)));

            return SUCCESS;
        }
        else {
            printf(" Memory allocation failed \n");
            return FAIL;
        }
    }
    else {
        return FAIL;
    }
}

int dequeue (QUEUE ** queueHeadPtr)
{
    if(queueHeadPtr) {
        QUEUE * poppedQueuePtr = pop(queueHeadPtr);
        int ret_data = poppedQueuePtr->data;
        FREE_QUEUE(poppedQueuePtr);
        return ret_data;
    }
    else {
        return -1;
    }
}

void print_queue (QUEUE * queueHeadPtr)
{
    printf(" Queue : ");
    while (queueHeadPtr) {
        printf("%d ", queueHeadPtr->data);
        queueHeadPtr = queueHeadPtr->next;
    }
    printf("NULL\n");
}

bool clear_queue (QUEUE ** queueHeadPtr)
{
    if(queueHeadPtr) {

        QUEUE * tempQueuePtr = NULL;
        while(*queueHeadPtr) {
            tempQueuePtr = (*queueHeadPtr);
            FREE_QUEUE(tempQueuePtr);
            (*queueHeadPtr) = (*queueHeadPtr)->next;
        }
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

bool clear_queue_r (QUEUE ** queueHeadPtr)
{
    if(*queueHeadPtr) {
        clear_queue_r(&(*queueHeadPtr)->next);
        FREE_QUEUE(*queueHeadPtr);
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}
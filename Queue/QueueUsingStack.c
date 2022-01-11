#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "QueueUsingStack.h"

void main (void)
{

}

void print_stack (QUEUE * queueHeadPtr)
{
    printf(" Queue : ");
    while (queueHeadPtr) {
        printf("%d ", queueHeadPtr->data);
        queueHeadPtr = queueHeadPtr->next;
    }
    printf("NULL\n");
}

bool clear_stack (QUEUE ** queueHeadPtr)
{
    if(queueHeadPtr) {

        QUEUE * tempQueuePtr = NULL;
        while(*queueHeadPtr) {
            tempQueuePtr = (*queueHeadPtr);
            FREE_STACK(tempQueuePtr);
            (*queueHeadPtr) = (*queueHeadPtr)->next;
        }
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}
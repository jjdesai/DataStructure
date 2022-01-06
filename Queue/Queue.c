#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "Queue.h"

void main (void)
{

}

QUEUE * create_new_queue (int data)
{
    QUEUE * newQueueNodePtr = calloc(1, sizeof(QUEUE));
    if(newQueueNodePtr) {
        newQueueNodePtr->data = data;
        newQueueNodePtr->next = NULL;
    }
    return newQueueNodePtr;
}

bool insert_in_queue (QUEUE ** headQueuePtr, int data)
{
    if(headQueuePtr) {
        QUEUE * newQueueNodePtr = create_new_queue(data);
        if (newQueueNodePtr) {

            if(*headQueuePtr) {
                QUEUE * currentNodePtr = *headQueuePtr;
                while(currentNodePtr->next)
                    currentNodePtr = currentNodePtr->next;
                //newQueueNodePtr->next = currentNodePtr->next; we've already initialize newNodePtr->next with NULL so repeatation is not required
                currentNodePtr->next = newQueueNodePtr;
            }
            else {
                (*headQueuePtr) = newQueueNodePtr;
            }
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

int remove_from_queue (QUEUE ** headQueuePtr)
{
    int ret_data = 0;
    if(*headQueuePtr) {
        QUEUE * tempQueuePtr = *headQueuePtr;
        (*headQueuePtr) = (*headQueuePtr)->next;
        ret_data = tempQueuePtr->data;
        FREE_QUEUE(tempQueuePtr);
    }
    return ret_data;
}

int access_front (QUEUE * headQueuePtr)
{
    return (headQueuePtr) ? headQueuePtr->data : 0;
}

int access_back (QUEUE * headQueuePtr)
{
    if(headQueuePtr) {
        while(headQueuePtr->next)
            headQueuePtr = headQueuePtr->next;
        return headQueuePtr->data;
    }
    else {
        return 0;
    }
}

bool is_queue_empty (QUEUE * headQueuePtr)
{
    return (headQueuePtr) ? NO : YES;
}

unsigned int size_of_queue (QUEUE * headQueuePtr)
{
    QUEUE * currentQueuePtr = headQueuePtr;
    int count = 0;
    while(currentQueuePtr) {
        currentQueuePtr = currentQueuePtr->next;
        count += 1;
    }
    return count;
}

bool swap_queues (QUEUE ** headQueuePtr1, QUEUE ** headQueuePtr2)
{
    if( (headQueuePtr1 && *headQueuePtr1) &&
        (headQueuePtr2 && *headQueuePtr2)) {
        
        QUEUE * tempQueuePtr = (*headQueuePtr1);
        (*headQueuePtr1) = (*headQueuePtr2);
        (*headQueuePtr2) = tempQueuePtr;
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

void print_queue (QUEUE * headQueuePtr)
{
    printf(" Queue : ");
    while(headQueuePtr) {
        printf("%d-->", headQueuePtr->data);
        headQueuePtr = headQueuePtr->next;
    }
    printf("NULL\n");
}
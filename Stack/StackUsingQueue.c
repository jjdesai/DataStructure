#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "StackUsingQueue.h"

void main (void)
{
    STACK * headPtr = NULL;
	
	Push(&headPtr, 2);
	Push(&headPtr, 3);
	PrintStack(headPtr);
	Push(&headPtr, 4);
	Push(&headPtr, 6);
	PrintStack(headPtr);
	Pop(&headPtr);
	Push(&headPtr,10);
	PrintStack(headPtr);
    
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

bool EnQueue (STACK ** headPtr, STACK * newStackPtr)
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

STACK * DeQueue (STACK ** stackHeadPtr)
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

bool Push (STACK ** firstQueuePtr, int data)
{
    if(firstQueuePtr) {
        STACK * newStackPtr = create_stack(data);
        if(newStackPtr){

            STACK * secondQueuePtr = NULL;

            while(EnQueue(&secondQueuePtr, DeQueue(firstQueuePtr)));   

            EnQueue(firstQueuePtr, newStackPtr);

            while(EnQueue(firstQueuePtr, DeQueue(&secondQueuePtr)));

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

int Pop (STACK ** headPtr)
{
    int data = 0;
    if(headPtr) {
        STACK * tmpPtr = DeQueue(headPtr);
        if(tmpPtr) {
            data = tmpPtr->data;
            free(tmpPtr);
            tmpPtr = NULL;
        }
    }
    return data;
}

void PrintStack (STACK * stackHeadPtr)
{
    printf(" Stack : ");
    while (stackHeadPtr) {
        printf("%d ", stackHeadPtr->data);
        stackHeadPtr = stackHeadPtr->next;
    }
    printf("NULL\n");
    
}

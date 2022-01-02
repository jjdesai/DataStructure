#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Include header file of SingleLinkList
#include "SingleLinkList.h"

void main()
{
    SINGLE_LINK * headPtr = NULL;
    
    add_single_link_at_last(&headPtr, 10);
    add_single_link_at_last(&headPtr, 20);
    add_single_link_at_last(&headPtr, 30);
    add_single_link_at_last(&headPtr, 40);

    print_single_link_list(headPtr);

    delete_single_link_list(&headPtr);

    print_single_link_list(headPtr);

}

SINGLE_LINK * create_new_node (int data)
{
    SINGLE_LINK * newNodePtr = (SINGLE_LINK *) calloc(1, sizeof(SINGLE_LINK));
    if(newNodePtr) {
        newNodePtr->data = data;
        newNodePtr->next = NULL;
    }
    return newNodePtr;
}

bool add_single_link_at_last (SINGLE_LINK ** headPtr, int data)
{
    bool ret_val = FAIL;
    if (headPtr) {

        SINGLE_LINK * newNodePtr = create_new_node(data);
        if (!newNodePtr) {
            printf(" Memory allocation fail \n");
            return FAIL;
        }
        
        if (NULL == *headPtr) {
            *headPtr = newNodePtr;
        }
        else {
            SINGLE_LINK * currentNodePtr = *headPtr;
            while(currentNodePtr->next)
                currentNodePtr = currentNodePtr->next;
            currentNodePtr->next = newNodePtr;
        }
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

void print_single_link_with_data (SINGLE_LINK * headPtr)
{
    SINGLE_LINK * currentNodePtr = headPtr;
    printf(" Single Link List (data) : ");
    while(currentNodePtr)
    {
        printf("%d-->", currentNodePtr->data);
        currentNodePtr = currentNodePtr->next;
    }
    printf("NULL\n");
    print_single_link_with_addr(headPtr);
}

void print_single_link_with_addr (SINGLE_LINK * headPtr)
{
    SINGLE_LINK * currentNodePtr = headPtr;
    printf(" Single Link List (Addr) : ");
    while(currentNodePtr)
    {
        printf("%.3p-->", (void *) currentNodePtr);
        currentNodePtr = currentNodePtr->next;
    }
    printf("NULL\n");
}

void print_single_link_list (SINGLE_LINK * headPtr)
{
    SINGLE_LINK * currentNodePtr = headPtr;
    print_single_link_with_data(currentNodePtr);
}

bool delete_single_link_list (SINGLE_LINK ** headPtr)
{
    if(*headPtr) {
        SINGLE_LINK * currentNodePtr;
        while(*headPtr)
        {
            currentNodePtr = *headPtr;
            (*headPtr) = (*headPtr)->next;
            free(currentNodePtr);
            currentNodePtr = NULL;
        }
        return SUCCESS;
    }
    else {
        printf(" HeadPtr is empty\n");
        return FAIL;
    }
}
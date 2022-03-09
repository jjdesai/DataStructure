#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Include header file of DoubleLinkList
#include "DoubleLinkList.h"

static DOUBLE_LINK * create_new_node (int data);

void main()
{
    DOUBLE_LINK * headPtr = NULL;

    add_double_link_at_last(&headPtr, 1);     // 1 -> NULL
    add_double_link_at_last(&headPtr, 10);    // 1 <-> 10 -> NULL
    add_double_link_at_last(&headPtr, 20);    // 1 <-> 10 <-> 20 -> NULL
    add_double_link_at_last(&headPtr, 30);    // 1 <-> 10 <-> 20 <-> 30 -> NULL
    add_double_link_at_last(&headPtr, 40);    // 1 <-> 10 <-> 20 <-> 30 <-> 40 -> NULL
    add_double_link_at_last(&headPtr, 50);    // 1 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 -> NULL
    add_double_link_at_last(&headPtr, 60);    // 1 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> 60 -> NULL
    add_double_link_at_last(&headPtr, 70);    // 1 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> 60 -> 70 -> NULL

    print_double_link_list(headPtr);

    delete_double_link_list(&headPtr);
}

// Working
static DOUBLE_LINK * create_new_node (int data)
{
    DOUBLE_LINK * newNodePtr = (DOUBLE_LINK *) calloc(1, sizeof(DOUBLE_LINK));
    if(newNodePtr)
    {
        newNodePtr->prev = NULL;
        newNodePtr->data = data;
        newNodePtr->next = NULL;
    }
    return newNodePtr;
}

// Working
bool add_double_link_at_last (DOUBLE_LINK ** headPtr, int data)
{
    if(headPtr)
    {
        DOUBLE_LINK * newNodePtr = create_new_node(data);
        if(newNodePtr)
        {
            if (is_double_link_empty(*headPtr))
            {
                *headPtr = newNodePtr;
            }
            else
            {
                DOUBLE_LINK * currentNodePtr = *headPtr;
                while(currentNodePtr->next)
                    currentNodePtr = currentNodePtr->next;
                newNodePtr->prev = currentNodePtr;
                currentNodePtr->next = newNodePtr;
            }
            return SUCCESS;
        }
        else
        {
            printf(" Memory allocation failed\n");
            return FAIL;
        }
    }
    else
    {
        printf(" NULL HeadPtr found");
        return FAIL;
    }
}

// Working
bool is_double_link_empty (DOUBLE_LINK * headPtr)
{
    return (headPtr) ? NO : YES; 
}

// Working
void print_double_link_list (DOUBLE_LINK * headPtr)
{
    printf(" ---------\n");
    DOUBLE_LINK * last;
    printf(" Double Link List : ");
    while(headPtr)
    {
        last = headPtr;
        printf("%d-->", headPtr->data);
        headPtr = headPtr->next;
    }
    printf("NULL\n");

    printf(" DLL In   Reverse : ");
    while(last)
    {
        printf("%d-->", last->data);
        last = last->prev;
    }
    printf("NULL\n");
    printf(" ---------\n");
}

// Working
bool delete_double_link_list (DOUBLE_LINK ** headPtr)
{
    if ((headPtr) && (*headPtr)) {
        DOUBLE_LINK * currentNodePtr;
        while(*headPtr)
        {
            currentNodePtr = *headPtr;
            (*headPtr) = (*headPtr)->next;
            FREE_DOUBLE_LINK_NODE(currentNodePtr);
        }
        return SUCCESS;
    }
    else {
        printf(" HeadPtr is empty\n");
        return FAIL;
    }
}
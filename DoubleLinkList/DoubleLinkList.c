#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Include header file of DoubleLinkList
#include "DoubleLinkList.h"

static DOUBLE_LINK * create_new_node (int data);

void main()
{
    DOUBLE_LINK * headPtr = NULL;

    add_double_link_at_pos(&headPtr, 11, 1);    // 11 -> NULL
    add_double_link_at_pos(&headPtr, 10, 2);    // 11 -> 10 -> NULL
    add_double_link_at_pos(&headPtr, 20, 1);    // 20 -> 11 -> 10 -> NULL
    add_double_link_at_pos(&headPtr, 30, 2);    // 20 -> 30 -> 11 -> 10 -> NULL
    add_double_link_at_pos(&headPtr, 90, 3);    // 20 -> 30 -> 90 -> 11 -> 10 -> NULL
    add_double_link_at_pos(&headPtr, 55, 1);    // 55 -> 20 -> 30 -> 90 -> 11 -> 10 -> NULL
    add_double_link_at_pos(&headPtr, 77, 6);    // 55 -> 20 -> 30 -> 90 -> 11 -> 77-> 10 -> NULL
    add_double_link_at_pos(&headPtr, 88, 8);    // 55 -> 20 -> 30 -> 90 -> 11 -> 77-> 10 -> 88 -> NULL
    add_double_link_at_pos(&headPtr, 88000, 10);// 55 -> 20 -> 30 -> 90 -> 11 -> 77-> 10 -> 88 -> NULL

    // add_double_link_at_first(&headPtr, 1);     // 1 -> NULL
    // add_double_link_at_last(&headPtr, 10);    // 1 <-> 10 -> NULL
    // add_double_link_at_last(&headPtr, 20);    // 1 <-> 10 <-> 20 -> NULL
    // add_double_link_at_last(&headPtr, 30);    // 1 <-> 10 <-> 20 <-> 30 -> NULL
    // add_double_link_at_last(&headPtr, 40);    // 1 <-> 10 <-> 20 <-> 30 <-> 40 -> NULL
    // add_double_link_at_last(&headPtr, 50);    // 1 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 -> NULL
    // add_double_link_at_last(&headPtr, 60);    // 1 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> 60 -> NULL
    // add_double_link_at_last(&headPtr, 70);    // 1 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> 60 -> 70 -> NULL

    //add_double_link_at_first(&headPtr, 5);

    print_double_link_list(headPtr);

    reverse_double_link(&headPtr);
    printf(" After Reversing the Double Link List\n");
    print_double_link_list(headPtr);

    // delete_double_link_list(&headPtr);
    delete_double_link_list_r(&headPtr);
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
bool add_double_link_at_first (DOUBLE_LINK ** headPtr, int data)
{
    if(headPtr)
    {
        DOUBLE_LINK * newNodePtr = create_new_node(data);
        if(newNodePtr)
        {
            newNodePtr->next = (*headPtr);
            if (!is_double_link_empty(*headPtr))
                (*headPtr)->prev = newNodePtr;
            (*headPtr) = newNodePtr;
        }
        else
        {
            printf(" Memory allocation failed\n");
            return FAIL;
        }
    }
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
bool add_double_link_at_pos (DOUBLE_LINK ** headPtr, int data, unsigned int position)
{
    if(headPtr) {
        DOUBLE_LINK * newNodePtr = create_new_node(data);
        if(!newNodePtr) {
            printf(" Memory allocation fail \n");
            return FAIL;
        }
        else {
            if((1 == position) || is_double_link_empty(*headPtr))
            {
                newNodePtr->next = (*headPtr);
                if (!is_double_link_empty(*headPtr))
                    (*headPtr)->prev = newNodePtr;
                (*headPtr) = newNodePtr;
                return SUCCESS;
            }
            else
            {
                DOUBLE_LINK * currentNodePtr = (*headPtr);
                DOUBLE_LINK * prevOfCurrentNodePtr = NULL;

                position--;
                while (position && currentNodePtr)
                {
                    prevOfCurrentNodePtr = currentNodePtr;
                    currentNodePtr = currentNodePtr->next; 
                    position--;
                }

                if(0 == position) {
                    prevOfCurrentNodePtr->next = newNodePtr;
                    newNodePtr->prev = prevOfCurrentNodePtr;
                    newNodePtr->next = currentNodePtr;
                    if(currentNodePtr)
                        currentNodePtr->prev = newNodePtr;
                    return SUCCESS;
                }
                else {
                    FREE_DOUBLE_LINK_NODE(newNodePtr);
                    return FAIL;
                }
            }
        }
    }
    else {
        return FAIL;
    }
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

bool delete_double_link_list_r (DOUBLE_LINK ** headPtr)    // _r Indicate recursion
{
    if(headPtr) {
        while(*headPtr) {
            delete_double_link_list_r(&(*headPtr)->next);
            FREE_DOUBLE_LINK_NODE(*headPtr);
        }
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

// Working
bool reverse_double_link (DOUBLE_LINK ** headPtr)
{
    if(headPtr) {

        DOUBLE_LINK * prevNodePtr = NULL, * currentNodePtr = (*headPtr), * tmpNextNodePtr = NULL;
       
        while(currentNodePtr) {

            tmpNextNodePtr = currentNodePtr->next;
            currentNodePtr->prev = tmpNextNodePtr;
            currentNodePtr->next = prevNodePtr;
            prevNodePtr = currentNodePtr;
            currentNodePtr = tmpNextNodePtr;
        }
        (*headPtr) = prevNodePtr;
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

// Not Working
DOUBLE_LINK * reverse_double_link_r (DOUBLE_LINK ** headPtr, DOUBLE_LINK * nodePtr)
{
    if(headPtr) {  
        if(nodePtr == NULL) {
            return NULL;
        }
        // To Assign headPtr with last node, as we're making it as first
        if(nodePtr->next == NULL) {
            (*headPtr) = nodePtr;
            return nodePtr;
        }
        DOUBLE_LINK * nextNodePtr = reverse_double_link_r(headPtr, nodePtr->next);
        nextNodePtr->next = nodePtr;
        // To Assign NULL to first node's next, as we're making it as last
        nodePtr->next = NULL;
        return nodePtr;
    }
    else {
        return NULL;
    }
}

// Working
bool is_double_link_empty (DOUBLE_LINK * headPtr)
{
    return (headPtr) ? NO : YES; 
}

// Working
unsigned int size_of_double_link (DOUBLE_LINK * headPtr)
{
    unsigned int count = 0;
    while(headPtr) {
        headPtr = headPtr->next;
        count += 1;
    }
    return count;
}
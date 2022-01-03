#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Include header file of SingleLinkList
#include "SingleLinkList.h"

void main()
{
    SINGLE_LINK * headPtr = NULL;

    add_single_link_at_pos(&headPtr, 11, 1);    // 11 -> NULL
    add_single_link_at_pos(&headPtr, 10, 2);    // 11 -> 10 -> NULL
    add_single_link_at_pos(&headPtr, 20, 1);    // 20 -> 11 -> 10 -> NULL
    add_single_link_at_pos(&headPtr, 30, 2);    // 20 -> 30 -> 11 -> 10 -> NULL
    add_single_link_at_pos(&headPtr, 90, 3);    // 20 -> 30 -> 90 -> 11 -> 10 -> NULL
    add_single_link_at_pos(&headPtr, 55, 1);    // 55 -> 20 -> 30 -> 90 -> 11 -> 10 -> NULL
    add_single_link_at_pos(&headPtr, 77, 6);    // 55 -> 20 -> 30 -> 90 -> 11 -> 77-> 10 -> NULL
    add_single_link_at_pos(&headPtr, 88, 8);    // 55 -> 20 -> 30 -> 90 -> 11 -> 77-> 10 -> 88 -> NULL

    print_single_link_list(headPtr);

    delete_single_node(&headPtr, 55);
    print_single_link_list(headPtr);
    delete_single_node(&headPtr, 30);
    print_single_link_list(headPtr);
    delete_single_node(&headPtr, 88);
    print_single_link_list(headPtr);
    delete_single_node(&headPtr, 100);
    print_single_link_list(headPtr);
    delete_single_node(&headPtr, 10);

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
        else {
            if (NULL == *headPtr) {
                *headPtr = newNodePtr;
            }
            else {
                SINGLE_LINK * currentNodePtr = *headPtr;
                while(currentNodePtr->next)
                    currentNodePtr = currentNodePtr->next;
                //newNodePtr->next = currentNodePtr->next; we've already initialize newNodePtr->next with NULL so repeatation is not required
                currentNodePtr->next = newNodePtr;
            }
            return SUCCESS;
        }
    }
    else {
        return FAIL;
    }
}

bool add_single_link_at_first (SINGLE_LINK ** headPtr, int data)
{
    if(headPtr) {
        SINGLE_LINK * newNodePtr = create_new_node(data);
        if (!newNodePtr) {
            printf(" Memory allocation fail \n");
            return FAIL;
        }
        else {
            newNodePtr->next = (*headPtr);
            (*headPtr) = newNodePtr;
            return SUCCESS;
        }
    }
    else {
        return FAIL;
    }
}

/*  To Test below function

    add_single_link_at_pos(&headPtr, 11, 1);    // 11 -> NULL
    add_single_link_at_pos(&headPtr, 10, 2);    // 11 -> 10 -> NULL
    add_single_link_at_pos(&headPtr, 20, 1);    // 20 -> 11 -> 10 -> NULL
    add_single_link_at_pos(&headPtr, 30, 2);    // 20 -> 30 -> 11 -> 10 -> NULL
    add_single_link_at_pos(&headPtr, 90, 3);    // 20 -> 30 -> 90 -> 11 -> 10 -> NULL
    add_single_link_at_pos(&headPtr, 55, 1);    // 55 -> 20 -> 30 -> 90 -> 11 -> 10 -> NULL
    add_single_link_at_pos(&headPtr, 77, 6);    // 55 -> 20 -> 30 -> 90 -> 11 -> 77-> 10 -> NULL
    add_single_link_at_pos(&headPtr, 88, 8);    // 55 -> 20 -> 30 -> 90 -> 11 -> 77-> 10 -> 88 -> NULL
    add_single_link_at_pos(&headPtr, 88000, 10);// 55 -> 20 -> 30 -> 90 -> 11 -> 77-> 10 -> 88 -> NULL

    print_single_link_list(headPtr);
    delete_single_link_list(&headPtr);
*/
bool add_single_link_at_pos (SINGLE_LINK ** headPtr, int data, unsigned int position)
{
    if(headPtr) {
        SINGLE_LINK * newNodePtr = create_new_node(data);
        if(!newNodePtr) {
            printf(" Memory allocation fail \n");
            return FAIL;
        }
        else {
            if((1 == position) || (NULL == *headPtr))
            {
                newNodePtr->next = (* headPtr);
                (*headPtr) = newNodePtr;
                printf(" Added [%d]\n", newNodePtr->data);
                return SUCCESS;
            }
            else
            {
                SINGLE_LINK * currentNodePtr = (*headPtr);
                SINGLE_LINK * prevOfCurrentNodePtr = NULL;

                printf(" Before : Pos[%d] Data[%d]\n", position, data);

                position--;
                while (position && currentNodePtr)
                {
                    prevOfCurrentNodePtr = currentNodePtr;
                    currentNodePtr = currentNodePtr->next; 
                    position--;
                }
                printf(" After : Pos[%d]\n", position);

                if(0 == position) {
                    prevOfCurrentNodePtr->next = newNodePtr;
                    newNodePtr->next = currentNodePtr;
                    return SUCCESS;
                }
                else {
                    printf(" Deleted with Add [%d]\n", newNodePtr->data);
                    FREE(newNodePtr);
                    return FAIL;
                }
            }
        }
    }
    else {
        return FAIL;
    }

}

bool add_single_link_with_ascending (SINGLE_LINK ** heardPtr, int data)
{
    if(heardPtr) {
        SINGLE_LINK * newNodePtr = create_new_node(data);
        if(!newNodePtr) {
            printf(" Memory allocation fail \n");
            return FAIL;
        }

        if((NULL == *heardPtr) || ((*heardPtr)->data >= newNodePtr->data)) {
            newNodePtr->next = (*heardPtr);
            (*heardPtr) = newNodePtr;
        }
        else {
            SINGLE_LINK * currentNodePtr = (*heardPtr);
            while(currentNodePtr->next && (currentNodePtr->next->data < newNodePtr->data)) {
                currentNodePtr = currentNodePtr->next;
            }
            newNodePtr->next = currentNodePtr->next;
            currentNodePtr->next = newNodePtr;
        }

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
    //print_single_link_with_addr(headPtr);
}

void print_single_link_with_addr (SINGLE_LINK * headPtr)
{
    SINGLE_LINK * currentNodePtr = headPtr;
    printf(" Single Link List (Addr) : ");
    while(currentNodePtr)
    {
        printf("%p-->", (void *) currentNodePtr);
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

bool delete_single_node (SINGLE_LINK ** headPtr, int data)
{
    if(headPtr && (*headPtr)) {
        
        SINGLE_LINK * currentNodePtr = *headPtr;
        SINGLE_LINK * prevOfCurrentNodePtr = NULL;

        while(currentNodePtr && (currentNodePtr->data != data)) {
            prevOfCurrentNodePtr = currentNodePtr;
            currentNodePtr = currentNodePtr->next;
        }

        // Very First Node itself
        if(!prevOfCurrentNodePtr && (*headPtr == currentNodePtr)) {
            *headPtr = (*headPtr)->next;
            FREE(currentNodePtr);
            return SUCCESS;
        }
        // If currentNodePtr is NULL, then there is no desired node present in linked list
        else if(currentNodePtr) {
            prevOfCurrentNodePtr->next = currentNodePtr->next;
            FREE(currentNodePtr);
            return SUCCESS;
        }
        // We did not found desired node in linked list
        else {
            return FAIL;
        }
    }
    else {
        printf(" HeadPtr is Empty\n");
        return FAIL;
    }
}
// bool delete_single_node_r       (SINGLE_LINK ** headPtr, int data);     // _r Indicate recursion
// bool delete_single_link_list    (SINGLE_LINK ** headPtr);
// bool delete_single_link_list_r  (SINGLE_LINK ** headPtr);               // _r Indicate recursion
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

    arrange_in_order(ARRANGE_IN_ASCENDING, headPtr);
    printf(" After ARRANGE_IN_ASCENDING\n");
    print_single_link_list(headPtr);

    arrange_in_order(ARRANGE_IN_DESCENDING, headPtr);
    printf(" After ARRANGE_IN_DESCENDING\n");
    print_single_link_list(headPtr);

    delete_single_link_list_r(&headPtr);
    printf(" After Delete \n");

    print_single_link_list(headPtr);
}

SINGLE_LINK * create_new_node (int data)
{
    SINGLE_LINK * newNodePtr = (SINGLE_LINK *) calloc(1, sizeof(SINGLE_LINK));
    if(newNodePtr)
    {
        newNodePtr->data = data;
        newNodePtr->next = NULL;
    }
    return newNodePtr;
}

bool add_single_link_at_last (SINGLE_LINK ** headPtr, int data)
{
    bool ret_val = FAIL;
    if (headPtr)
    {
        SINGLE_LINK * newNodePtr = create_new_node(data);
        if (!newNodePtr)
        {
            printf(" Memory allocation fail \n");
            return FAIL;
        }
        else
        {
            if (is_single_link_empty(*headPtr))
            {
                *headPtr = newNodePtr;
            }
            else
            {
                SINGLE_LINK * currentNodePtr = *headPtr;
                while(currentNodePtr->next)
                    currentNodePtr = currentNodePtr->next;
                //newNodePtr->next = currentNodePtr->next; we've already initialize newNodePtr->next with NULL so repeatation is not required
                currentNodePtr->next = newNodePtr;
            }
            return SUCCESS;
        }
    }
    else
    {
        return FAIL;
    }
}

bool add_single_link_at_first (SINGLE_LINK ** headPtr, int data)
{
    if(headPtr)
    {
        SINGLE_LINK * newNodePtr = create_new_node(data);
        if (!newNodePtr)
        {
            printf(" Memory allocation fail \n");
            return FAIL;
        }
        else
        {
            newNodePtr->next = (*headPtr);
            (*headPtr) = newNodePtr;
            return SUCCESS;
        }
    }
    else
    {
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
            if((1 == position) || is_single_link_empty(headPtr))
            {
                newNodePtr->next = (* headPtr);
                (*headPtr) = newNodePtr;
                return SUCCESS;
            }
            else
            {
                SINGLE_LINK * currentNodePtr = (*headPtr);
                SINGLE_LINK * prevOfCurrentNodePtr = NULL;

                position--;
                while (position && currentNodePtr)
                {
                    prevOfCurrentNodePtr = currentNodePtr;
                    currentNodePtr = currentNodePtr->next; 
                    position--;
                }

                if(0 == position) {
                    prevOfCurrentNodePtr->next = newNodePtr;
                    newNodePtr->next = currentNodePtr;
                    return SUCCESS;
                }
                else {
                    FREE_SINGLE_LINK_NODE(newNodePtr);
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
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

void print_single_link_with_data (SINGLE_LINK * headPtr)
{
    printf(" Single Link List (data) : ");
    while(headPtr)
    {
        printf("%d-->", headPtr->data);
        headPtr = headPtr->next;
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

bool arrange_in_order(ARRANGE_ORDER order, SINGLE_LINK * headPtr)
{
    if(headPtr) {
        SINGLE_LINK * innerLoopPtr = NULL;
        SINGLE_LINK * outterLoopPtr = NULL;
        for(outterLoopPtr=headPtr; outterLoopPtr->next; outterLoopPtr=outterLoopPtr->next) {
            for(innerLoopPtr=outterLoopPtr->next; innerLoopPtr; innerLoopPtr=innerLoopPtr->next) {
                if(ARRANGE_IN_ASCENDING == order) {
                    if(innerLoopPtr->data < outterLoopPtr->data) {
                        swap_with_data(innerLoopPtr, outterLoopPtr);
                    }
                }
                else if(ARRANGE_IN_DESCENDING == order) {
                    if(innerLoopPtr->data > outterLoopPtr->data) {
                        swap_with_data(innerLoopPtr, outterLoopPtr);
                    }
                }
            }
        }
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

bool swap_with_data(SINGLE_LINK * ptr1, SINGLE_LINK * ptr2)
{
    if(ptr1 && ptr2) {
        int temp = ptr1->data;
        ptr1->data = ptr2->data;
        ptr2->data = temp;
        return SUCCESS;
    }
    else {
        return FAIL;
    }
}

bool delete_single_link_list (SINGLE_LINK ** headPtr)
{
    if(*headPtr) {
        SINGLE_LINK * currentNodePtr;
        while(*headPtr)
        {
            currentNodePtr = *headPtr;
            (*headPtr) = (*headPtr)->next;
            FREE_SINGLE_LINK_NODE(currentNodePtr);
        }
        return SUCCESS;
    }
    else {
        printf(" HeadPtr is empty\n");
        return FAIL;
    }
}

bool delete_single_link_list_r (SINGLE_LINK ** headPtr)    // _r Indicate recursion
{
    if(headPtr) {
        while(*headPtr) {
            delete_single_link_list_r(&(*headPtr)->next);
            FREE_SINGLE_LINK_NODE(*headPtr);
        }
        return SUCCESS;
    }
    else {
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
            FREE_SINGLE_LINK_NODE(currentNodePtr);
            return SUCCESS;
        }
        // If currentNodePtr is NULL, then there is no desired node present in linked list
        else if(currentNodePtr) {
            prevOfCurrentNodePtr->next = currentNodePtr->next;
            FREE_SINGLE_LINK_NODE(currentNodePtr);
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

bool reverse_single_link (SINGLE_LINK ** headPtr)
{
    if(headPtr) {

        SINGLE_LINK * prevNodePtr = NULL, * currentNodePtr = (*headPtr), * tmpNextNodePtr = NULL;
       
        while(currentNodePtr) {

            tmpNextNodePtr = currentNodePtr->next;
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

// Return the last node which was first node before this operation
SINGLE_LINK * reverse_single_link_r (SINGLE_LINK ** headPtr, SINGLE_LINK * nodePtr)
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
        SINGLE_LINK * nextNodePtr = reverse_single_link_r(headPtr, nodePtr->next);
        nextNodePtr->next = nodePtr;
        // To Assign NULL to first node's next, as we're making it as last
        nodePtr->next = NULL;
        return nodePtr;
    }
    else {
        return NULL;
    }
}

bool is_single_link_empty (SINGLE_LINK * headPtr)
{
    return (headPtr) ? NO : YES; 
}

unsigned int size_of_single_link (SINGLE_LINK * headPtr)
{
    unsigned int count = 0;
    while(headPtr) {
        headPtr = headPtr->next;
        count += 1;
    }
    return count;
}

SINGLE_LINK * add_two_single_link (SINGLE_LINK * headPtr1, SINGLE_LINK * headPtr2)
{
    if(headPtr1 && headPtr2) {
        SINGLE_LINK * newLinkListHeadPtr = create_new_node(0);
        SINGLE_LINK * currentSinglePtr = newLinkListHeadPtr;
        SINGLE_LINK * newSinglePtr = NULL;
        int data1, data2 = 0;
        int carry = 0;
        int sum = 0;

        while(headPtr1 || headPtr2) {
            sum =   ((headPtr1) ? headPtr1->data : 0) +
                    ((headPtr2) ? headPtr2->data : 0) +
                    carry;

            newSinglePtr = create_new_node((sum%10));
            currentSinglePtr->next = newSinglePtr;
            currentSinglePtr = currentSinglePtr->next;

            carry = (sum%10);

            headPtr1 = ((headPtr1) ? (headPtr1->next) : NULL);
            headPtr2 = ((headPtr2) ? (headPtr2->next) : NULL);
        }
        if(carry) {
            currentSinglePtr->next = create_new_node(carry);
        }

        currentSinglePtr = newLinkListHeadPtr->next;
        FREE_SINGLE_LINK_NODE(newLinkListHeadPtr);
        return currentSinglePtr;
    }
    else {
        return NULL;
    }
}
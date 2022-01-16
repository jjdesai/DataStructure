#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "CircularLinkList.h"

int main()
{
    CIRCULAR_LINK * circularHeadPtr = NULL;
    add_circular_node_at_beginning(&circularHeadPtr, 1);
    print_circular_link_list(circularHeadPtr);
    add_circular_node_at_beginning(&circularHeadPtr, 11);
    add_circular_node_at_beginning(&circularHeadPtr, 111);
    add_circular_node_at_beginning(&circularHeadPtr, 1111);
    print_circular_link_list(circularHeadPtr);
}

CIRCULAR_LINK * creat_circular_node (int data)
{
    CIRCULAR_LINK * newCircularPtr = calloc(1, sizeof(CIRCULAR_LINK));
    if(newCircularPtr) {
        newCircularPtr->data = data;
        newCircularPtr->next = NULL;
    }
    return newCircularPtr;
}

bool is_circular_link_empty (CIRCULAR_LINK * circularHeadPtr)
{
    return ((!circularHeadPtr) ? YES : NO);
}

unsigned int size_of_single_link (CIRCULAR_LINK * circularHeadPtr)
{
    int count = 0;
    while(circularHeadPtr) {
        count += 1;
        circularHeadPtr = circularHeadPtr->next;
    }
    return count;
}

bool add_circular_node_at_beginning (CIRCULAR_LINK ** circularHeadPtr, int data)
{
    if(circularHeadPtr) {
        CIRCULAR_LINK * newCircularLinkNode = creat_circular_node(data);
        if(newCircularLinkNode) {
            if(is_circular_link_empty(*circularHeadPtr)) {
                printf("Here...\n");
                newCircularLinkNode->next = newCircularLinkNode;
            }
            else {
                printf(" No Way...\n");
                CIRCULAR_LINK * tmpCircularNode = (*circularHeadPtr);
                while(tmpCircularNode->next != (*circularHeadPtr)) {
                    tmpCircularNode = tmpCircularNode->next;
                }
                tmpCircularNode->next = newCircularLinkNode;
                newCircularLinkNode->next = (*circularHeadPtr)->next;
            }
            (*circularHeadPtr) = newCircularLinkNode;
            return SUCCESS;
        }
        else {
            printf(" Memory allocation failed\n");
            return FAIL;
        }
    }
    else {
        return FAIL;
    }
}

bool add_circular_node_at_end (CIRCULAR_LINK ** circularHeadPtr, int data)
{
    if(circularHeadPtr) {
        CIRCULAR_LINK * newCircularLinkNode = creat_circular_node(data);
        if(newCircularLinkNode) {

            if(is_circular_link_empty(*circularHeadPtr)) {
                newCircularLinkNode->next = newCircularLinkNode;
                (*circularHeadPtr) = newCircularLinkNode;
            }
            else {
                CIRCULAR_LINK * travelNode = (*circularHeadPtr);
                while(travelNode->next != (*circularHeadPtr)) {
                    travelNode = travelNode->next;
                }
                travelNode->next = newCircularLinkNode;
                newCircularLinkNode->next = (*circularHeadPtr);
            }
            return SUCCESS;
        }
        else {
            printf(" Memory allocation failed\n");
            return FAIL;
        }
    }
    else {
        return FAIL;
    }
}

bool add_circular_node_at_position (CIRCULAR_LINK ** circularHeadPtr, int data, int position)
{

}

bool add_circular_node_after (CIRCULAR_LINK ** circularHeadPtr, int data, int afterData)
{
    if(circularHeadPtr) {


    }
    else {
        return SUCCESS;
    }

}

void print_circular_link_list (CIRCULAR_LINK * circularHeadPtr)
{
    if(circularHeadPtr) {
        printf(" Circular : ");
        CIRCULAR_LINK * circularHeadPtrDupli = circularHeadPtr;
        while(circularHeadPtr->next != circularHeadPtrDupli) {
            printf("%d--->", circularHeadPtr->data);
            circularHeadPtr = circularHeadPtr->next;
        }
        printf("CIRCULAR\n");
    }
}
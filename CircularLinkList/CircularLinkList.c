#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "CircularLinkList.h"

int main(int agrc, char ** argv)
{
    CIRCULAR_LINK * circularHeadPtr = NULL;
    add_circular_node_at_end(&circularHeadPtr, 1);
    print_circular_link_list(circularHeadPtr);
    add_circular_node_at_end(&circularHeadPtr, 11);
    print_circular_link_list(circularHeadPtr);
    add_circular_node_at_end(&circularHeadPtr, 111);
    print_circular_link_list(circularHeadPtr);
    add_circular_node_at_end(&circularHeadPtr, 1111);
    print_circular_link_list(circularHeadPtr);

    delete_circular_link_list_r(&circularHeadPtr, circularHeadPtr->next);

    add_circular_node_at_end(&circularHeadPtr, 999);
    print_circular_link_list(circularHeadPtr);

    delete_circular_link_list_r(&circularHeadPtr, circularHeadPtr->next);

    return 1;
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

unsigned int size_of_circular_link (CIRCULAR_LINK * circularHeadPtr)
{
    unsigned int count = 0;
    if(circularHeadPtr) {
        printf(" Circular : ");
        CIRCULAR_LINK * circularHeadPtrDupli = circularHeadPtr;
        do {
            count++;
        }while(circularHeadPtr != circularHeadPtrDupli);
    }
    return count;
}

bool add_circular_node_at_beginning (CIRCULAR_LINK ** circularHeadPtr, int data)
{
    if(circularHeadPtr) {
        CIRCULAR_LINK * newCircularLinkNode = creat_circular_node(data);
        if(newCircularLinkNode) {
            if(is_circular_link_empty(*circularHeadPtr)) {
                newCircularLinkNode->next = newCircularLinkNode;
            }
            else {
                CIRCULAR_LINK * tmpCircularNode = (*circularHeadPtr);

                do {
                    tmpCircularNode = tmpCircularNode->next;
                }while(tmpCircularNode->next != (*circularHeadPtr));

                tmpCircularNode->next = newCircularLinkNode;
                newCircularLinkNode->next = (*circularHeadPtr);
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

        CIRCULAR_LINK * newCircularLinkNode = creat_circular_node(data);
        if(newCircularLinkNode){
            if(is_circular_link_empty(*circularHeadPtr)) {

            }
            else {

                CIRCULAR_LINK * tmpCircularNodePtr = (*circularHeadPtr);
                do {
                    tmpCircularNodePtr = tmpCircularNodePtr->next;
                }while(((*circularHeadPtr) != tmpCircularNodePtr) && (tmpCircularNodePtr->data));
            }
        }
        else {
            printf(" Memory Allocation Failed\n");
            return FAIL;
        }
    }
    else {
        return SUCCESS;
    }
}

bool delete_circular_link_list (CIRCULAR_LINK ** circularHeadPtr)
{
    if(circularHeadPtr) {
        if(is_circular_link_empty(*circularHeadPtr)) {
            printf(" Circular Link List is already empty\n");
            return FAIL;
        }
        else {
            CIRCULAR_LINK * rotationPtr = (*circularHeadPtr);
            CIRCULAR_LINK * deleteCircularNodePtr = NULL;
            do {
                deleteCircularNodePtr = rotationPtr;
                rotationPtr = rotationPtr->next;
                printf(" Free[%d]\n", deleteCircularNodePtr->data);
                FREE_CIRCULAR_LINK_NODE(deleteCircularNodePtr);
            }while(rotationPtr != (*circularHeadPtr));
            (*circularHeadPtr) = NULL;
            return SUCCESS;
        }
    }
    else {
        return FAIL;
    }
}

bool delete_circular_link_list_r (CIRCULAR_LINK ** circularHeadPtr, CIRCULAR_LINK * rotationCircularNodePtr)
{
    if(circularHeadPtr) {
        if(is_circular_link_empty(*circularHeadPtr)) {
            printf(" Circular Link List is already empty\n");
            return FAIL;
        }
        else if((*circularHeadPtr) != (rotationCircularNodePtr)) {
            printf(" Free[%d]\n", rotationCircularNodePtr->data);
            delete_circular_link_list_r(circularHeadPtr, rotationCircularNodePtr->next);
            
            FREE_CIRCULAR_LINK_NODE((*circularHeadPtr));
            return SUCCESS;
        }
        else {
            printf("Reached Last\n");
            return SUCCESS;
        }
    }
    else {
        return FAIL;
    }
}

void print_circular_link_list (CIRCULAR_LINK * circularHeadPtr)
{
    if(circularHeadPtr) {
        printf(" Circular : ");
        CIRCULAR_LINK * circularHeadPtrDupli = circularHeadPtr;
        do {
            printf("%d-->", circularHeadPtr->data);
            circularHeadPtr = circularHeadPtr->next;
        }while(circularHeadPtr != circularHeadPtrDupli);
        printf("%d CIRCULAR...\n", circularHeadPtr->data);
    }
}

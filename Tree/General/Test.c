#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct _general_tree_
{
    int data;
    unsigned int degree;
    struct _general_tree_ ** childHeadPtr;

}GENERAL_TREE;

#define YES     1
#define NO      0

#define DESTRUCTOR_of_GENERAL_TREE(VAL) \
        (VAL)->degree = 0;              \
        free((VAL)->childHeadPtr);      \
        (VAL)->childHeadPtr = NULL;     \
        free(VAL);                      \
        VAL = NULL;

typedef unsigned char bool;                     

bool is_general_tree_empty (GENERAL_TREE * headPtr)
{
    return (headPtr) ? NO : YES;
}

GENERAL_TREE * get_parent_node (GENERAL_TREE * headPtr, int parentData)
{
    if(is_general_tree_empty(headPtr))
        return NULL;
    
    if(headPtr->data == parentData)
    {
        return headPtr;
    }
    else
    {
        unsigned int i;
        GENERAL_TREE * retPtr = NULL;
        for(i=0; i<headPtr->degree; i++)
        {
            retPtr = get_parent_node(headPtr->childHeadPtr[i], parentData);
            if(retPtr)  break;
        }
        return retPtr;
    }
}

bool insert_in_general_tree (GENERAL_TREE ** headPtr, unsigned int data, unsigned int parentData)
{
    if(headPtr)
    {
        GENERAL_TREE * newNodePtr = creat_general_tree(data);
        if(newNodePtr)
        {
            if(*headPtr)
            {
                GENERAL_TREE * parentNodePtr = get_parent_node(*headPtr, parentData);
                if(parentNodePtr)
                {
                    int prevSize = parentNodePtr->degree; 
                    parentNodePtr->degree += 1;
                    parentNodePtr->childHeadPtr = (GENERAL_TREE **) realloc(parentNodePtr->childHeadPtr, parentNodePtr->degree);
                    parentNodePtr->childHeadPtr[prevSize] = newNodePtr;
                    return 1;
                }
                else
                {
                    printf("Parent[%d] Node is not exist\n", parentData);
                    return 0;
                }
            }
            else
            {
                (*headPtr) = newNodePtr;
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }
}

bool delete_general_tree (GENERAL_TREE ** headPtr)
{
    if(is_general_tree_empty(*headPtr))
        return NO;

    for(unsigned int i=0; i<(*headPtr)->degree; i++)
        delete_general_tree(&((*headPtr)->childHeadPtr[i]));

    DESTRUCTOR_of_GENERAL_TREE(*headPtr);
}

void print_general_tree_in_preorder (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return;
    
    printf("%d ", headPtr->data);
    GENERAL_TREE * retPtr = NULL;
    for(unsigned int i=0; i < headPtr->degree; i++)
    {
        print_general_tree_in_preorder(headPtr->childHeadPtr[i]);
    }
}

void print_general_tree_in_postorder (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return;
    
    GENERAL_TREE * retPtr = NULL;
    for(unsigned int i=0; i < headPtr->degree; i++)
    {
        print_general_tree_in_postorder(headPtr->childHeadPtr[i]);
    }
    printf("%d ", headPtr->data);
}

int main(int argc, char ** argv)
{
    GENERAL_TREE * headPtr = NULL;

    insert_in_general_tree(&headPtr, 0, 0);
    
    insert_in_general_tree(&headPtr, 1, 0);
    insert_in_general_tree(&headPtr, 2, 0);
    insert_in_general_tree(&headPtr, 3, 0);

    insert_in_general_tree(&headPtr, 11, 1);
    insert_in_general_tree(&headPtr, 12, 1);
    insert_in_general_tree(&headPtr, 13, 1);

    insert_in_general_tree(&headPtr, 21, 2);
    insert_in_general_tree(&headPtr, 22, 2);
    insert_in_general_tree(&headPtr, 23, 2);

    insert_in_general_tree(&headPtr, 31, 3);
    insert_in_general_tree(&headPtr, 32, 3);
    insert_in_general_tree(&headPtr, 33, 3);

    printf(" General Tree in Pre-Order : ");
    print_general_tree_in_preorder(headPtr);
    printf("\n");

    printf(" General Tree in Post-Order : ");
    print_general_tree_in_postorder(headPtr);
    printf("\n");

    delete_general_tree(&headPtr);

    return 1;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "GeneralTree.h"

GENERAL_TREE * get_node_from_data (GENERAL_TREE * headPtr, int parentData);
GENERAL_TREE * get_parent_node_of_data(GENERAL_TREE * headPtr, int data);

/*
                            0
                            |
                |-----------|-----------|
                1           2           3
                |           |           |
            |--------|  |---|----|  |--------|
            11  12  13  21  22  23  31  32  33
            |               |                |
         |-----|   |----|---|---|----|    |-----|
        111   112  221 222 223 224 225   331   332
*/

int main ()
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

    delete_node_from_general_tree(&headPtr, 21);

    printf(" General Tree in Pre-Order : ");
    print_general_tree_in_preorder(headPtr);
    printf("\n");

    printf(" General Tree in Post-Order : ");
    print_general_tree_in_postorder(headPtr);
    printf("\n");

    printf(" Total Size of General Tree : [%d]\n", total_nodes_in_general_tree(headPtr));
    printf(" Parent of 22 is [%d]\n", get_parent_of_data(headPtr, 22));
    printf(" Parent of 32 is [%d]\n", get_parent_of_data(headPtr, 32));
    printf(" Parent of 34 is [%d]\n", get_parent_of_data(headPtr, 34));

    delete_general_tree(&headPtr);

    printf(" Total Size of General Tree : [%d]\n", total_nodes_in_general_tree(headPtr));

    return 1;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Create a new node and return without checking the allocation.
    Parameter : data (In) -> data to be filled in data-structure 
    Return :    New Node
*/
GENERAL_TREE * creat_general_tree (int data)
{
    GENERAL_TREE * newNodePtr = (GENERAL_TREE *) malloc(sizeof(GENERAL_TREE));
    if(newNodePtr)
    {
        newNodePtr->data = data;
        newNodePtr->degree = 0;
        newNodePtr->childHeadPtr = NULL;
    }
    return newNodePtr;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Check whether tree is empty or not.
    Parameter : headPtr (In) -> Head Pointer 
    Return :    NO  --> When headPtr is NON-NULL
                YES --> When headPtr is NULL
*/
bool is_general_tree_empty (GENERAL_TREE * headPtr)
{
    return (headPtr) ? NO : YES;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the total nodes from given general tree pointer at headPtr.
    Parameter : headPtr (In) -> Head Pointer 
    Return :    Total number of nodes
*/
unsigned int total_nodes_in_general_tree (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return 0;

    int i;
    int totalNode = 1;
    for(i=0; i<headPtr->degree; i++)
    {
        totalNode += total_nodes_in_general_tree(headPtr->childHeadPtr[i]);
    }
    return totalNode;
}

GENERAL_TREE * get_node_from_data (GENERAL_TREE * headPtr, int data)
{
    if(is_general_tree_empty(headPtr))
        return NULL;
    
    if(headPtr->data == data)
    {
        return headPtr;
    }
    else
    {
        unsigned int i;
        GENERAL_TREE * retPtr = NULL;
        for(i=0; i<headPtr->degree; i++)
        {
            retPtr = get_node_from_data(headPtr->childHeadPtr[i], data);
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
                GENERAL_TREE * parentNodePtr = get_node_from_data(*headPtr, parentData);
                if(parentNodePtr)
                {
                    int prevSize = parentNodePtr->degree; 
                    parentNodePtr->degree += 1;
                    parentNodePtr->childHeadPtr = (GENERAL_TREE **) realloc(parentNodePtr->childHeadPtr, parentNodePtr->degree);
                    parentNodePtr->childHeadPtr[prevSize] = newNodePtr;
                    return YES;
                }
                else
                {
                    printf("Parent[%d] Node is not exist\n", parentData);
                    return NO;
                }
            }
            else
            {
                (*headPtr) = newNodePtr;
                return YES;
            }
        }
    }
    else
    {
        return NO;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in pre-order (Root->Left->Right).
    Parameter : headPtr (In) -> Head Pointer
*/
void print_general_tree_in_preorder (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return;
    
    printf("%d ", headPtr->data);
    for(unsigned int i=0; i < headPtr->degree; i++)
    {
        print_general_tree_in_preorder(headPtr->childHeadPtr[i]);
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in post-order (Left->Right->Root).
    Parameter : headPtr (In) -> Head Pointer
*/
void print_general_tree_in_postorder (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return;
    
    for(unsigned int i=0; i < headPtr->degree; i++)
    {
        print_general_tree_in_postorder(headPtr->childHeadPtr[i]);
    }
    printf("%d ", headPtr->data);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Delete the whole general tree pointed by headPtr.
    Parameter : headPtr (In) : Head Pointer  
    Return :    FAIL    --> When tree is already empty
                SUCCESS --> When tree is freeded successfully
*/
void delete_general_tree (GENERAL_TREE ** headPtr)
{
    if(is_general_tree_empty(*headPtr))
        return;

    for(unsigned int i=0; i<(*headPtr)->degree; i++)
        delete_general_tree(&((*headPtr)->childHeadPtr[i]));

    DESTRUCTOR_of_GENERAL_TREE(*headPtr);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Delete the particular node/sub-tree with data from general tree pointed by headPtr.
    Parameter : headPtr (In) : Head Pointer
                data (In)    : Node/Sub-Tree which needs to be delete 
    Return :    FAIL    --> When General Tree is already empty/ does not have node with data 
                SUCCESS --> When Node/Sub-Tree is freeded successfully
*/
bool delete_node_from_general_tree (GENERAL_TREE ** headPtr, int data)
{
    if(headPtr)
    {
        if(is_general_tree_empty(*headPtr))
            return FAIL;
        
        // Node found
        if((*headPtr)->data == data)
        {
            delete_general_tree(headPtr);
            return SUCCESS;
        }
        // Node did not found. Have to travel in General Tree
        else
        {
            unsigned int i;
            bool ret = FAIL;
            for(i=0; i<(*headPtr)->degree; i++)
            {
                ret = delete_node_from_general_tree(&(*headPtr)->childHeadPtr[i], data);
                if(ret) break;
            }
            return ret;
        }
    }
    else
        return FAIL;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the root node data.
    Parameter : headPtr (In) : Head Pointer  
    Return :    -1    --> When tree is empty
                Data  --> Return the first node data
*/
int get_root_node_data (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return -1;
    else
        return headPtr->data;
}

GENERAL_TREE * get_parent_node_of_data(GENERAL_TREE * headPtr, int data)
{
    if(is_general_tree_empty(headPtr))
        return NULL;
    else
    {
        GENERAL_TREE * tmpNodePtr = NULL;
        for(unsigned int i=0; i<headPtr->degree; i++)
        {
            if(!headPtr->childHeadPtr[i])
            {
                printf("Unexpected...[%d]\n", i);
                continue;                   // This is Error due to deleting the node. Delete node is not well handled
            }
            if(headPtr->childHeadPtr[i]->data == data)
            {
                printf("Helo\n");
                return headPtr;
            }
            else
            {
                if(NULL != (tmpNodePtr = get_parent_node_of_data(headPtr->childHeadPtr[i], data)))
                {
                    printf("Returing...\n");
                    return tmpNodePtr;
                }
            }
        }
        printf("Return..\n");
        return NULL;
    }
}

int get_parent_of_data (GENERAL_TREE * headPtr, int data)
{
    GENERAL_TREE * tmpNodePtr = get_parent_node_of_data(headPtr, data);
    if(tmpNodePtr)
        return tmpNodePtr->data;
    else
        return -1;
}

#if 0

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the sibling.
    Parameter : headPtr (In) : Head Pointer
                data (In)    : Data whose sibling needs to find
    Return :    -1    --> When sibling is not found
                Sibling data --> Return sibling data 
*/
int get_siblings (GENERAL_TREE * headPtr, int data)
{
    if(is_general_tree_empty(headPtr))
        return -1;
    else
    {
        if(headPtr->left && headPtr->right)
        {
            int ret = -1; 
            if(headPtr->left->data == data)
                return headPtr->right->data;
            else if(headPtr->right->data == data)
                return headPtr->left->data;
            else if(-1 != (ret = get_siblings(headPtr->left, data)))
                return ret;
            else if(-1 != (ret = get_siblings(headPtr->right, data)))
                return ret;
            else
                return -1;
        }
        else
            return -1;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the sibling.
    Parameter : headPtr (In) : Head Pointer
    Return :    -1    --> When sibling is not found
                sibling data --> Return sibling data 
*/
bool is_sibling (GENERAL_TREE * headPtr, int data1, int data2)
{
    if(is_general_tree_empty(headPtr))
        return NO;
    else
    {
        if(headPtr->left && headPtr->right)
        {
            if( ((headPtr->left->data == data1) && (headPtr->right->data == data2)) ||
                ((headPtr->right->data == data1) && (headPtr->left->data == data2))   )
            {
                return YES;
            }
            if(YES == is_sibling(headPtr->left, data1, data2))
                return YES;
            else if(YES == is_sibling(headPtr->right, data1, data2))
                return YES;
            else
                return NO;
        }
        else
            return NO;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Print the internel nodes (Internal node is the one who has atleast one child).
    Parameter : headPtr (In) : Head Pointer  
    Return :    Print the internal nodes 
*/
void print_internal_node (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return;

    if(headPtr->left || headPtr->right)
        printf("%d ", headPtr->data);

    if(headPtr->left)
        print_internal_node(headPtr->left);
    if(headPtr->right)
        print_internal_node(headPtr->right);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Print the leaf nodes (Leaf node is the one who has no child).
    Parameter : headPtr (In) : Head Pointer  
    Return :    Print the leaf nodes 
*/
void print_leaf_node (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return;

    if( (NULL == headPtr->left) &&
        (NULL == headPtr->right) )
        printf("%d ", headPtr->data);

    if(headPtr->left)
        print_leaf_node(headPtr->left);
    if(headPtr->right)
        print_leaf_node(headPtr->right);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Print the ancestors (Path to data).
    Parameter : headPtr (In) : Head Pointer
                data (In)    : Data till which path needs to print
    Return :    Print the ancestor 
*/
bool print_ancestor (GENERAL_TREE * headPtr, int data)
{
    if(is_general_tree_empty(headPtr))
        return NO;

    if(data == headPtr->data)
    {
        printf("%d ", headPtr->data);
        return YES;
    }

    if( print_ancestor(headPtr->left, data) ||
        print_ancestor(headPtr->right, data) )
    {
        printf("%d ", headPtr->data);
        return YES;
    }
    else
        return NO;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Print the descendant (Path after data).
    Parameter : headPtr (In) : Head Pointer
                data (In)    : Data after which path needs to print
    Return :    Print the descendants 
*/
void print_descendant (GENERAL_TREE * headPtr, int data)
{
    if(is_general_tree_empty(headPtr))
        return;
    
    if(headPtr->data == data)
    {
        print_in_inorder(headPtr);
    }
    else
    {
        print_descendant(headPtr->left, data);
        print_descendant(headPtr->right, data);
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the height.
    Parameter : headPtr (In) : Head Pointer
    Return :    0 -> NULL Tree
                Height of the tree 
*/
unsigned int get_height (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return 0;
    else
    {
        int leftHeight = get_height(headPtr->left);
        int rightHeight = get_height(headPtr->right);
        return (leftHeight > rightHeight) ? (leftHeight+1) : (rightHeight+1);
    }
}

int total_node_at_level (GENERAL_TREE * headPtr, int level)
{

}

#endif
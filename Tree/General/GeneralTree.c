#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "GeneralTree.h"

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
        111   112  221 222 223 224  225  331   332

*/

/*
                    10
                ___/  \___
               /          \
              20          30
             /  \        /  \
           40   50     60    70
           /   /  \            \
          80  90  100          110

        0   |1   2   |3   4   5   6   |7   8   9   10  11  12  13  14
        10  |20  30  |40  50  60  70  |80  -1  100 90  -1  -1  -1  110
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

    printf(" General Tree in Post-Order : ");
    print_general_tree_in_postorder(headPtr);
    printf("\n");

    delete_general_tree(&headPtr);

    return 1;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Create a new node and return without checking the allocation.
    Parameter : headPtr (In) -> Head Pointer 
    Return :    New Node
*/
GENERAL_TREE * create_general_tree (int data)
{
    GENERAL_TREE * newGeneralNode = (GENERAL_TREE *) calloc(1, sizeof(GENERAL_TREE));
    if(newGeneralNode)
    {
        newGeneralNode->data = data;
        newGeneralNode->left = NULL;
        newGeneralNode->right = NULL;
    }
    return newGeneralNode;
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
    return ((headPtr) ? NO : YES);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Calculate the size of tree pointed by headPtr.
    Parameter : headPtr (In) -> Head Pointer 
    Return :    0    --> When headPtr is NULL (No Tree present)
                size --> Size of the Tree  (How many node present in Tree)
*/
unsigned int size_of_general_tree (GENERAL_TREE * headPtr)
{
    if(NULL == headPtr)
        return 0;
    else
        return (1 + size_of_general_tree(headPtr->left) + size_of_general_tree(headPtr->right));
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Based on Position at pos, add new node with data in headPtr.
    Parameter : headPtr (In) -> Head Pointer 
                data    (In) -> Data with which new node created
                pos     (IN) -> Belong to E_POSITION.
    Return :    FAIL    --> When headPtr negative or Memory allocation failed
                SUCCESS --> When new node with data is successfully added at pos of headPtr
*/
bool insert_in_tree (GENERAL_TREE ** headPtr, int data, E_POSITION pos)
{
    if(headPtr)
    {
        GENERAL_TREE * newNodePtr = create_general_tree(data); 
        if(newNodePtr)
        {
            switch (pos)
            {
                case POSITION_ROOT: (*headPtr) = newNodePtr;        break;
                case POSITION_LEFT: (*headPtr)->left = newNodePtr;  break;
                case POSITION_RIGHT:(*headPtr)->right = newNodePtr; break;
                default: printf(" Wrong Position selected\n");      break;
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
        return FAIL;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Check data is present in General Tree or not.
    Parameter : headPtr (In) -> Head Pointer 
                data    (In) -> data whose present need to check in tree 
    Return :    NO  --> When data is not present in tree
                YES --> When data is present in tree
*/
bool is_data_present_in_tree (GENERAL_TREE * headPtr, const int data)
{
    if(headPtr == NULL)
        return NO;
    else
    {
        int ret = NO;
        if(data == headPtr->data)
            return YES;
        if(YES == (ret = is_data_present_in_tree(headPtr->left, data)))
            return YES;
        else if(YES == (ret = is_data_present_in_tree(headPtr->right, data)))
            return YES;
        else
            return ret;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in pre-order (Root->Left->Right).
    Parameter : headPtr (In) -> Head Pointer
*/
void print_in_preorder (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return;

    printf("%d ", headPtr->data);
    print_in_preorder(headPtr->left);
    print_in_preorder(headPtr->right);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in in-order (Left->Root->Right).
    Parameter : headPtr (In) -> Head Pointer
*/
void print_in_inorder (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return;

    print_in_inorder(headPtr->left);
    printf("%d ", headPtr->data);
    print_in_inorder(headPtr->right);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in post-order (Left->Right->Root).
    Parameter : headPtr (In) -> Head Pointer
*/
void print_in_postorder (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return;

    print_in_postorder(headPtr->left);
    print_in_postorder(headPtr->right);
    printf("%d ", headPtr->data);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Delete the whole tree below headPtr.
    Parameter : headPtr (In) : Head Pointer  
    Return :    FAIL    --> When tree is already empty
                SUCCESS --> When tree is freeded successfully
*/
bool delete_general_tree (GENERAL_TREE ** headPtr)
{
    if(is_general_tree_empty(*headPtr))
        return FAIL;
    else
    {
        delete_general_tree(&((*headPtr)->left));
        delete_general_tree(&((*headPtr)->right));
        FREE_GENERAT_TREE_NODE((*headPtr));
        return SUCCESS;
    }
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
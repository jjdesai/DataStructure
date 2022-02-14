#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "BinaryCommon.h"

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Create a new node and return without checking the allocation.
    Parameter : headPtr (In) -> Head Pointer 
    Return :    New Node
*/
BINARY_TREE * create_binary_tree (int data)
{
    BINARY_TREE * newBinaryNode = (BINARY_TREE *) calloc(1, sizeof(BINARY_TREE));
    if(newBinaryNode)
    {
        newBinaryNode->data = data;
        newBinaryNode->left = NULL;
        newBinaryNode->right = NULL;
    }
    return newBinaryNode;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Check whether Binary Tree is empty or not.
    Parameter : headPtr (In) -> Head Pointer 
    Return :    NO  --> When headPtr is NON-NULL
                YES --> When headPtr is NULL
*/
bool is_binary_tree_empty (BINARY_TREE * headPtr)
{
    return ((headPtr) ? NO : YES);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the total number nodes in Binary Tree .
    Parameter : headPtr (In) -> Head Pointer 
    Return :    0    --> When headPtr is NULL (No Binary Tree present)
                total number of nodes present in Binary Tree
    Time Complexity : O(n)  -> Travel through each node
    Space Complexity : O(h) -> h is the height of the Binary Tree

*/
unsigned int total_node_in_binary_tree (BINARY_TREE * headPtr)
{
    if(NULL == headPtr)
        return 0;
    else
        return ( 1                                           + 
                 total_node_in_binary_tree(headPtr->left)    +
                 total_node_in_binary_tree(headPtr->right) );
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Delete the whole tree below headPtr.
    Parameter : headPtr (In) : Head Pointer  
    Return :    FAIL    --> When binary tree is already empty
                SUCCESS --> When binary tree is freeded successfully
*/
bool delete_binary_tree (BINARY_TREE ** headPtr)
{
    if(is_binary_tree_empty(*headPtr))
        return FAIL;
    else
    {
        delete_binary_tree(&((*headPtr)->left));
        delete_binary_tree(&((*headPtr)->right));
        FREE_BINARY_TREE_NODE((*headPtr));
        return SUCCESS;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the height of Binary Tree.
    Parameter : headPtr (In) : Head Pointer
    Return :    0 -> When Binary Tree is NULL
                Height of the Binary Tree 
*/
unsigned int get_binary_tree_height (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return 0;
    else
    {
        int leftHeight = get_binary_tree_height(headPtr->left);
        int rightHeight = get_binary_tree_height(headPtr->right);
        return (leftHeight > rightHeight) ? (leftHeight+1) : (rightHeight+1);
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in pre-order (Root->Left->Right).
    Parameter : headPtr (In) -> Head Pointer
*/
void print_in_preorder (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
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
void print_in_inorder (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
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
void print_in_postorder (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return;

    print_in_postorder(headPtr->left);
    print_in_postorder(headPtr->right);
    printf("%d ", headPtr->data);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the root node data.
    Parameter : headPtr (In) : Head Pointer  
    Return :    -1    --> When Binary Tree is empty
                Data  --> Return the first node data
*/
int get_root_node_data (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
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
int get_siblings (BINARY_TREE * headPtr, int data)
{
    if(is_binary_tree_empty(headPtr))
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
bool is_sibling (BINARY_TREE * headPtr, int data1, int data2)
{
    if(is_binary_tree_empty(headPtr))
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
void print_internal_node (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
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
void print_leaf_node (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
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
bool print_ancestor (BINARY_TREE * headPtr, int data)
{
    if(is_binary_tree_empty(headPtr))
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
void print_descendant (BINARY_TREE * headPtr, int data)
{
    if(is_binary_tree_empty(headPtr))
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
                Height of the Binary Tree 
*/
unsigned int get_height_of_binary_tree (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return 0;
    else
    {
        int leftHeight = get_height_of_binary_tree(headPtr->left);
        int rightHeight = get_height_of_binary_tree(headPtr->right);
        return (leftHeight > rightHeight) ? (leftHeight+1) : (rightHeight+1);
    }
}

BINARY_TREE * find_data_node_from_binary_tree (BINARY_TREE * headPtr, unsigned int data)
{
    if(is_binary_tree_empty(headPtr))
        return NULL;
    else
    {
        if(headPtr->data == data)
            return headPtr;
        BINARY_TREE * retPtr = find_data_node_from_binary_tree(headPtr->left, data);
        if(retPtr)
            return retPtr;
        retPtr = find_data_node_from_binary_tree(headPtr->right, data);
        if(retPtr)
            return retPtr;
    }
}

BINARY_TREE * lowest_common_ancestor (BINARY_TREE * headPtr, BINARY_TREE * data1NodePtr, BINARY_TREE * data2NodePtr)
{
    if((headPtr == NULL) || (headPtr == data1NodePtr) || (headPtr == data2NodePtr))
        return headPtr;
    else
    {
        BINARY_TREE * leftPtr = lowest_common_ancestor(headPtr->left, data1NodePtr, data2NodePtr);
        BINARY_TREE * rightPtr = lowest_common_ancestor(headPtr->right, data1NodePtr, data2NodePtr);
        if(leftPtr == NULL)
            return rightPtr;
        else if(rightPtr == NULL)
            return leftPtr;
        else
        {
            // Both Left and Right is not NULL, we've found our result
            return headPtr;
        }
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the Lowest Common Ancestor between data1 & data2 from given binary tree headPtr.
    Parameter : headPtr (In) : Head Pointer
                data1 (In) & data2 (In) -> data1 & data2 whose LCA needs to find out
    Return :    -1 -> Negative Case
                Return the data of node which is the Lowest Common Ancestor 
*/
int lowest_common_ancestor_in_binary_tree (BINARY_TREE * headPtr, unsigned int data1, unsigned int data2)
{
    if(is_binary_tree_empty(headPtr))
        return -1;
    else
    {
        BINARY_TREE * data1NodePtr = find_data_node_from_binary_tree(headPtr, data1);
        BINARY_TREE * data2NodePtr = find_data_node_from_binary_tree(headPtr, data2);

        if(data1NodePtr && data2NodePtr)
        {
            BINARY_TREE * lcaPtr = lowest_common_ancestor(headPtr, data1NodePtr, data2NodePtr);
            if(lcaPtr)
            {
                printf(" Lowest Common Ancestor between [%d] & [%d] is [%d]\n", data1, data2, lcaPtr->data);
                return lcaPtr->data;
            }
            return -1;
        }
        else
        {
            printf(" Data [%d] or [%d] is not present in the Given Binary Tree\n", data1, data2);
            return -1;
        }
    }
}
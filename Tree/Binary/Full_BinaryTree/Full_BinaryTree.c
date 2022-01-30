#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "../BinaryCommon.c"    // As Make File is not completed, need to add .c
                                // Chnage it to .h once makefile is ready
#include "Full_BinaryTree.h"

/*
                 ______10______
                /              \
              _20__          __30_
             /     \        /     \
            40     50      60      70
           /  \   /  \    /  \    /  \
          80  90 100 110 120 130 140 150
*/

unsigned int find_left_tree_height (BINARY_TREE * headPtr);
unsigned int find_right_tree_height (BINARY_TREE * headPtr);

bool delete_binary_tree_without_root (BINARY_TREE ** headPtr);

int main (int argc, char ** argv)
{
    BINARY_TREE * headPtr = NULL, * headPtr1 = NULL;

    headPtr = create_binary_tree(10);

    headPtr->left = create_binary_tree(20);
    headPtr->right = create_binary_tree(30);

    headPtr->left->left = create_binary_tree(40);
    headPtr->left->right = create_binary_tree(50);
    headPtr->right->left = create_binary_tree(60);
    headPtr->right->right = create_binary_tree(70);

    headPtr->left->left->left = create_binary_tree(80);
    headPtr->left->left->right = create_binary_tree(90);
    headPtr->left->right->left = create_binary_tree(100);
    headPtr->left->right->right = create_binary_tree(110);
    headPtr->right->left->left = create_binary_tree(120);
    headPtr->right->left->right = create_binary_tree(130);
    headPtr->right->right->left = create_binary_tree(140);
    headPtr->right->right->right = create_binary_tree(150);

    printf(" Total no of Node : [%d]\n", total_node_in_full_binary_tree(headPtr));
    printf(" Full Binary Tree Size : [%d]\n", total_node_in_binary_tree(headPtr));

    // To Check delete_node_from_full_binary_tree
    // printf(" Deleting 120 : [%d]\n", delete_node_from_full_binary_tree(&headPtr, 120));  // Node can not delete
    // printf(" Deleting 20 : [%d]\n", delete_node_from_full_binary_tree(&headPtr, 20));    // Node will be deleted
    // printf(" Deleting 220 : [%d]\n", delete_node_from_full_binary_tree(&headPtr, 220));  // Node is not present
    // printf(" Deleting 10 : [%d]\n", delete_node_from_full_binary_tree(&headPtr1, 10));   // Node is null

    if(is_tree_a_full_binary_tree(headPtr))
        printf(" Given Binary Tree is a Full Binary Tree\n");
    else
        printf(" Given Binary Tree is not a Full Binary Tree\n");

    delete_binary_tree(&headPtr);
    printf("--- --- Delete Full Binary Tree --- ---\n");
    printf(" Full Binary Tree Size : [%d]\n", total_node_in_binary_tree(headPtr));

    return -1;
}

unsigned int find_left_tree_height (BINARY_TREE * headPtr)
{
    unsigned int height = 0;
    while(headPtr)
    {
        height+=1;
        headPtr = headPtr->left;
    }
    return height;
}

unsigned int find_right_tree_height (BINARY_TREE * headPtr)
{
    unsigned int height = 0;
    while(headPtr)
    {
        height+=1;
        headPtr = headPtr->right;
    }
    return height;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Get the total number of nodes present in Full Binary Tree.
    Parameter : headPtr (In) -> Head Pointer
    Return :    Number of nodes in Full Binary Tree pointer by headPtr
    NOTE : This function only works when tree is Full Binary Tree
    Time Complexity :   O( (log n)^2 ) --> n is the number of nodes
    Space Complexity :  O( log n )
                        Auxilary Space Complexity will come in order to count the height

    Check total_node_in_binary_tree and compare the Complexity

*/
unsigned int total_node_in_full_binary_tree (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return 0;

    unsigned int leftTreeHeight = find_left_tree_height(headPtr);
    unsigned int rightTreeHeight = find_right_tree_height(headPtr);

    if(leftTreeHeight == rightTreeHeight)       // This represent Perfect Binary Tree so
        return ((1<<leftTreeHeight) -1) ;       // total node = (2^height)-1
    else
        return (1                                                           +
                total_node_in_full_binary_tree(headPtr->left) +
                total_node_in_full_binary_tree(headPtr->right) );
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : To check whether tree is Full Binary Tree or not.
    Parameter : headPtr (In) : Head Pointer
    Return :    -1  -> When Binary Tree is NULL
                YES -> When Binary Tree is Full Binary Tree
                NO  -> When Binary Tree is not Full Binary Tree
*/
int is_tree_a_full_binary_tree(BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return -1;

    if(NULL == headPtr->left && headPtr->right == NULL)
    {
        // Reach to leaf node
        return YES; 
    }
    else if(headPtr->left && headPtr->right)
    {
        // left & right both present, so go inside the tree 
        if(NO == is_tree_a_full_binary_tree(headPtr->left))
            return NO;
        else if (NO == is_tree_a_full_binary_tree(headPtr->right))
            return NO;
        else {
            return YES;
        }
    }
    else
    {
        // Either left or right is missing in tree
        return NO;
    }
}

int delete_node_from_full_binary_tree (BINARY_TREE ** headPtr, int data)
{
    if(is_binary_tree_empty(*headPtr))
        return -1;

    if(data == (*headPtr)->data)
    {
        if((NULL == (*headPtr)->left) || (NULL == (*headPtr)->right))
        {
            return FAIL;
        }
        else
        {
            delete_binary_tree(&(*headPtr)->left);
            delete_binary_tree(&(*headPtr)->right);
            return SUCCESS;
        }
    }
    else
    {
        if(SUCCESS == delete_node_from_full_binary_tree(&(*headPtr)->left, data))
            return SUCCESS;
        else if(SUCCESS == delete_node_from_full_binary_tree(&(*headPtr)->right, data))
            return SUCCESS;
        else
            return FAIL;
    }
}

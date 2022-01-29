#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "Complete_BinaryTree.h"
#include "../BinaryCommon.c"    // As Make File is not completed, need to add .c
                                // Chnage it to .h once makefile is ready


/*
                __10__
               /      \
              20      30
             /  \    /
            40  50  60
*/

unsigned int find_left_tree_height (BINARY_TREE * headPtr);
unsigned int find_right_tree_height (BINARY_TREE * headPtr);

int main (int argc, char ** argv)
{
    BINARY_TREE * headPtr = NULL;

    headPtr = create_binary_tree(10);
    headPtr->left = create_binary_tree(20);
    headPtr->right = create_binary_tree(30); 
    headPtr->left->left = create_binary_tree(40);
    headPtr->left->right = create_binary_tree(50);
    headPtr->right->left = create_binary_tree(60);
    headPtr->right->right = create_binary_tree(70);
    headPtr->left->left->left = create_binary_tree(80);

    printf(" Total no of Node : [%d]\n", total_number_of_node_in_complete_binary_tree(headPtr));
    printf(" Binary Tree Size : [%d]\n", total_node_in_binary_tree(headPtr));

    if(is_tree_a_complete_tree(headPtr))
        printf(" Given Binary Tree is Complete Binary Tree\n");
    else
        printf(" Given Binary Tree is not a Complete Binary Tree\n");

    delete_binary_tree(&headPtr);
    printf("--- --- --- --- ---\n");
    printf(" Binary Tree Size : [%d]\n", total_node_in_binary_tree(headPtr));

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
    Description : Get the total number of nodes present in Complete Binary Tree.
    Parameter : headPtr (In) -> Head Pointer
    Return :    Number of nodes in Complete Binary Tree pointer by headPtr
    NOTE : This function only works when tree is Complete Binary Tree
    Time Complexity :   O( (log n)^2 ) --> n is the number of nodes
    Space Complexity :  O( log n )
                        Auxilary Space Complexity will come in order to count the height

    Check total_node_in_binary_tree and compare the Complexity

*/
unsigned int  total_number_of_node_in_complete_binary_tree (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return 0;

    unsigned int leftTreeHeight = find_left_tree_height(headPtr);
    unsigned int rightTreeHeight = find_right_tree_height(headPtr);

    if(leftTreeHeight == rightTreeHeight)       // This represent Full Binary Tree so
        return ((1<<leftTreeHeight) -1) ;       // total node = (2^height)-1
    else
        return (1                                                           +
                total_number_of_node_in_complete_binary_tree(headPtr->left) +
                total_number_of_node_in_complete_binary_tree(headPtr->right) );
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : To check whether tree is Complete Binary Tree or not.
    Parameter : headPtr (In) : Head Pointer
    Return :    -1  -> When Binary Tree is NULL
                YES -> When Binary Tree is Complete Binary Tree
                NO  -> When Binary Tree is not Complete Binary Tree
*/
int is_tree_a_complete_tree(BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return -1;

    if(NULL == headPtr->left) {
        if(NULL == headPtr->right)  return YES; // Reach to leaf node
        else                        return NO;  // Node has no left but it has right
    }

    if(NO == is_tree_a_complete_tree(headPtr->left))        // Check on left side
        return NO;
    else if(NO == is_tree_a_complete_tree(headPtr->right))  // Check on right side
        return NO;
    else
        return YES;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "../BinaryCommon.c"    // As Make File is not completed, need to add .c
                                // Chnage it to .h once makefile is ready
#include "Complete_BinaryTree.h"

/*
                 ______10______
                /              \
              _20__          __30_
             /     \        /     \
            40     50      60      70
           /  \   /  \    /  \    /  \
          80  90 100 110 120 130 140 150
*/

unsigned int find_left_tree_height (BINARY_TREE * rootPtr);
unsigned int find_right_tree_height (BINARY_TREE * rootPtr);

int main (int argc, char ** argv)
{
    BINARY_TREE * rootPtr = NULL;

    rootPtr = create_binary_tree(10);
    rootPtr->left = create_binary_tree(20);
    rootPtr->right = create_binary_tree(30); 
    rootPtr->left->left = create_binary_tree(40);
    rootPtr->left->right = create_binary_tree(50);
    rootPtr->right->left = create_binary_tree(60);
    rootPtr->right->right = create_binary_tree(70);
    rootPtr->left->left->left = create_binary_tree(80);

    // rootPtr->left->left->right = create_binary_tree(90);
    // rootPtr->left->right->left = create_binary_tree(100);
    // rootPtr->left->right->right = create_binary_tree(110);
    // rootPtr->right->left->left = create_binary_tree(120);
    // rootPtr->right->left->right = create_binary_tree(130);
    // rootPtr->right->right->left = create_binary_tree(140);
    // rootPtr->right->right->right = create_binary_tree(150);

    printf(" Total no of Node : [%d]\n", total_node_in_complete_binary_tree(rootPtr));
    printf(" Complete Binary Tree Size : [%d]\n", total_node_in_binary_tree(rootPtr));

    if(is_tree_a_complete_tree(rootPtr))
        printf(" Given Binary Tree is Complete Binary Tree\n");
    else
        printf(" Given Binary Tree is not a Complete Binary Tree\n");

    delete_binary_tree(&rootPtr);
    printf("--- --- Delete Complete Binary Tree --- ---\n");
    printf(" Complete Binary Tree Size : [%d]\n", total_node_in_binary_tree(rootPtr));

    return -1;
}

unsigned int find_left_tree_height (BINARY_TREE * rootPtr)
{
    unsigned int height = 0;
    while(rootPtr)
    {
        height+=1;
        rootPtr = rootPtr->left;
    }
    return height;
}

unsigned int find_right_tree_height (BINARY_TREE * rootPtr)
{
    unsigned int height = 0;
    while(rootPtr)
    {
        height+=1;
        rootPtr = rootPtr->right;
    }
    return height;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Get the total number of nodes present in Complete Binary Tree.
    Parameter : rootPtr (In) -> Head Pointer
    Return :    Number of nodes in Complete Binary Tree pointer by rootPtr
    NOTE : This function only works when tree is Complete Binary Tree
    Time Complexity :   O( (log n)^2 ) --> n is the number of nodes
    Space Complexity :  O( log n )
                        Auxilary Space Complexity will come in order to count the height

    Check total_node_in_binary_tree and compare the Complexity

*/
unsigned int  total_node_in_complete_binary_tree (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return 0;

    unsigned int leftTreeHeight = find_left_tree_height(rootPtr);
    unsigned int rightTreeHeight = find_right_tree_height(rootPtr);

    if(leftTreeHeight == rightTreeHeight)       // This represent Perfect Binary Tree so
        return ((1<<leftTreeHeight) -1) ;       // total node = (2^height)-1
    else
        return (1                                                           +
                total_node_in_complete_binary_tree(rootPtr->left) +
                total_node_in_complete_binary_tree(rootPtr->right) );
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : To check whether tree is Complete Binary Tree or not.
    Parameter : rootPtr (In) : Head Pointer
    Return :    -1  -> When Binary Tree is NULL
                YES -> When Binary Tree is Complete Binary Tree
                NO  -> When Binary Tree is not Complete Binary Tree
*/
int is_tree_a_complete_tree(BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return -1;

    if(NULL == rootPtr->left) {
        if(NULL == rootPtr->right)  return YES; // Reach to leaf node
        else                        return NO;  // Node has no left but it has right
    }

    if(NO == is_tree_a_complete_tree(rootPtr->left))        // Check on left side
        return NO;
    else if(NO == is_tree_a_complete_tree(rootPtr->right))  // Check on right side
        return NO;
    else
        return YES;
}
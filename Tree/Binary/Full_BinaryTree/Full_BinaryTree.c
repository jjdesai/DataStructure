#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "../PrintMyBinaryTree.c"
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

unsigned int find_left_tree_height (BINARY_TREE * rootPtr);
unsigned int find_right_tree_height (BINARY_TREE * rootPtr);

bool delete_binary_tree_without_root (BINARY_TREE ** rootPtr);

int main (int argc, char ** argv)
{
    BINARY_TREE * rootPtr = NULL, * headPtr1 = NULL;

    rootPtr = create_binary_tree(10);

    rootPtr->left = create_binary_tree(20);
    rootPtr->right = create_binary_tree(30);

    rootPtr->left->left = create_binary_tree(40);
    rootPtr->left->right = create_binary_tree(50);
    rootPtr->right->left = create_binary_tree(60);
    rootPtr->right->right = create_binary_tree(70);

    rootPtr->left->left->left = create_binary_tree(80);
    rootPtr->left->left->right = create_binary_tree(90);
    rootPtr->left->right->left = create_binary_tree(100);
    rootPtr->left->right->right = create_binary_tree(110);
    rootPtr->right->left->left = create_binary_tree(120);
    rootPtr->right->left->right = create_binary_tree(130);
    rootPtr->right->right->left = create_binary_tree(140);
    rootPtr->right->right->right = create_binary_tree(150);

    printf(" Total no of Node : [%d]\n", total_node_in_full_binary_tree(rootPtr));
    printf(" Full Binary Tree Size : [%d]\n", total_node_in_binary_tree(rootPtr));

    printf("\n\n");
    print_my_binary_tree(rootPtr);
    printf("\n\n");

    // To Check delete_node_from_full_binary_tree
    // printf(" Deleting 120 : [%d]\n", delete_node_from_full_binary_tree(&rootPtr, 120));  // Node can not delete
    // printf(" Deleting 20 : [%d]\n", delete_node_from_full_binary_tree(&rootPtr, 20));    // Node will be deleted
    // printf(" Deleting 220 : [%d]\n", delete_node_from_full_binary_tree(&rootPtr, 220));  // Node is not present
    // printf(" Deleting 10 : [%d]\n", delete_node_from_full_binary_tree(&headPtr1, 10));   // Node is null

    if(is_tree_a_full_binary_tree(rootPtr))
        printf(" Given Binary Tree is a Full Binary Tree\n");
    else
        printf(" Given Binary Tree is not a Full Binary Tree\n");

    delete_binary_tree(&rootPtr);
    printf("--- --- Delete Full Binary Tree --- ---\n");
    printf(" Full Binary Tree Size : [%d]\n", total_node_in_binary_tree(rootPtr));

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
    Description : Get the total number of nodes present in Full Binary Tree.
    Parameter : rootPtr (In) -> Head Pointer
    Return :    Number of nodes in Full Binary Tree pointer by rootPtr
    NOTE : This function only works when tree is Full Binary Tree
    Time Complexity :   O( (log n)^2 ) --> n is the number of nodes
    Space Complexity :  O( log n )
                        Auxilary Space Complexity will come in order to count the height

    Check total_node_in_binary_tree and compare the Complexity

*/
unsigned int total_node_in_full_binary_tree (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return 0;

    unsigned int leftTreeHeight = find_left_tree_height(rootPtr);
    unsigned int rightTreeHeight = find_right_tree_height(rootPtr);

    if(leftTreeHeight == rightTreeHeight)       // This represent Perfect Binary Tree so
        return ((1<<leftTreeHeight) -1) ;       // total node = (2^height)-1
    else
        return (1                                                           +
                total_node_in_full_binary_tree(rootPtr->left) +
                total_node_in_full_binary_tree(rootPtr->right) );
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : To check whether tree is Full Binary Tree or not.
    Parameter : rootPtr (In) : Head Pointer
    Return :    -1  -> When Binary Tree is NULL
                YES -> When Binary Tree is Full Binary Tree
                NO  -> When Binary Tree is not Full Binary Tree
*/
int is_tree_a_full_binary_tree(BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return -1;

    if(NULL == rootPtr->left && rootPtr->right == NULL)
    {
        // Reach to leaf node
        return YES; 
    }
    else if(rootPtr->left && rootPtr->right)
    {
        // left & right both present, so go inside the tree 
        if(NO == is_tree_a_full_binary_tree(rootPtr->left))         // Travel on left Sub-Tree
            return NO;
        else if (NO == is_tree_a_full_binary_tree(rootPtr->right))  // Travel on right Sub-Tree
            return NO;
        else
            return YES;
    }
    else
    {
        // Either left or right is missing in tree
        return NO;
    }
}

int delete_node_from_full_binary_tree (BINARY_TREE ** rootPtr, int data)
{
    if(is_binary_tree_empty(*rootPtr))
        return -1;

    if(data == (*rootPtr)->data)
    {
        // data found on Full Binary Tree
        if((NULL == (*rootPtr)->left) || (NULL == (*rootPtr)->right))
        {
            // data found on leaf node, no need to delete. 
            return FAIL;
        }
        else
        {
            // data found on internal node, need to delete entire left and right sub tree
            delete_binary_tree(&(*rootPtr)->left);
            delete_binary_tree(&(*rootPtr)->right);
            return SUCCESS;
        }
    }
    else
    {
        // data not found on Full Binary Tree 
        if(SUCCESS == delete_node_from_full_binary_tree(&(*rootPtr)->left, data))           // Check on left Sub-Tree
            return SUCCESS;
        else if(SUCCESS == delete_node_from_full_binary_tree(&(*rootPtr)->right, data))     // Check on right Sub-Tree
            return SUCCESS;
        else
            return FAIL;
    }
}

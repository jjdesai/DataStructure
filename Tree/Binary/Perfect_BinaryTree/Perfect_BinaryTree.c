#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "../PrintMyBinaryTree.c"
#include "../BinaryCommon.c"    // As Make File is not completed, need to add .c
                                // Chnage it to .h once makefile is ready
#include "Perfect_BinaryTree.h"

/*
                 ______10______
                /              \
              _20__          __30_
             /     \        /     \
            40     50      60      70
           /  \   /  \    /  \    /  \
          80  90 100 110 120 130 140 150
*/

int main(int argc, char ** argv)
{
    BINARY_TREE * rootPtr = NULL, * rootPtr1 = NULL;

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

    lowest_common_ancestor_in_binary_tree(rootPtr, 50, 90);
    lowest_common_ancestor_in_binary_tree(rootPtr, 50, 100);

    print_my_binary_tree(rootPtr);

    printf(" Total no of Node : [%lu]\n", total_node_in_perfect_binary_tree(rootPtr));

    if(is_tree_a_perfect_binary_tree(rootPtr))
        printf(" Given Binary Tree is a Perfect Binary Tree\n");
    else
        printf(" Given Binary Tree is not a Perfect Binary Tree\n");

    delete_binary_tree(&rootPtr);

    printf(" Total no of Node : [%lu]\n", total_node_in_perfect_binary_tree(rootPtr));
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the height Perfect Binary Tree
    Parameter : rootPtr (In) -> Head Pointer 
    Return :    Return the height of Perfect Binary Tree
*/
unsigned int get_height_of_perfect_binary_tree (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return 0;
    else
        return (1 + get_height_of_perfect_binary_tree(rootPtr->left));
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Count the total number of nodes in Perfect Binary Tree
    Parameter : rootPtr (In) -> Head Pointer 
    Return :    Return the number of nodes present in Perfect Binary Tree
*/
long unsigned int total_node_in_perfect_binary_tree (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return 0;
    else
    {
        unsigned int height = get_height_of_perfect_binary_tree(rootPtr);
        long unsigned int totalNode = 1;
        for(int i=0; i<height; i++)
            totalNode *= 2;
        return totalNode-1;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Will check whether tree is Perfect Binary Tree or not
    Parameter : rootPtr (In) -> Head Pointer 
    Return :    0 --> If Tree is not Perfect Binary Tree
                1 --> If Tree is Perfect Binary Tree
*/
int is_tree_a_perfect_binary_tree (BINARY_TREE * rootPtr)
{
    unsigned int treeSize = 0;
    unsigned int totalNodeFromHeight = 0;
    
    totalNodeFromHeight = total_node_in_perfect_binary_tree(rootPtr);
    
    treeSize = total_node_in_binary_tree(rootPtr);

    return (totalNodeFromHeight == treeSize);
}
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

    printf(" Total no of Node : [%lu]\n", total_node_in_perfect_binary_tree(headPtr));

}

unsigned int get_height_of_perfect_binary_tree (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return 0;
    else
        return (1 + get_height_of_perfect_binary_tree(headPtr->left));
}

long unsigned int total_node_in_perfect_binary_tree (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return 0;
    else
    {
        unsigned int height = get_height_of_perfect_binary_tree(headPtr);
        long unsigned int total_node = 1;
        for(int i=0; i<height; i++)
            total_node *= 2;
        return ((1<<height) - 1);
    }
}


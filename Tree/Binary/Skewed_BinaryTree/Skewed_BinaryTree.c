#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "../PrintMyBinaryTree.c"
#include "../BinaryCommon.c"    // As Make File is not completed, need to add .c
                                // Chnage it to .h once makefile is ready
#include "Skewed_BinaryTree.h"

void create_left_skewed (BINARY_TREE ** headPtr);
void create_right_skewed (BINARY_TREE ** headPtr);
void create_mix_skewed (BINARY_TREE ** headPtr);

int main(int argc, char ** argv)
{
    BINARY_TREE * leftSkewedHeadPtr = NULL;
    BINARY_TREE * rightSkewedHeadPtr = NULL;
    BINARY_TREE * mixSkewedHeadPtr = NULL;

    create_left_skewed(&leftSkewedHeadPtr);
    create_right_skewed(&rightSkewedHeadPtr);
    create_mix_skewed(&mixSkewedHeadPtr);

    printf(" Printing Left Skewed...\n");
    print_my_binary_tree(leftSkewedHeadPtr);
    printf(" Printing Right Skewed...\n");
    print_my_binary_tree(rightSkewedHeadPtr);
    printf(" Printing Mix Skewed...\n");
    print_my_binary_tree(mixSkewedHeadPtr);
    printf("Start Operations...\n");

    printf(" To check Left : [%s]\n", is_tree_a_left_skewed_binary_tree(leftSkewedHeadPtr)?"YES":"NO");
    printf(" To check Mix : [%s]\n", is_tree_a_mix_skewed_binary_tree(mixSkewedHeadPtr)?"YES":"NO");

    delete_binary_tree(&leftSkewedHeadPtr);
    delete_binary_tree(&rightSkewedHeadPtr);
    delete_binary_tree(&mixSkewedHeadPtr);

    return 0;

}

void create_left_skewed (BINARY_TREE ** headPtr)
{
    if(headPtr)
    {
        *headPtr = create_binary_tree(10);                                  //         10
        (*headPtr)->left = create_binary_tree(20);                          //       20
        (*headPtr)->left->left = create_binary_tree(30);                    //     30
        (*headPtr)->left->left->left = create_binary_tree(40);              //   40
        (*headPtr)->left->left->left->left = create_binary_tree(50);        // 50
    }
}

void create_right_skewed (BINARY_TREE ** headPtr)
{
    if(headPtr)
    {
        *headPtr = create_binary_tree(10);                                  // 10
        (*headPtr)->right = create_binary_tree(20);                         //   20
        (*headPtr)->right->right = create_binary_tree(30);                  //     30
        (*headPtr)->right->right->right = create_binary_tree(40);           //       40
        (*headPtr)->right->right->right->right = create_binary_tree(50);    //         50
    }
}

void create_mix_skewed (BINARY_TREE ** headPtr)
{
    if(headPtr)
    {
        *headPtr = create_binary_tree(10);                                //    10
        (*headPtr)->right = create_binary_tree(20);                       //      20
        (*headPtr)->right->left = create_binary_tree(30);                 //    30
        (*headPtr)->right->left->right = create_binary_tree(40);          //      40
        (*headPtr)->right->left->right->left = create_binary_tree(50);    //    50
    }
}

bool is_tree_a_left_skewed_binary_tree (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return YES;
    
    if(headPtr->right)
        return NO;
    else
        return is_tree_a_left_skewed_binary_tree(headPtr->left);
}

bool is_tree_a_right_skewed_binary_tree (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return YES;
    
    if(headPtr->left)
        return NO;
    else
        return is_tree_a_right_skewed_binary_tree(headPtr->right);
}

bool is_tree_a_mix_skewed_binary_tree (BINARY_TREE * headPtr)
{
    if(is_binary_tree_empty(headPtr))
        return YES;

    // Reach to leaf node, return YES
    if((NULL == headPtr->right) && (NULL == headPtr->left))
        return YES;
    // Right is present, but Left is not.
    else if(headPtr->right && (NULL == headPtr->left))
        return is_tree_a_mix_skewed_binary_tree(headPtr->right);
    // Left is present, but Right is not.
    else if(headPtr->left && (NULL == headPtr->right))
        return is_tree_a_mix_skewed_binary_tree(headPtr->left);
    else
        return NO;
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "../PrintMyBinaryTree.c"
#include "../BinaryCommon.c"    // As Make File is not completed, need to add .c
                                // Chnage it to .h once makefile is ready
#include "Skewed_BinaryTree.h"

void create_left_skewed (BINARY_TREE ** rootPtr);
void create_right_skewed (BINARY_TREE ** rootPtr);
void create_mix_skewed (BINARY_TREE ** rootPtr);

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

    printf(" Height of Left : [%d]\n", get_height_of_skewed_binary_tree(leftSkewedHeadPtr));
    printf(" Height of Right : [%d]\n", get_height_of_skewed_binary_tree(rightSkewedHeadPtr));
    printf(" Height of Mix : [%d]\n", get_height_of_skewed_binary_tree(mixSkewedHeadPtr));

    delete_binary_tree(&leftSkewedHeadPtr);
    delete_binary_tree(&rightSkewedHeadPtr);
    delete_binary_tree(&mixSkewedHeadPtr);

    return 0;

}

void create_left_skewed (BINARY_TREE ** rootPtr)
{
    if(rootPtr)
    {
        *rootPtr = create_binary_tree(10);                                  //         10
        (*rootPtr)->left = create_binary_tree(20);                          //       20
        (*rootPtr)->left->left = create_binary_tree(30);                    //     30
        (*rootPtr)->left->left->left = create_binary_tree(40);              //   40
        (*rootPtr)->left->left->left->left = create_binary_tree(50);        // 50
    }
}

void create_right_skewed (BINARY_TREE ** rootPtr)
{
    if(rootPtr)
    {
        *rootPtr = create_binary_tree(10);                                  // 10
        (*rootPtr)->right = create_binary_tree(20);                         //   20
        (*rootPtr)->right->right = create_binary_tree(30);                  //     30
        (*rootPtr)->right->right->right = create_binary_tree(40);           //       40
        (*rootPtr)->right->right->right->right = create_binary_tree(50);    //         50
    }
}

void create_mix_skewed (BINARY_TREE ** rootPtr)
{
    if(rootPtr)
    {
        *rootPtr = create_binary_tree(10);                                //    10
        (*rootPtr)->right = create_binary_tree(20);                       //      20
        (*rootPtr)->right->left = create_binary_tree(30);                 //    30
        (*rootPtr)->right->left->right = create_binary_tree(40);          //      40
        (*rootPtr)->right->left->right->left = create_binary_tree(50);    //    50
    }
}

unsigned int get_height_of_skewed_binary_tree (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return 0;
    else
        return (1                                                                       + 
                ((rootPtr->left) ?  get_height_of_skewed_binary_tree(rootPtr->left) :
                                    get_height_of_skewed_binary_tree (rootPtr->right)));
}

unsigned int total_node_in_skewed_binary_tree (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return 0;
    else
        return (1                                                                       + 
                ( (rootPtr->left) ?  get_height_of_skewed_binary_tree(rootPtr->left) :
                                    get_height_of_skewed_binary_tree (rootPtr->right)));
}

bool is_tree_a_left_skewed_binary_tree (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return YES;
    
    if(rootPtr->right)
        return NO;
    else
        return is_tree_a_left_skewed_binary_tree(rootPtr->left);
}

bool is_tree_a_right_skewed_binary_tree (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return YES;
    
    if(rootPtr->left)
        return NO;
    else
        return is_tree_a_right_skewed_binary_tree(rootPtr->right);
}

bool is_tree_a_mix_skewed_binary_tree (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return YES;

    // Reach to leaf node, return YES
    if((NULL == rootPtr->right) && (NULL == rootPtr->left))
        return YES;
    // Right is present, but Left is not.
    else if(rootPtr->right && (NULL == rootPtr->left))
        return is_tree_a_mix_skewed_binary_tree(rootPtr->right);
    // Left is present, but Right is not.
    else if(rootPtr->left && (NULL == rootPtr->right))
        return is_tree_a_mix_skewed_binary_tree(rootPtr->left);
    else
        return NO;
}
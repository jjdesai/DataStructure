#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "BinaryCommon.h"

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Create a new node and return without checking the allocation.
    Parameter : rootPtr (In) -> Head Pointer 
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
    Parameter : rootPtr (In) -> Head Pointer 
    Return :    NO  --> When rootPtr is NON-NULL
                YES --> When rootPtr is NULL
*/
bool is_binary_tree_empty (BINARY_TREE * rootPtr)
{
    return ((rootPtr) ? NO : YES);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the total number nodes in Binary Tree .
    Parameter : rootPtr (In) -> Head Pointer 
    Return :    0    --> When rootPtr is NULL (No Binary Tree present)
                total number of nodes present in Binary Tree
    Time Complexity : O(n)  -> Travel through each node
    Space Complexity : O(h) -> h is the height of the Binary Tree

*/
unsigned int total_node_in_binary_tree (BINARY_TREE * rootPtr)
{
    if(NULL == rootPtr)
        return 0;
    else
        return ( 1                                           + 
                 total_node_in_binary_tree(rootPtr->left)    +
                 total_node_in_binary_tree(rootPtr->right) );
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Delete the whole tree below rootPtr.
    Parameter : rootPtr (In) : Head Pointer  
    Return :    FAIL    --> When binary tree is already empty
                SUCCESS --> When binary tree is freeded successfully
*/
bool delete_binary_tree (BINARY_TREE ** rootPtr)
{
    if(is_binary_tree_empty(*rootPtr))
        return FAIL;
    else
    {
        delete_binary_tree(&((*rootPtr)->left));
        delete_binary_tree(&((*rootPtr)->right));
        FREE_BINARY_TREE_NODE((*rootPtr));
        return SUCCESS;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the height of Binary Tree.
    Parameter : rootPtr (In) : Head Pointer
    Return :    0 -> When Binary Tree is NULL
                Height of the Binary Tree 
*/
unsigned int get_binary_tree_height (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return 0;
    else
    {
        int leftHeight = get_binary_tree_height(rootPtr->left);
        int rightHeight = get_binary_tree_height(rootPtr->right);
        return (leftHeight > rightHeight) ? (leftHeight+1) : (rightHeight+1);
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in pre-order (Root->Left->Right).
    Parameter : rootPtr (In) -> Head Pointer
*/
void print_in_preorder (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return;

    printf("%d ", rootPtr->data);
    print_in_preorder(rootPtr->left);
    print_in_preorder(rootPtr->right);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in in-order (Left->Root->Right).
    Parameter : rootPtr (In) -> Head Pointer
*/
void print_in_inorder (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return;

    print_in_inorder(rootPtr->left);
    printf("%d ", rootPtr->data);
    print_in_inorder(rootPtr->right);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in post-order (Left->Right->Root).
    Parameter : rootPtr (In) -> Head Pointer
*/
void print_in_postorder (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return;

    print_in_postorder(rootPtr->left);
    print_in_postorder(rootPtr->right);
    printf("%d ", rootPtr->data);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the root node data.
    Parameter : rootPtr (In) : Head Pointer  
    Return :    -1    --> When Binary Tree is empty
                Data  --> Return the first node data
*/
int get_root_node_data (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return -1;
    else
        return rootPtr->data;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the sibling.
    Parameter : rootPtr (In) : Head Pointer
                data (In)    : Data whose sibling needs to find
    Return :    -1    --> When sibling is not found
                Sibling data --> Return sibling data 
*/
int get_siblings (BINARY_TREE * rootPtr, int data)
{
    if(is_binary_tree_empty(rootPtr))
        return -1;
    else
    {
        if(rootPtr->left && rootPtr->right)
        {
            int ret = -1; 
            if(rootPtr->left->data == data)
                return rootPtr->right->data;
            else if(rootPtr->right->data == data)
                return rootPtr->left->data;
            else if(-1 != (ret = get_siblings(rootPtr->left, data)))
                return ret;
            else if(-1 != (ret = get_siblings(rootPtr->right, data)))
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
    Parameter : rootPtr (In) : Head Pointer
    Return :    -1    --> When sibling is not found
                sibling data --> Return sibling data 
*/
bool is_sibling (BINARY_TREE * rootPtr, int data1, int data2)
{
    if(is_binary_tree_empty(rootPtr))
        return NO;
    else
    {
        if(rootPtr->left && rootPtr->right)
        {
            if( ((rootPtr->left->data == data1) && (rootPtr->right->data == data2)) ||
                ((rootPtr->right->data == data1) && (rootPtr->left->data == data2))   )
            {
                return YES;
            }
            if(YES == is_sibling(rootPtr->left, data1, data2))
                return YES;
            else if(YES == is_sibling(rootPtr->right, data1, data2))
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
    Parameter : rootPtr (In) : Head Pointer  
    Return :    Print the internal nodes 
*/
void print_internal_node (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return;

    if(rootPtr->left || rootPtr->right)
        printf("%d ", rootPtr->data);

    if(rootPtr->left)
        print_internal_node(rootPtr->left);
    if(rootPtr->right)
        print_internal_node(rootPtr->right);

}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Print the leaf nodes (Leaf node is the one who has no child).
    Parameter : rootPtr (In) : Head Pointer  
    Return :    Print the leaf nodes 
*/
void print_leaf_node (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return;

    if( (NULL == rootPtr->left) &&
        (NULL == rootPtr->right) )
        printf("%d ", rootPtr->data);

    if(rootPtr->left)
        print_leaf_node(rootPtr->left);
    if(rootPtr->right)
        print_leaf_node(rootPtr->right);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Print the ancestors (Path to data).
    Parameter : rootPtr (In) : Head Pointer
                data (In)    : Data till which path needs to print
    Return :    Print the ancestor 
*/
bool print_ancestor (BINARY_TREE * rootPtr, int data)
{
    if(is_binary_tree_empty(rootPtr))
        return NO;

    if(data == rootPtr->data)
    {
        printf("%d ", rootPtr->data);
        return YES;
    }

    if( print_ancestor(rootPtr->left, data) ||
        print_ancestor(rootPtr->right, data) )
    {
        printf("%d ", rootPtr->data);
        return YES;
    }
    else
        return NO;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Print the descendant (Path after data).
    Parameter : rootPtr (In) : Head Pointer
                data (In)    : Data after which path needs to print
    Return :    Print the descendants 
*/
void print_descendant (BINARY_TREE * rootPtr, int data)
{
    if(is_binary_tree_empty(rootPtr))
        return;
    
    if(rootPtr->data == data)
    {
        print_in_inorder(rootPtr);
    }
    else
    {
        print_descendant(rootPtr->left, data);
        print_descendant(rootPtr->right, data);
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the height.
    Parameter : rootPtr (In) : Head Pointer
    Return :    0 -> NULL Tree
                Height of the Binary Tree 
*/
unsigned int get_height_of_binary_tree (BINARY_TREE * rootPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return 0;
    else
    {
        int leftHeight = get_height_of_binary_tree(rootPtr->left);
        int rightHeight = get_height_of_binary_tree(rootPtr->right);
        return (leftHeight > rightHeight) ? (leftHeight+1) : (rightHeight+1);
    }
}

static void print_left_side_view(BINARY_TREE * rootPtr, int currentLevel, unsigned int * maxLevelTravelPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return;
    
    if(currentLevel == (*maxLevelTravelPtr))
    {
        printf(" %d", rootPtr->data);
        *maxLevelTravelPtr = (*maxLevelTravelPtr)+1;
    }

    print_left_side_view(rootPtr->left, currentLevel+1, maxLevelTravelPtr);
    print_left_side_view(rootPtr->right, currentLevel+1, maxLevelTravelPtr);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : This will print the left view of the binary tree pointed by rootPtr.
    Parameter : rootPtr (In) : Head Pointer
    Return :    void 
*/
void print_left_side_view_of_binary_tree (BINARY_TREE * rootPtr)
{
    if(rootPtr)
    {
        unsigned int maxLevelTravel=0;
        printf(" Left side View :");
        print_left_side_view(rootPtr, 0, &maxLevelTravel);
        printf("\n");
    }
    else
    {
        printf(" RootPtr found as NULL\n");
    }
}

static void print_right_side_view(BINARY_TREE * rootPtr, int currentLevel, unsigned int * maxLevelTravelPtr)
{
    if(is_binary_tree_empty(rootPtr))
        return;
    
    if(currentLevel == (*maxLevelTravelPtr))
    {
        printf(" %d", rootPtr->data);
        *maxLevelTravelPtr = (*maxLevelTravelPtr)+1;
    }

    print_right_side_view(rootPtr->right, currentLevel+1, maxLevelTravelPtr);
    print_right_side_view(rootPtr->left, currentLevel+1, maxLevelTravelPtr);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : This will print the right view of the binary tree pointed by rootPtr.
    Parameter : rootPtr (In) : Head Pointer
    Return :    void 
*/
void print_right_side_view_of_binary_tree (BINARY_TREE * rootPtr)
{
    if(rootPtr)
    {
        unsigned int maxLevelTravel=0;
        printf(" Right side View :");
        print_right_side_view(rootPtr, 0, &maxLevelTravel);
        printf("\n");
    }
    else
    {
        printf(" RootPtr found as NULL\n");
    }
}

static BINARY_TREE * find_data_node_from_binary_tree (BINARY_TREE * rootPtr, unsigned int data)
{
    if(is_binary_tree_empty(rootPtr))
        return NULL;
    else
    {
        if(rootPtr->data == data)
            return rootPtr;
        BINARY_TREE * retPtr = find_data_node_from_binary_tree(rootPtr->left, data);
        if(retPtr)
            return retPtr;
        retPtr = find_data_node_from_binary_tree(rootPtr->right, data);
        if(retPtr)
            return retPtr;
    }
}

static BINARY_TREE * lowest_common_ancestor (BINARY_TREE * rootPtr, BINARY_TREE * data1NodePtr, BINARY_TREE * data2NodePtr)
{
    if((rootPtr == NULL) || (rootPtr == data1NodePtr) || (rootPtr == data2NodePtr))
        return rootPtr;
    else
    {
        BINARY_TREE * leftPtr = lowest_common_ancestor(rootPtr->left, data1NodePtr, data2NodePtr);
        BINARY_TREE * rightPtr = lowest_common_ancestor(rootPtr->right, data1NodePtr, data2NodePtr);
        if(leftPtr == NULL)
            return rightPtr;
        else if(rightPtr == NULL)
            return leftPtr;
        else
        {
            // Both Left and Right is not NULL, we've found our result
            return rootPtr;
        }
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the Lowest Common Ancestor between data1 & data2 from given binary tree rootPtr.
    Parameter : rootPtr (In) : Head Pointer
                data1 (In) & data2 (In) -> data1 & data2 whose LCA needs to find out
    Return :    -1 -> Negative Case
                Return the data of node which is the Lowest Common Ancestor 
*/
int lowest_common_ancestor_in_binary_tree (BINARY_TREE * rootPtr, unsigned int data1, unsigned int data2)
{
    if(is_binary_tree_empty(rootPtr))
        return -1;
    else
    {
        BINARY_TREE * data1NodePtr = find_data_node_from_binary_tree(rootPtr, data1);
        BINARY_TREE * data2NodePtr = find_data_node_from_binary_tree(rootPtr, data2);

        if(data1NodePtr && data2NodePtr)
        {
            BINARY_TREE * lcaPtr = lowest_common_ancestor(rootPtr, data1NodePtr, data2NodePtr);
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
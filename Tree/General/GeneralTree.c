#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "GeneralTree.h"

/*
                    10
                ___/  \___
               /          \
              20          30
             /  \        /  \
           40   50     60    70
           /   /  \            \
          80  90  100          110

        0   |1   2   |3   4   5   6   |7   8   9   10  11  12  13  14
        10  |20  30  |40  50  60  70  |80  -1  100 90  -1  -1  -1  110
*/


int main ()
{
    GENERAL_TREE * headPtr = NULL;

    insert_in_tree(&headPtr, 10, POSITION_ROOT);             // HEAD -> 10
    insert_in_tree(&headPtr, 20, POSITION_LEFT);             // 10->(left)->20
    insert_in_tree(&headPtr, 30, POSITION_RIGHT);            // 10->(right)->30
    
    insert_in_tree(&headPtr->left, 40, POSITION_LEFT);       // 20->(left)->40
    insert_in_tree(&headPtr->left, 50, POSITION_RIGHT);      // 20->(right)->50
    
    insert_in_tree(&headPtr->right, 60, POSITION_LEFT);      // 30->(left)->60
    insert_in_tree(&headPtr->right, 70, POSITION_RIGHT);     // 30->(right)->70

    insert_in_tree(&headPtr->left->left, 80, POSITION_LEFT);    // 40->(left)->80
    insert_in_tree(&headPtr->left->right, 90, POSITION_LEFT);   // 50->(left)->90
    insert_in_tree(&headPtr->left->right, 100, POSITION_RIGHT); // 50->(right)->100
     

    insert_in_tree(&headPtr->right->right, 110, POSITION_RIGHT);   // 70->(right)->110

    printf(" General Tree Size : [%d]\n", size_of_general_tree(headPtr));

    printf(" Pre-Order\t: ");
    print_in_preorder(headPtr);
    printf("\n");

    printf(" Post-Order\t: ");
    print_in_postorder(headPtr);
    printf("\n");

    printf(" In-Order\t: ");
    print_in_inorder(headPtr);
    printf("\n");

    printf(" Data 5 is [%s]\n", is_data_present_in_tree(headPtr, 5) ? "Present" : "Absent");
    printf(" Data 100 is [%s]\n", is_data_present_in_tree(headPtr, 100) ? "Present" : "Absent");
    printf(" Data 10 is [%s]\n", is_data_present_in_tree(headPtr, 10) ? "Present" : "Absent");

    printf(" Root Node Data : [%d]\n", get_root_node_data(headPtr));

    printf(" 10 Sibling 20 [%s]\n", is_sibling(headPtr, 10, 20) ? "YES" : "NO");
    printf(" 90 Sibling 100 [%s]\n", is_sibling(headPtr, 90, 100) ? "YES" : "NO");
    printf(" 90 Sibling 100 [%s]\n", is_sibling(headPtr, 100, 90) ? "YES" : "NO");

    printf(" Another Sibling of 10 is [%d]\n", get_siblings(headPtr, 10));
    printf(" Another Sibling of 70 is [%d]\n", get_siblings(headPtr, 70));
    printf(" Another Sibling of 90 is [%d]\n", get_siblings(headPtr, 90));

    delete_general_tree(&headPtr);
    printf(" -------- \n");
    printf(" Deleting Whole General Tree\n");

    printf(" General Tree Size : [%d]\n", size_of_general_tree(headPtr));
    printf(" Root Node Data : [%d]\n", get_root_node_data(headPtr));

    return -1;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Create a new node and return without checking the allocation.
    Parameter : headPtr (In) -> Head Pointer 
    Return :    New Node
*/
GENERAL_TREE * create_general_tree (int data)
{
    GENERAL_TREE * newGeneralNode = (GENERAL_TREE *) calloc(1, sizeof(GENERAL_TREE));
    if(newGeneralNode)
    {
        newGeneralNode->data = data;
        newGeneralNode->left = NULL;
        newGeneralNode->right = NULL;
    }
    return newGeneralNode;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Check whether tree is empty or not.
    Parameter : headPtr (In) -> Head Pointer 
    Return :    NO  --> When headPtr is NON-NULL
                YES --> When headPtr is NULL
*/
bool is_general_tree_empty (GENERAL_TREE * headPtr)
{
    return ((headPtr) ? NO : YES);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Calculate the size of tree pointed by headPtr.
    Parameter : headPtr (In) -> Head Pointer 
    Return :    0    --> When headPtr is NULL (No Tree present)
                size --> Size of the Tree  (How many node present in Tree)
*/
unsigned int size_of_general_tree (GENERAL_TREE * headPtr)
{
    if(NULL == headPtr)
        return 0;
    else
        return (1 + size_of_general_tree(headPtr->left) + size_of_general_tree(headPtr->right));
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Based on Position at pos, add new node with data in headPtr.
    Parameter : headPtr (In) -> Head Pointer 
                data    (In) -> Data with which new node created
                pos     (IN) -> Belong to E_POSITION.
    Return :    FAIL    --> When headPtr negative or Memory allocation failed
                SUCCESS --> When new node with data is successfully added at pos of headPtr
*/
bool insert_in_tree (GENERAL_TREE ** headPtr, int data, E_POSITION pos)
{
    if(headPtr)
    {
        GENERAL_TREE * newNodePtr = create_general_tree(data); 
        if(newNodePtr)
        {
            switch (pos)
            {
                case POSITION_ROOT: (*headPtr) = newNodePtr;        break;
                case POSITION_LEFT: (*headPtr)->left = newNodePtr;  break;
                case POSITION_RIGHT:(*headPtr)->right = newNodePtr; break;
                default: printf(" Wrong Position selected\n");      break;
            }
            return SUCCESS;
        }
        else
        {
            printf(" Memory allocation failed\n");
            return FAIL;
        }
    }
    else
    {
        return FAIL;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Check data is present in General Tree or not.
    Parameter : headPtr (In) -> Head Pointer 
                data    (In) -> data whose present need to check in tree 
    Return :    NO  --> When data is not present in tree
                YES --> When data is present in tree
*/
bool is_data_present_in_tree (GENERAL_TREE * headPtr, const int data)
{
    if(headPtr == NULL)
        return NO;
    else
    {
        int ret = NO;
        if(data == headPtr->data)
            return YES;
        if(YES == (ret = is_data_present_in_tree(headPtr->left, data)))
            return YES;
        else if(YES == (ret = is_data_present_in_tree(headPtr->right, data)))
            return YES;
        else
            return ret;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in pre-order (Root->Left->Right).
    Parameter : headPtr (In) -> Head Pointer
*/
void print_in_preorder (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
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
void print_in_inorder (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
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
void print_in_postorder (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
        return;

    print_in_postorder(headPtr->left);
    print_in_postorder(headPtr->right);
    printf("%d ", headPtr->data);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Delete the whole tree below headPtr.
    Parameter : headPtr (In) : Head Pointer  
    Return :    FAIL    --> When tree is already empty
                SUCCESS --> When tree is freeded successfully
*/
bool delete_general_tree (GENERAL_TREE ** headPtr)
{
    if(is_general_tree_empty(*headPtr))
        return FAIL;
    else
    {
        delete_general_tree(&((*headPtr)->left));
        delete_general_tree(&((*headPtr)->right));
        FREE_GENERAT_TREE_NODE((*headPtr));
        return SUCCESS;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the root node data.
    Parameter : headPtr (In) : Head Pointer  
    Return :    -1    --> When tree is empty
                Data  --> Return the first node data
*/
int get_root_node_data (GENERAL_TREE * headPtr)
{
    if(is_general_tree_empty(headPtr))
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
                sibling data --> Return sibling data 
*/
int get_siblings (GENERAL_TREE * headPtr, int data)
{
    if(is_general_tree_empty(headPtr))
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
bool is_sibling (GENERAL_TREE * headPtr, int data1, int data2)
{
    if(is_general_tree_empty(headPtr))
        return NO;
    else
    {
        if(headPtr->left && headPtr->right)
        {
            if( (headPtr->left->data == data1) && (headPtr->right->data == data2) ||
                (headPtr->right->data == data1) && (headPtr->left->data == data2)   )
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

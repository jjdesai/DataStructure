#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "GeneralTree.h"

GENERAL_TREE * get_node_from_data (GENERAL_TREE * rootPtr, int parentData);
GENERAL_TREE * get_parent_node_of_data(GENERAL_TREE * rootPtr, int childData);

/*
                            0
                            |
                |-----------|-----------|
                1           2           3
                |           |           |
            |--------|  |---|----|  |--------|
            11  12  13  21  22  23  31  32  33
            |               |                |
         |-----|   |----|---|---|----|    |-----|
        111   112  221 222 223 224 225   331   332
*/

int main ()
{
    GENERAL_TREE * rootPtr = NULL;

    insert_in_general_tree(&rootPtr, 0, 0);
    
    insert_in_general_tree(&rootPtr, 1, 0);
    insert_in_general_tree(&rootPtr, 2, 0);
    insert_in_general_tree(&rootPtr, 3, 0);

    insert_in_general_tree(&rootPtr, 11, 1);
    insert_in_general_tree(&rootPtr, 12, 1);
    insert_in_general_tree(&rootPtr, 13, 1);

    insert_in_general_tree(&rootPtr, 21, 2);
    insert_in_general_tree(&rootPtr, 22, 2);
    insert_in_general_tree(&rootPtr, 23, 2);

    insert_in_general_tree(&rootPtr, 31, 3);
    insert_in_general_tree(&rootPtr, 32, 3);
    insert_in_general_tree(&rootPtr, 33, 3);

    insert_in_general_tree(&rootPtr, 311, 31);

    printf(" General Tree in Pre-Order : ");
    print_general_tree_in_preorder(rootPtr);
    printf("\n");

    printf(" Internal Node : ");
    print_internal_node_of_general_tree(rootPtr);
    printf("\n");

    printf(" Leaf Node : ");
    print_leaf_node_of_general_tree(rootPtr);
    printf("\n");

    printf(" Ancestor of 31 is : ");
    print_ancestor_of_general_tree(rootPtr, 31);
    printf("\n");

    printf(" Descendant of 1 is : ");
    print_descendant_of_general_tree(rootPtr, 1);
    printf("\n");

    printf(" Height of General Tree : [%d]\n", get_height_of_general_tree(rootPtr));

    delete_node_from_general_tree(&rootPtr, 21);

    printf(" General Tree in Pre-Order : ");
    print_general_tree_in_preorder(rootPtr);
    printf("\n");

    printf(" General Tree in Post-Order : ");
    print_general_tree_in_postorder(rootPtr);
    printf("\n");

    printf(" Total Size of General Tree : [%d]\n", total_nodes_in_general_tree(rootPtr));
    printf(" Parent of 22 is [%d]\n", get_parent_of_data(rootPtr, 22));
    printf(" Parent of 2 is [%d]\n", get_parent_of_data(rootPtr, 2));
    printf(" Parent of 0 is [%d]\n", get_parent_of_data(rootPtr, 0));

    delete_general_tree(&rootPtr);

    printf(" Total Size of General Tree : [%d]\n", total_nodes_in_general_tree(rootPtr));

    return 1;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Create a new node and return without checking the allocation.
    Parameter : data (In) -> data to be filled in data-structure 
    Return :    New Node
*/
GENERAL_TREE * creat_general_tree (int data)
{
    GENERAL_TREE * newNodePtr = (GENERAL_TREE *) malloc(sizeof(GENERAL_TREE));
    if(newNodePtr)
    {
        newNodePtr->data = data;
        newNodePtr->degree = 0;
        newNodePtr->childHeadPtr = NULL;
    }
    return newNodePtr;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Check whether tree is empty or not.
    Parameter : rootPtr (In) -> Head Pointer 
    Return :    NO  --> When rootPtr is NON-NULL
                YES --> When rootPtr is NULL
*/
bool is_general_tree_empty (GENERAL_TREE * rootPtr)
{
    return (rootPtr) ? NO : YES;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the total nodes from given general tree pointer at rootPtr.
    Parameter : rootPtr (In) -> Head Pointer 
    Return :    Total number of nodes
*/
unsigned int total_nodes_in_general_tree (GENERAL_TREE * rootPtr)
{
    if(is_general_tree_empty(rootPtr))
        return 0;

    int i;
    int totalNode = 1;
    for(i=0; i<rootPtr->degree; i++)
    {
        totalNode += total_nodes_in_general_tree(rootPtr->childHeadPtr[i]);
    }
    return totalNode;
}

/*
Helper Function of insert_in_general_tree()
*/
GENERAL_TREE * get_node_from_data (GENERAL_TREE * rootPtr, int data)
{
    if(is_general_tree_empty(rootPtr))
        return NULL;
    
    if(rootPtr->data == data)
    {
        return rootPtr;
    }
    else
    {
        unsigned int i;
        GENERAL_TREE * retPtr = NULL;
        for(i=0; i<rootPtr->degree; i++)
        {
            retPtr = get_node_from_data(rootPtr->childHeadPtr[i], data);
            if(retPtr)  break;
        }
        return retPtr;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Insert a new node with data below parentData at General Tree pointer by rootPtr.
    Parameter : rootPtr (In) -> Head Pointer
                data (In) -> Child data with which new node will create
                parentData (In) -> Parent data under which new node will create
    Return :    Total number of nodes
*/
bool insert_in_general_tree (GENERAL_TREE ** rootPtr, unsigned int data, unsigned int parentData)
{
    if(rootPtr)
    {
        GENERAL_TREE * newNodePtr = creat_general_tree(data);
        if(newNodePtr)
        {
            if(*rootPtr)
            {
                GENERAL_TREE * parentNodePtr = get_node_from_data(*rootPtr, parentData);
                if(parentNodePtr)
                {
                    int prevSize = parentNodePtr->degree; 
                    parentNodePtr->degree += 1;
                    parentNodePtr->childHeadPtr = (GENERAL_TREE **) realloc(parentNodePtr->childHeadPtr, parentNodePtr->degree);
                    parentNodePtr->childHeadPtr[prevSize] = newNodePtr;
                    return YES;
                }
                else
                {
                    printf("Parent[%d] Node is not exist\n", parentData);
                    return NO;
                }
            }
            else
            {
                (*rootPtr) = newNodePtr;
                return YES;
            }
        }
    }
    else
    {
        return NO;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in pre-order (Root->Left->Right).
    Parameter : rootPtr (In) -> Head Pointer
*/
void print_general_tree_in_preorder (GENERAL_TREE * rootPtr)
{
    if(is_general_tree_empty(rootPtr))
        return;
    
    printf("%d ", rootPtr->data);
    for(unsigned int i=0; i < rootPtr->degree; i++)
    {
        print_general_tree_in_preorder(rootPtr->childHeadPtr[i]);
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Printing in post-order (Left->Right->Root).
    Parameter : rootPtr (In) -> Head Pointer
*/
void print_general_tree_in_postorder (GENERAL_TREE * rootPtr)
{
    if(is_general_tree_empty(rootPtr))
        return;
    
    for(unsigned int i=0; i < rootPtr->degree; i++)
    {
        print_general_tree_in_postorder(rootPtr->childHeadPtr[i]);
    }
    printf("%d ", rootPtr->data);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Delete the whole general tree pointed by rootPtr.
    Parameter : rootPtr (In) : Head Pointer  
    Return :    FAIL    --> When tree is already empty
                SUCCESS --> When tree is freeded successfully
*/
void delete_general_tree (GENERAL_TREE ** rootPtr)
{
    if(is_general_tree_empty(*rootPtr))
        return;

    for(unsigned int i=0; i<(*rootPtr)->degree; i++)
        delete_general_tree(&((*rootPtr)->childHeadPtr[i]));

    DESTRUCTOR_of_GENERAL_TREE(*rootPtr);
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Delete the particular node/sub-tree with data from general tree pointed by rootPtr.
    Parameter : rootPtr (In) : Head Pointer
                data (In)    : Node/Sub-Tree which needs to be delete 
    Return :    FAIL    --> When General Tree is already empty/ does not have node with data 
                SUCCESS --> When Node/Sub-Tree is freeded successfully

    NOTE : Due to the resolution of bug, this function will not delete root node
*/
bool delete_node_from_general_tree (GENERAL_TREE ** rootPtr, int data)
{
    if(rootPtr)
    {
        if(is_general_tree_empty(*rootPtr))
            return FAIL;
        else
        {
            for(unsigned int i=0; i<(*rootPtr)->degree; i++)
            {
                if(data == (*rootPtr)->childHeadPtr[i]->data)
                {
                    GENERAL_TREE * deletePtr = (*rootPtr)->childHeadPtr[i];
                    delete_general_tree(&(*rootPtr)->childHeadPtr[i]);
                    for(unsigned int j=i; j<((*rootPtr)->degree-1); j++)
                        (*rootPtr)->childHeadPtr[j] = (*rootPtr)->childHeadPtr[j+1];
                    (*rootPtr)->degree -= 1;
                    return SUCCESS;
                }
                else
                {
                    int ret = FAIL;
                    if(SUCCESS == (ret = delete_node_from_general_tree(&(*rootPtr)->childHeadPtr[i], data)))
                        return SUCCESS;
                }
            }
            return FAIL;
        }
    }
    else
        return FAIL;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the root node data.
    Parameter : rootPtr (In) : Head Pointer  
    Return :    -1    --> When tree is empty
                Data  --> Return the first node data
*/
int get_root_node_data (GENERAL_TREE * rootPtr)
{
    if(is_general_tree_empty(rootPtr))
        return -1;
    else
        return rootPtr->data;
}

/*
Helper Function of get_parent_of_data()
*/
GENERAL_TREE * get_parent_node_of_data(GENERAL_TREE * rootPtr, int childData)
{
    if(is_general_tree_empty(rootPtr))
        return NULL;
    else
    {
        GENERAL_TREE * tmpNodePtr = NULL;
        for(unsigned int i=0; i<rootPtr->degree; i++)
        {
            if(rootPtr->childHeadPtr[i]->data == childData)
            {
                return rootPtr;
            }
            else
            {
                tmpNodePtr = get_parent_node_of_data(rootPtr->childHeadPtr[i], childData);
                if(tmpNodePtr)  break;
            }
        }
        return tmpNodePtr;
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the parent node data of childData.
    Parameter : rootPtr (In) : Head Pointer  
                (childData)  : Child data whose parent needs to be return
    Return :    -1    --> When childData is not present, or childnode is root
                Data  --> Return the parent data of childData

    Note : If you pass childData as root data, it will return -1
*/
int get_parent_of_data (GENERAL_TREE * rootPtr, int childData)
{
    GENERAL_TREE * tmpNodePtr = get_parent_node_of_data(rootPtr, childData);
    if(tmpNodePtr)
        return tmpNodePtr->data;
    else
        return -1;
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Print the internel nodes (Internal node is the one who has atleast one child).
    Parameter : rootPtr (In) : Head Pointer  
    Return :    Print the internal nodes 
*/
void print_internal_node_of_general_tree (GENERAL_TREE * rootPtr)
{
    if(is_general_tree_empty(rootPtr))
        return;

    if(rootPtr->degree != 0)
        printf("%d ", rootPtr->data);

    for(unsigned int i=0; i < rootPtr->degree; i++)
    {
        print_internal_node_of_general_tree(rootPtr->childHeadPtr[i]);
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Print the leaf nodes (Leaf node is the one who has no child).
    Parameter : rootPtr (In) : Head Pointer  
    Return :    Print the leaf nodes 
*/
void print_leaf_node_of_general_tree (GENERAL_TREE * rootPtr)
{
    if(is_general_tree_empty(rootPtr))
        return;

    if(rootPtr->degree == 0)
        printf("%d ", rootPtr->data);

    for(unsigned int i=0; i < rootPtr->degree; i++)
    {
        print_leaf_node_of_general_tree(rootPtr->childHeadPtr[i]);
    }
}

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Print the ancestors (Path to data).
    Parameter : rootPtr (In) : Head Pointer
                data (In)    : Data till which path needs to print
    Return :    Print the ancestor 
*/
bool print_ancestor_of_general_tree (GENERAL_TREE * rootPtr, int data)
{
    if(is_general_tree_empty(rootPtr))
        return NO;

    if(data == rootPtr->data)
    {
        printf("%d ", rootPtr->data);
        return YES;
    }

    for(unsigned int i=0; i<rootPtr->degree; i++)
    {
        if(print_ancestor_of_general_tree(rootPtr->childHeadPtr[i], data))
        {
            printf("%d ", rootPtr->data);
            return YES;
        }
    }
    
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
bool print_descendant_of_general_tree (GENERAL_TREE * rootPtr, int data)
{
    if(is_general_tree_empty(rootPtr))
        return NO;
    
    if(rootPtr->data == data)
    {
        print_general_tree_in_preorder(rootPtr);
        return YES;
    }
    else
    {
        for(unsigned int i=0; i<rootPtr->degree; i++)
        {
            if(print_descendant_of_general_tree(rootPtr->childHeadPtr[i], data))
                return YES;
        }
        return NO;
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
unsigned int get_height_of_general_tree_r (GENERAL_TREE * rootPtr, int level)
{
    if(is_general_tree_empty(rootPtr))
    {
        return 0;
    }
    else
    {
        if(rootPtr->degree == 0)
        {
            return level;
            printf(" Data[%d] At level[%d]\n", rootPtr->data, level);
        }

        static unsigned int max = 0; 
        for(unsigned int i=0; i<(rootPtr->degree); i++)
        {
            int ret = get_height_of_general_tree_r(rootPtr->childHeadPtr[i], level+1);
            printf("Ret : %d\n", ret);
            if(max < ret)
                max = ret;
        }
        
        return max;
    }
}

unsigned int get_height_of_general_tree (GENERAL_TREE * rootPtr)
{
    return get_height_of_general_tree_r(rootPtr, 1);
}

#if 0

/*
    Author : Jay Desai      Tester : Jay Desai
    Status : Working
    Description : Return the sibling.
    Parameter : rootPtr (In) : Head Pointer
                data (In)    : Data whose sibling needs to find
    Return :    -1    --> When sibling is not found
                Sibling data --> Return sibling data 
*/
int get_siblings (GENERAL_TREE * rootPtr, int data)
{
    if(is_general_tree_empty(rootPtr))
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
bool is_sibling (GENERAL_TREE * rootPtr, int data1, int data2)
{
    if(is_general_tree_empty(rootPtr))
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
    Description : Return the height.
    Parameter : rootPtr (In) : Head Pointer
    Return :    0 -> NULL Tree
                Height of the tree 
*/
unsigned int get_height (GENERAL_TREE * rootPtr)
{
    if(is_general_tree_empty(rootPtr))
        return 0;
    else
    {
        int leftHeight = get_height(rootPtr->left);
        int rightHeight = get_height(rootPtr->right);
        return (leftHeight > rightHeight) ? (leftHeight+1) : (rightHeight+1);
    }
}

int total_node_at_level (GENERAL_TREE * rootPtr, int level)
{

}

#endif
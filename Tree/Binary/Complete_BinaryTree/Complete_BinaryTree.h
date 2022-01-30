#ifndef _COMPLETE_BINARY_TREE_H_
#define _COMPLETE_BINARY_TREE_H_

    /*

    Complete Binary Defination : 
        A complete binary tree is a binary tree in which all the levels are completely
        filled except possibly the lowest one, which is filled from the left.
        
        A complete binary tree is just like a full binary tree, but with two major differences.
        - All the leaf elements must lean towards the left.
        - The last leaf element might not have a right sibling i.e. a complete binary tree
          doesn't have to be a full binary tree.

        Example :      Figure-1             Figure-2            Figure-3
                        ------               ------              ------
                        __10__               __10__              __10__    
                       /      \             /      \            /      \   
                      20      30           20      30          20      30  
                     /  \    /  \         /       /  \        /  \       \   
                    40  50  60  70       40      60  70      40  50      70
                   /                    /                   /              
                  80                   80                  80              

                  Figure-1, Figure-2 are Complete Binary Tree
                  Figure-3 is not a Complete Binary Tree as there is no left of 30 but it has right
    */

    unsigned int total_node_in_complete_binary_tree (BINARY_TREE * headPtr);
    int is_tree_a_complete_tree (BINARY_TREE * headPtr);

    int delete_node_from_complete_binary_tree (BINARY_TREE * headPtr, int data);

#endif // _COMPLETE_BINARY_TREE_H_
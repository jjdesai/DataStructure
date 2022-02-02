#ifndef _PERFECT_BINARY_TREE_H_
#define _PERFECT_BINARY_TREE_H_

    /*

    Perfect Binary Defination :
        A Perfect Binary Tree is a tree in which all the leaf nodes are at same level. 
    
    Example :             Figure-1                 Figure-2           Figure-3
                           ------                   ------             ------
                       ______10______               __10__             __10__         
                      /              \             /      \           /      \    
                   __20__          __30__         20      30         20      30   
                  /      \        /      \       /  \    /  \       /  \    /  \  
                 40      50      60      70     40  50  60  70     40  50  60  70 
                /  \    /  \    /  \    /  \                      /  \      
               80  90  100 110 120 130 140 150                   80  90

                Figure-1, Figure-2 are Perfect Binary Tree
                Figure-3 is not a Perfect Binary Tree as node 80 & 90 are in different level than 56, 60 & 70.
    */

    unsigned int get_height_of_perfect_binary_tree (BINARY_TREE * headPtr);
    long unsigned int total_node_in_perfect_binary_tree (BINARY_TREE * headPtr);
    int is_tree_a_perfect_binary_tree (BINARY_TREE * headPtr);

#endif // _PERFECT_BINARY_TREE_H_
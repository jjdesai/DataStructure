#ifndef _SKEWED_BINARY_TREE_H_
#define _SKEWED_BINARY_TREE_H_

    /*

    Skewed Binary Defination :
        Skewed Binary Tree is a Binary Tree where every parent node has only one child node.
        Height of a Skewed Binary Tree is equal to Total number of nodes in that tree.

        There is three types of Skewed Binary Tree.
         1. Left Skewed Binary Tree
         2. Right Skewed Binary Tree
         3. Mixed Skewed Binary Tree

    Example :
                    Left Skewed     Right Skewed     Mix Skewed     Mix Skewed     Mix Skewed      
                    -----------     ------------     ----------     ----------     ----------
                          10         10                 10            10                  10
                          /           \                   \             \                /
                         20           20                   20            20            20
                         /             \                  /                \             \
                        30             30               30                  30            30
                        /               \                 \                /             /
                       40               40                 40            40            40
                       /                  \               /             /             /
                      50                  50            50            50            50
    */ 

    typedef enum {

        LEFT_SKEWED_BINARY_TREE,
        RIGHT_SKEWED_BINARY_TREE,
        MIX_SKEWED_BINARY_TREE,
        
    }TYPE_OF_SKEWED_BINARY_TREE;

    unsigned int get_height_of_skewed_binary_tree (BINARY_TREE * headPtr);
    unsigned int total_node_in_skewed_binary_tree (BINARY_TREE * headPtr);

    bool is_tree_a_left_skewed_binary_tree   (BINARY_TREE * headPtr);
    bool is_tree_a_right_skewed_binary_tree  (BINARY_TREE * headPtr);
    bool is_tree_a_mix_skewed_binary_tree    (BINARY_TREE * headPtr);

#endif // _PERFECT_BINARY_TREE_H_
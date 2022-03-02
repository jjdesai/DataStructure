#ifndef _FULL_BINARY_TREE_H_
#define _FULL_BINARY_TREE_H_

    /*

    Full Binary Defination :
        A full binary tree (sometimes referred to as a Proper or Plane or Strict Binary Tree)
        is a tree in which every node has either 0 or 2 children. 
    
    Example :        Figure-1             Figure-2              Figure-3
                      ------               ------                ------
                      __10__               ___10___              __10__    
                     /      \             /        \            /      \   
                    20      30           20      __30__        20      30  
                   /  \    /  \         / \     /      \      /  \       \ 
                  40  50  60  70       40  50  60      70    40  50      70
                 /  \                         /  \    /  \
                80  90                       120 130 140 150 

                Figure-1, Figure-2 are Full/Proper/Strict/Plane Binary Tree
                Figure-3 is not a Full Binary Tree as node 30 has only one child.
    */

    unsigned int total_node_in_full_binary_tree (BINARY_TREE * rootPtr);
    int is_tree_a_full_binary_tree (BINARY_TREE * rootPtr);

    // Deleting node from Full Binary Tree can be done by following method:
    // - Check the data with each node data in Full Binary Tree
    // - If node is leaf node, you can not delete particular node.
    //   (as after deleting leaf node, tree will not remain Full Binary Tree)
    // - If node is internal node, delete whole sub-tree
    int delete_node_from_full_binary_tree (BINARY_TREE ** rootPtr, int data);

#endif // _FULL_BINARY_TREE_H_
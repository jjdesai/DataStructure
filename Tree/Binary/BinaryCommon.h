#ifndef _BINARY_TREE_COMMON_H_
#define _BINARY_TREE_COMMON_H_

    #define SUCCESS 1
    #define FAIL    0

    #define TRUE    1
    #define FALSE   0

    #define YES     1
    #define NO      0

    #define FREE_BINARY_TREE_NODE(VAR)  free(VAR);  \
                                        VAR = NULL; 

    typedef unsigned char bool;

    typedef struct _binary_tree_
    {
        struct _binary_tree_ * left;
        int data;
        struct _binary_tree_ * right;

    }BINARY_TREE;

    typedef enum _position_
    {
        POSITION_ROOT   = 0,
        POSITION_LEFT,
        POSITION_RIGHT,

    }E_POSITION;

    typedef enum _binary_tree_types_
    {
        // https://en.wikipedia.org/wiki/List_of_data_structures

        FULL_BINARY_TREE,       // PROPER_BINARY_TREE, STRICT_BINARY_TREE
        COMPLETE_BINARY_TREE,
        PERFECT_BINARY_TREE,
        BALANCED_BINARY_TREE,
        DEGENERATE_BINARY_TREE,

        MAX_BINARY_TREE_TYPE,

    }BINARY_TREE_TYPE;

    typedef enum _types_of_sel_balancing_binary_search_tree
    {
        // https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree

        T_2_3_TREE,
        AA_TREE,
        AVL_TREE,
        WEAK_AVL_TREE,
        B_TREE,
        RED_BLACK_TREE,
        SCAPEGOAT_TREE,
        SPLAY_TREE,
        TANGO_TREE,
        TREAP_TREE,
        WEIGHT_BALANCED_TREE,

    }TYPES_OF_SELF_BALANCING_BINARY_SEARCH_TREE;

    BINARY_TREE * create_binary_tree  (int data);

    bool is_binary_tree_empty               (BINARY_TREE * headPtr);
    unsigned int total_node_in_binary_tree  (BINARY_TREE * headPtr);

    bool delete_binary_tree                 (BINARY_TREE ** headPtr);
    
    unsigned int get_binary_tree_height     (BINARY_TREE * headPtr);
    
    void print_in_preorder  (BINARY_TREE * headPtr);
    void print_in_inorder   (BINARY_TREE * headPtr);
    void print_in_postorder (BINARY_TREE * headPtr);
    void print_in_list      (BINARY_TREE * headPtr);    // NOTE: Level Order Traversal will require

    int get_root_node_data                  (BINARY_TREE * headPtr);
    int get_siblings                        (BINARY_TREE * headPtr, int data);
    bool is_sibling                         (BINARY_TREE * headPtr, int data1, int data2);
    void print_internal_node                (BINARY_TREE * headPtr);
    int get_internet_node_count             (BINARY_TREE * headPtr);
    void print_leaf_node                    (BINARY_TREE * headPtr);   // Same --> void print_external_node    (BINARY_TREE * headPtr);
    int get_breadth_of_binary_tree          (BINARY_TREE * headPtr);   // The number of leaves
    bool print_ancestor                     (BINARY_TREE * headPtr, int data);     // Root to data path
    void print_descendant                   (BINARY_TREE * headPtr, int data);     // After data path
    unsigned int get_height_of_binary_tree  (BINARY_TREE * headPtr);
    int total_node_at_level                 (BINARY_TREE * headPtr, int level);

    void print_bottom_view_of_binary_tree      (BINARY_TREE * headPtr);
    void print_top_view_of_binary_tree         (BINARY_TREE * headPtr);
    void print_left_side_view_of_binary_tree   (BINARY_TREE * headPtr);
    void print_right_side_view_of_binary_tree  (BINARY_TREE * headPtr);

    void print_all_node_at_level_in_binary_tree (BINARY_TREE * headPtr, unsigned int level); // NOTE: Level Order Traversal will require
    int total_node_at_level_in_binaryl_tree     (BINARY_TREE * headPtr, unsigned int level); // NOTE: Level Order Traversal will require

    // https://www.sanfoundry.com/c-program-find-lowest-common-ancestor/
    int lowest_common_ancestor                  (BINARY_TREE * headPtr, unsigned int data1, unsigned int data2);

    https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/#:~:text=The%20left%20boundary%20is%20defined,left%20boundary%20or%20right%20boundary.
    void print_boundry_of_binary_tree           (BINARY_TREE * headPtr);

#endif // _BINARY_TREE_COMMON_H_
#ifndef _GENERAL_TREE_H_
#define _GENERAL_TREE_H_

    #define SUCCESS 1
    #define FAIL    0

    #define TRUE    1
    #define FALSE   0

    #define YES     1
    #define NO      0

    #define DESTRUCTOR_of_GENERAL_TREE(VAL) \
        (VAL)->degree = 0;                  \
        free((VAL)->childHeadPtr);          \
        (VAL)->childHeadPtr = NULL;         \
        free(VAL);                          \
        VAL = NULL;

    typedef unsigned char bool;

    typedef struct _general_tree_
    {
        unsigned int data;
        unsigned int degree;
        struct _general_tree_ ** childHeadPtr;

    }GENERAL_TREE;

    GENERAL_TREE * creat_general_tree (int data);

    bool is_general_tree_empty (GENERAL_TREE * rootPtr);
    unsigned int total_nodes_in_general_tree (GENERAL_TREE * rootPtr);
    
    bool insert_in_general_tree (GENERAL_TREE ** rootPtr, unsigned int data, unsigned int parentData);

    void print_general_tree_in_preorder (GENERAL_TREE * rootPtr);
    void print_general_tree_in_postorder (GENERAL_TREE * rootPtr);

    void delete_general_tree (GENERAL_TREE ** rootPtr);
    bool delete_node_from_general_tree (GENERAL_TREE ** rootPtr, int data);
    
    int get_root_node_data (GENERAL_TREE * rootPtr);
    int get_parent_of_data (GENERAL_TREE * rootPtr, int childData);
    void print_internal_node_of_general_tree (GENERAL_TREE * rootPtr);
    void print_leaf_node_of_general_tree (GENERAL_TREE * rootPtr);
    bool print_ancestor_of_general_tree (GENERAL_TREE * rootPtr, int data);
    bool print_descendant_of_general_tree (GENERAL_TREE * rootPtr, int data);

    unsigned int get_height_of_general_tree (GENERAL_TREE * rootPtr);

#endif

#define _GENERAL_TREE_H_

#ifndef _GENERAL_TREE_H_
#define _GENERAL_TREE_H_

    #define SUCCESS 1
    #define FAIL    0

    #define TRUE    1
    #define FALSE   0

    #define YES     1
    #define NO      0

    #define FREE_GENERAT_TREE_NODE(VAR) free(VAR);  \
                                        VAR = NULL; 

    typedef unsigned char bool;

    typedef struct _general_tree_
    {
        int data;
        int degree;
        struct _general_tree_ ** childNodePtr;

    }GENERAL_TREE;

    typedef enum _position_
    {
        POSITION_ROOT   = 0,
        POSITION_LEFT,
        POSITION_RIGHT,

    }E_POSITION;

    GENERAL_TREE * create_general_tree  (int data);

    bool is_general_tree_empty          (GENERAL_TREE * rootPtr);
    unsigned int size_of_general_tree   (GENERAL_TREE * rootPtr);

    bool insert_in_tree         (GENERAL_TREE ** rootPtr, int data, E_POSITION pos);
    bool is_data_present_in_tree (GENERAL_TREE * rootPtr, int data);

    void print_in_preorder  (GENERAL_TREE * rootPtr);
    void print_in_inorder   (GENERAL_TREE * rootPtr);
    void print_in_postorder (GENERAL_TREE * rootPtr);
    void print_in_list      (GENERAL_TREE * rootPtr);    // NOTE: Level Order Traversal will require

    bool delete_general_tree            (GENERAL_TREE ** rootPtr);
    bool delete_node_in_general_tree    (GENERAL_TREE ** rootPtr, int data);

    int get_root_node_data      (GENERAL_TREE * rootPtr);
    int get_siblings            (GENERAL_TREE * rootPtr, int data);
    bool is_sibling             (GENERAL_TREE * rootPtr, int data1, int data2);
    void print_internal_node    (GENERAL_TREE * rootPtr);
    int get_internet_node_count (GENERAL_TREE * rootPtr);
    void print_leaf_node        (GENERAL_TREE * rootPtr);   // Same --> void print_external_node    (GENERAL_TREE * rootPtr);
    int get_breadth             (GENERAL_TREE * rootPtr);   // The number of leaves
    bool print_ancestor         (GENERAL_TREE * rootPtr, int data);     // Root to data path
    void print_descendant       (GENERAL_TREE * rootPtr, int data);     // After data path
    unsigned int get_height     (GENERAL_TREE * rootPtr);
    int total_node_at_level     (GENERAL_TREE * rootPtr, int level);

    void print_bottom_view_of_general_tree      (GENERAL_TREE * rootPtr);
    void print_top_view_of_general_tree         (GENERAL_TREE * rootPtr);
    void print_left_side_view_of_general_tree   (GENERAL_TREE * rootPtr);
    void print_right_side_view_of_general_tree  (GENERAL_TREE * rootPtr);

    void print_all_node_at_level_in_general_tree (GENERAL_TREE * rootPtr, unsigned int level); // NOTE: Level Order Traversal will require
    int total_node_at_level_in_general_tree      (GENERAL_TREE * rootPtr, unsigned int level); // NOTE: Level Order Traversal will require

#endif // _GENERAL_TREE_H_

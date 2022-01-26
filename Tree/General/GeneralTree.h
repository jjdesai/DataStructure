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
        struct _general_tree_ * left;
        struct _general_tree_ * right;

    }GENERAL_TREE;

    typedef enum _position_
    {
        POSITION_ROOT   = 0,
        POSITION_LEFT,
        POSITION_RIGHT,

    }E_POSITION; 

    GENERAL_TREE * create_general_tree  (int data);

    bool is_general_tree_empty          (GENERAL_TREE * headPtr);
    unsigned int size_of_general_tree   (GENERAL_TREE * headPtr);

    bool insert_in_tree         (GENERAL_TREE ** headPtr, int data, E_POSITION pos);
    bool is_data_present_in_tree (GENERAL_TREE * headPtr, int data);

    void print_in_preorder  (GENERAL_TREE * headPtr);
    void print_in_inorder   (GENERAL_TREE * headPtr);
    void print_in_postorder (GENERAL_TREE * headPtr);
    void print_in_list      (GENERAL_TREE * headPtr);

    bool delete_general_tree            (GENERAL_TREE ** headPtr);
    bool delete_node_in_general_tree    (GENERAL_TREE ** headPtr, int data);

    int get_root_node           (GENERAL_TREE * headPtr);
    bool is_sibling             (GENERAL_TREE * headPtr, int data1, int data2);
    bool print_siblings         (GENERAL_TREE * headPtr, int data);
    void print_internal_node    (GENERAL_TREE * headPtr);
    int get_internet_node_count (GENERAL_TREE * headPtr);
    void print_leaf_node        (GENERAL_TREE * headPtr);   // Same --> void print_external_node    (GENERAL_TREE * headPtr);
    int get_breadth             (GENERAL_TREE * headPtr);   // The number of leaves
    bool print_ancestor         (GENERAL_TREE * headPtr, int data);
    bool print_escendants       (GENERAL_TREE * headPtr, int data);
    int get_depth               (GENERAL_TREE * headPtr);
    int get_height              (GENERAL_TREE * headPtr);
    int total_node_at_level     (GENERAL_TREE * headPtr, int level);

#endif // _GENERAL_TREE_H_

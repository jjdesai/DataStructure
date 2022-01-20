#ifndef _CIRCULAR_LINK_LIST_
#define _CIRCULAR_LINK_LIST_

    #define SUCCESS 1
    #define FAIL    0

    #define TRUE    1
    #define FALSE   0

    #define YES     1
    #define NO      0

    #define FREE_CIRCULAR_LINK_NODE(VAR)    free(VAR);  \
                                            VAR = NULL; 

    typedef unsigned char bool;

    typedef struct _circular_link_list_
    {
        int data;
        struct _circular_link_list_ * next;

    }CIRCULAR_LINK;

    CIRCULAR_LINK * creat_circular_node     (int data);
    bool is_circular_link_empty             (CIRCULAR_LINK * circularHeadPtr);
    unsigned int size_of_circular_link      (CIRCULAR_LINK * circularHeadPtr);

    bool add_circular_node_at_first     (CIRCULAR_LINK ** circularHeadPtr, int data);
    bool add_circular_node_at_end       (CIRCULAR_LINK ** circularHeadPtr, int data);
    bool add_circular_node_at_position  (CIRCULAR_LINK ** circularHeadPtr, int data, int position);
    bool add_circular_node_after        (CIRCULAR_LINK ** circularHeadPtr, int data, int afterData);

    bool delete_circular_link_list      (CIRCULAR_LINK ** circularHeadPtr);
    bool delete_circular_link_list_r    (CIRCULAR_LINK ** circularHeadPtr, CIRCULAR_LINK * rotationCircularNodePtr);

    bool delete_circular_node_from_beginning    (CIRCULAR_LINK ** circularHeadPtr);
    bool delete_circular_node_from_last         (CIRCULAR_LINK ** circularHeadPtr);
    bool delete_specific_circular_node          (CIRCULAR_LINK ** circularHeadPtr, int specificData);

    void print_circular_link_list       (CIRCULAR_LINK * circularHeadPtr);
    
#endif  // _CIRCULAR_LINK_LIST_

#ifndef _DOUBLE_LINK_LIST_
#define _DOUBLE_LINK_LIST_

    #define SUCCESS 1
    #define FAIL    0

    #define YES     1
    #define NO      0

    #define FREE_DOUBLE_LINK_NODE(VAR)  free(VAR);    \
                                        VAR = NULL;

    typedef unsigned char bool;

    typedef struct _double_link_list_
    {
        struct _double_link_list_ * prev;
        int data;
        struct _double_link_list_ * next;

    }DOUBLE_LINK;

    typedef enum _arrange_order_
    {
        ARRANGE_IN_ASCENDING    = 0,
        ARRANGE_IN_DESCENDING,  //1

    }ARRANGE_ORDER;

    bool add_double_link_at_last        (DOUBLE_LINK ** headPtr, int data);
    bool add_double_link_at_first       (DOUBLE_LINK ** headPtr, int data);
    bool add_double_link_at_pos         (DOUBLE_LINK ** headPtr, int data, unsigned int position);
    bool add_double_link_with_ascending (DOUBLE_LINK ** heardPtr, int data);
    
    void print_double_link_with_data    (DOUBLE_LINK * headPtr);
    void print_double_link_with_addr    (DOUBLE_LINK * headPtr);
    void print_double_link_list         (DOUBLE_LINK * headPtr);

    bool arrange_in_order               (ARRANGE_ORDER order, DOUBLE_LINK * headPtr);
    bool swap_with_data                 (DOUBLE_LINK * ptr1, DOUBLE_LINK * ptr2);
    
    bool delete_double_node             (DOUBLE_LINK ** headPtr, int data);
    bool delete_double_node_r           (DOUBLE_LINK ** headPtr, int data);     // _r Indicate recursion
    bool delete_double_link_list        (DOUBLE_LINK ** headPtr);
    bool delete_double_link_list_r      (DOUBLE_LINK ** headPtr);               // _r Indicate recursion

    bool reverse_double_link            (DOUBLE_LINK ** headPtr);
    DOUBLE_LINK * reverse_double_link_r (DOUBLE_LINK ** headPtr, DOUBLE_LINK * nodePtr); // _r Indicate recursion

    bool is_double_link_empty           (DOUBLE_LINK * headPtr);
    unsigned int size_of_double_link    (DOUBLE_LINK * headPtr);
    DOUBLE_LINK * add_two_double_link   (DOUBLE_LINK * headPtr1, DOUBLE_LINK * headPtr2); 

#endif  // _DOUBLE_LINK_LIST_

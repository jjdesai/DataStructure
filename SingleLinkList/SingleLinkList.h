
#ifndef _SINGLE_LINK_LIST_
#define _SINGLE_LINK_LIST_

    #define SUCCESS 1
    #define FAIL    0

    #define YES     1
    #define NO      0

    #define FREE_SINGLE_LINK_NODE(VAR)  free(VAR);    \
                                        VAR = NULL;

    typedef unsigned char bool;

    typedef struct _single_link_list_
    {
        int data;
        struct _single_link_list_ * next;

    }SINGLE_LINK;

    typedef enum _arrange_order_
    {
        ARRANGE_IN_ASCENDING    = 0,
        ARRANGE_IN_DESCENDING,  //1

    }ARRANGE_ORDER;

    bool add_single_link_at_last        (SINGLE_LINK ** headPtr, int data);
    bool add_single_link_at_first       (SINGLE_LINK ** headPtr, int data);
    bool add_single_link_at_pos         (SINGLE_LINK ** headPtr, int data, unsigned int position);
    bool add_single_link_with_ascending (SINGLE_LINK ** heardPtr, int data);
    
    void print_single_link_with_data    (SINGLE_LINK * headPtr);
    void print_single_link_with_addr    (SINGLE_LINK * headPtr);
    void print_single_link_list         (SINGLE_LINK * headPtr);

    bool arrange_in_order               (ARRANGE_ORDER order, SINGLE_LINK * headPtr);
    bool swap_with_data                 (SINGLE_LINK * ptr1, SINGLE_LINK * ptr2);
    
    bool delete_single_node             (SINGLE_LINK ** headPtr, int data);
    bool delete_single_node_r           (SINGLE_LINK ** headPtr, int data);     // _r Indicate recursion
    bool delete_single_link_list        (SINGLE_LINK ** headPtr);
    bool delete_single_link_list_r      (SINGLE_LINK ** headPtr);               // _r Indicate recursion

    bool reverse_single_link            (SINGLE_LINK ** headPtr);
    SINGLE_LINK * reverse_single_link_r (SINGLE_LINK ** headPtr, SINGLE_LINK * nodePtr); // _r Indicate recursion

    bool is_single_link_empty           (SINGLE_LINK * headPtr);
    unsigned int size_of_single_link    (SINGLE_LINK * headPtr);
    SINGLE_LINK * add_two_single_link   (SINGLE_LINK * headPtr1, SINGLE_LINK * headPtr2); 

#endif  // _SINGLE_LINK_LIST_

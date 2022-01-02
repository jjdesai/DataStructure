
#ifndef _SINGLE_LINK_LIST_
#define _SINGLE_LINK_LIST_

    #define SUCCESS 1
    #define FAIL    0

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

    SINGLE_LINK * create_new_node       (int data);

    bool add_single_link_at_last        (SINGLE_LINK ** headPtr, int data);
    bool add_single_link_at_first       (SINGLE_LINK ** headPtr, int data);
    bool add_single_link_at_pos         (SINGLE_LINK ** headPtr, int data);
    bool add_single_link_with_ascending (SINGLE_LINK ** heardPtr, int data);
    
    void print_single_link_with_data    (SINGLE_LINK * headPtr);
    void print_single_link_with_addr    (SINGLE_LINK * headPtr);
    void print_single_link_list         (SINGLE_LINK * headPtr);

    bool arrange_in_order           (ARRANGE_ORDER order, SINGLE_LINK ** headPtr);
    bool swap_with_data             (SINGLE_LINK * singlePtr1, SINGLE_LINK * singlePtr2);
    bool swap_with_address          (); // TODO: Argument will be decided once logic will decided 
    
    bool delete_single_node         (SINGLE_LINK ** headPtr, int data);
    bool delete_single_node_r       (SINGLE_LINK ** headPtr, int data);     // _r Indicate recursion
    bool delete_single_link_list    (SINGLE_LINK ** headPtr);
    bool delete_single_link_list_r  (SINGLE_LINK ** headPtr);               // _r Indicate recursion

#endif  // _SINGLE_LINK_LIST_

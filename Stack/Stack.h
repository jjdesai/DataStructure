
#ifndef _STACK_
#define _STACK_

    #define SUCCESS 1
    #define FAIL    0

    #define TRUE    1
    #define FALSE   0

    #define FREE_STACK(VAR) free(VAR);   \
                            VAR = NULL;

    typedef unsigned char bool;

    typedef struct _stack_
    {
        int data;
        struct  _stack_ * next;

    }STACK;

    STACK * create_new_stock (int data);
    
    bool is_stack_empty     (STACK * stackHeadPtr);
    unsigned int stack_size (STACK * stackHeadPtr);
    
    int top_from_stack      (STACK * stackHeadPtr);
    bool push_in_stack      (STACK ** stackHeadPtr, int data);
    bool pop_from_stack     (STACK ** stackHeadPtr, int * poppedDataPtr);
    
    bool swap_stack         (STACK ** stackHeadPtr1, STACK ** stackHeadPtr2);
    
    void print_stack        (STACK * stackHeadPtr);
    bool clear_stack        (STACK ** stackHeadPtr);
    bool clear_stack_r      (STACK ** stackHeadPtr);

#endif  // _STACK_
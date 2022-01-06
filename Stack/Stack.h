
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
    
    bool is_stack_empty     (STACK * headStackPtr);
    unsigned int stack_size (STACK * headStackPtr);
    
    int top_from_stack      (STACK * headStackPtr);
    bool push_in_stack      (STACK ** headStackPtr, int data);
    bool pop_from_stack     (STACK ** headStackPtr, int * poppedDataPtr);
    
    bool swap_stack         (STACK ** headStackPtr1, STACK ** headStackPtr2);
    
    void print_stack        (STACK * headStackPtr);

#endif  // _STACK_
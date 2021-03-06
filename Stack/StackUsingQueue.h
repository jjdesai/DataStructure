#ifndef _STACK_USING_QUEUE_
#define _STACK_USING_QUEUE_

    #define SUCCESS 1
    #define FAIL    0

    #define FREE_STACK(VAR) free(VAR);  \
                            VAR = NULL;

    #define YES 1
    #define NO  0

    typedef unsigned char bool;

    typedef struct  _stack_
    {
        int data;
        struct _stack_ * next;

    }STACK;

    STACK * create_stack    (int data);
    bool enqueue            (STACK ** stackHeadPtr, STACK * newStackPtr);
    STACK * dequeue         (STACK ** stackHeadPtr);
    bool push               (STACK ** stackHeadPtr, int data);
    int pop                 (STACK ** stackHeadPtr);
    void print_stack        (STACK * stackHeadPtr);
    bool clear_stack        (STACK ** stackHeadPtr);
    bool clear_stack_r      (STACK ** stackHeadPtr);

#endif // _STACK_USING_QUEUE_
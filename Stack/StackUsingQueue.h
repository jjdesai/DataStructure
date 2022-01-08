#ifndef _STACK_USING_QUEUE_
#define _STACK_USING_QUEUE_

    #define SUCCESS 1
    #define FAIL    0

    #define YES 1
    #define NO  0

    typedef unsigned char bool;

    typedef struct  _stack_
    {
        int data;
        struct _stack_ * next;

    }STACK;

    STACK * create_stack    (int data);
    bool EnQueue             (STACK ** headPtr, STACK * newStackPtr);
    STACK * DeQueue         (STACK ** headPtr);
    bool Push               (STACK ** headPtr, int data);
    int Pop                 (STACK ** headPtr);
    void PrintStack         (STACK * tmpPtr);

#endif // _STACK_USING_QUEUE_
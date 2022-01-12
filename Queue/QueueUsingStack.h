#ifndef QUEUE_USING_STACK
#define QUEUE_USING_STACK

    #define SUCCESS 1
    #define FAIL    0

    #define TRUE    1
    #define FALSE   0

    #define FREE_QUEUE(VAR) free(VAR);  \
                            VAR = NULL;

    typedef unsigned char bool;

    typedef struct _queue_
    {
        int data;
        struct  _queue_ * next;        

    }QUEUE;

    bool push       (QUEUE ** queueHeadPtr, QUEUE * newQueuePtr);
    QUEUE * pop     (QUEUE ** queueHeadPtr);
    bool enqueue    (QUEUE ** queueHeadPtr, int data);
    int dequeue     (QUEUE ** queueHeadPtr);
    
    void print_queue    (QUEUE * queueHeadPtr);
    bool clear_queue    (QUEUE ** queueHeadPtr);
    bool clear_queue_r  (QUEUE ** queueHeadPtr);

#endif // QUEUE_USING_STACK
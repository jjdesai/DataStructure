#ifndef _QUEUE_
#define _QUEUE_

    #define SUCCESS 1
    #define FAIL    0

    #define YES     1
    #define NO      0

    #define FREE_QUEUE(VAR)     free(VAR);  \
                                VAR = NULL;

    typedef unsigned char bool;

    typedef struct _queue_
    {
        int data;
        struct _queue_ * next;

    }QUEUE;

    QUEUE * create_new_queue    (int data);

    bool insert_in_queue        (QUEUE ** headQueuePtr, int data);      // EnQueue
    int remove_from_queue       (QUEUE ** headQueuePtr);                // DeQueue

    int access_front            (QUEUE * headQueuePtr);                 // Access front data
    int access_back             (QUEUE * headQueuePtr);                 // Access back data

    bool is_queue_empty         (QUEUE * headQueuePtr);                 // isEmpty
    unsigned int size_of_queue  (QUEUE * headQueuePtr);                 // size

    bool swap_queues            (QUEUE ** headQueuePtr1, QUEUE ** headQueuePtr2);
    void print_queue            (QUEUE * headQueuePtr);
    bool clear_queue            (QUEUE ** headQueuePtr);
    bool clear_queue_r          (QUEUE ** queueHeadPtr);
    
#endif  // _QUEUE_
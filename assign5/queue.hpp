#ifndef __QUEUE__
#define __QUEUE__

#include "node.hpp"

class Queue 
{
    Node *front, *rear, *temp;
    int len;
    public:
        Queue(void);
        void enqueue(char new_letter);
        bool dequeue();
        char get_front();
        char get_rear();
        bool is_empty();
        int list_count();
    
};
#endif

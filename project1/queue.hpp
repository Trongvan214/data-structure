#ifndef __QUEUE__
#define __QUEUE__

#include "node.hpp"

class Queue 
{
    Node *front, *rear, *temp;
    int t_wait_time, t_cust_serv, t_cust_throw, serv_time;
    int len;
    public:
        Queue(void);
        void enqueue(int arriv_time, int serv_time);
        bool dequeue();
        int get_front();
        int get_rear();
        bool is_empty();
        int list_count();
        void min_past();
        int r_wait_time();
        int r_cust_serv();
        int r_cust_throw();
};
#endif

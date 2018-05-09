#ifndef __CASHIER__
#define __CASHIER__

#include "queue.hpp" 

class Cashier 
{
    Queue line;
    //total time people in this cashier waited
    int t_wait_time
    //a for available, i for inactive
    char status;
    //depends on customers serv_time
    int t_serv_remain;
    //total customer rejected
    int t_cust_throw;
    public: 
        Cashier(void);
        void serv_cust(int serv);
        void add_to_line(int serv);
        bool is_available();
        int return_t_wait_time();
        int return_t_cust_throw();
        int return_t_cust_serv();
        int waiting_customer();
        
        
};


#endif

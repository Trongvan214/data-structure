#ifndef __SIMULATION__
#define __SIMULATION__

#include "cashier.hpp"

class Simulation
{
    // ranges in values from 0 to 570
	int time_count;
    // number of customers serviced so far
	int t_serviced;
    // of all customers in the queues
	long t_wait_time;	
    // count of customers turned away
	int t_turned_away;
    Cashier one,two,three;
    public: 
        Simulation(void);
        bool is_cust_here(int arriv_time);
        void take_data(int num,int arr_time,int serv_time);
        int avg_wait()
        int turned_away();
        int total_cust_serv();
        bool is_over();
};

#endif 

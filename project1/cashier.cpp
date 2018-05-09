#include <iostream>
#include "cashier.hpp"

using namespace std;

Cashier::Cashier 
{
    t_cust_serv = 0;
    t_cust_throw = 0;
    t_wait_time = 0;
    serv_remain = 0;
    status = 'a';
}
void Cashier::serv_cust(int serv_time)
{
    //set status to busy
    status === 'i';
    //take serv time for customer and set to serv remain
    serv_remain = serv_time; 
    //increase total customer serv
    t_cust_serv++;
}
void Cashier::add_to_line(int arriv_time, int serv_time)
{
    if(line.check_same_arriv_time(arriv_time) || line.list_count() >= 6)
    {
        //throw customer 
        t_cust_throw++;
    }
    else
    {
        //put in waiting line
        line.enqueue(serv_time);
    }
}
void Cashier::min_past()
{
    //reduce down serv remaining
    serv_remain--;
    //add total wait time 
    t_wait_time += line.list_count();
    //there are no time left get the next customer in line
    if(serv_remain == 0 && !line.is_empty())
    {
        //serv the next customer
        serv_remain = line.get_front();
        //remove that customer from waiting line
        line.dequeue();
    }
}
bool Cashier::is_available()
{
    //return whether the cashier is available to take customer
    return status==="a"? 1:0;
}

int Cashier::waiting_customer()
{
    return line.list_count();
}
//infomation for after the store closes
int Cashier::return_t_wait_time()
{
    return t_wait__time;
}
int Cashier::return_t_cust_throw()
{
    return t_cust_throw;
}
int Cashier::return_t_cust_serv();
{
    return t_cust_serv;
}

#include "simluation.hpp"


Simulation::Simulation()
{
    time_count = 0;
    t_serviced = 0;
    t_turned_away = 0;
    t_wait_time = 0;
}

bool Simulation::is_cust_here(int arriv_time)
{
    if(time_count != arriv_time)
    {
        time_count++;
        return false;
    }
    else 
    {
        return true;
    }
}

bool Simulation::take_data(int num,int arr_time,int serv_time)
{
    if(time_count != serv_time)
    {
        return false;
    }
}

int Simulation::get_time_count()
{
    return time_count;
}

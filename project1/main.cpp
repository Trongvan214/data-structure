//Author: Trong Van
//Student ID: x454v285
//Project 1
/*------------------Start program----------------------
 * 
 *      take the first customer from data .txt
 *      while working hours is not over
 *          if not 30 min before closing 
 *              if data arriv == working hour
 *                  sort customer to the shortest line
 *                  take the next data
 *          else
 *              throw customer
 *       
 *      finish working hours 
 *          put all the data in results.txt
 **/

#include <iostream>
#include <fstream>
#include <iomanip>

#include "queue.hpp"

using namespace std;

int main()
{
    //the cashiers
    Queue cash1,cash2,cash3;
    //point to the short len queue
    int t_cust, 
        cust_num, 
        arriv_time, 
        serv_time , 
        t_cust_serv = 0,
        t_cust_throw = 0,
        t_wait_time = 0,
        working_time = 0;
    //the len count of the cashiers
    int len1, len2, len3;
    int prev_arriv;
    ifstream read("customers.txt");
    read >> t_cust; 
    read>>cust_num>>arriv_time>>serv_time;
    while(working_time!=600)
    { 
        if(working_time == arriv_time)
        {
            //throw customer
            if(working_time >= 570)
            {
                t_cust_throw++;
            } 
            prev_arriv = arriv_time;
            len1=cash1.list_count();
            len2=cash2.list_count();
            len3=cash3.list_count();
            if(len1<=len2&&len1<=len3)
            {
                cash1.enqueue(arriv_time,serv_time);
            }
            else if(len2<len1&&len2<=len3)
            {
                cash2.enqueue(arriv_time,serv_time);
            }
            else if(len3<len1&&len3<len2)
            {
                cash3.enqueue(arriv_time,serv_time);
            }
            //read the next line check see if it's the end
            if(read>>cust_num>>arriv_time>>serv_time)
            {
                //if not check next arri to prev_arriv
                while(arriv_time == prev_arriv)
                {
                    //if next line is the end jump out loop
                    if(!(read>>cust_num>>arriv_time>>serv_time))
                    {
                        arriv_time = -9999;
                    }
                    t_cust_throw++;
                }
            }
        }
        //this function does all calculation to take next customer
        cash1.min_past();
        cash2.min_past();
        cash3.min_past();
        working_time++;
    }
    read.close();
    //total up all 3 cashier total throw
    t_cust_throw+=cash1.r_cust_throw()
                +cash2.r_cust_throw()
                +cash3.r_cust_throw();
    t_cust_serv=cash1.r_cust_serv()+cash2.r_cust_serv()+cash3.r_cust_serv();
    t_wait_time=cash1.r_wait_time()+cash2.r_wait_time()+cash3.r_wait_time();
    float avg_wait = 0;
    if(t_wait_time != 0)
    {
        avg_wait = (float)t_wait_time/t_cust_serv;
    }
    //write to file 
    ofstream write("results.txt");
    write << setprecision(2) << fixed;
    write << "Total number of customers serviced: " << t_cust_serv << endl;
    write << "Total number of customers turned away: " << t_cust_throw << endl;
    write << "Average wait time: " <<  avg_wait << endl; 
    write << "Total wait time: " << t_wait_time << endl;
    write.close();

    cout << setprecision(2) << fixed;
    cout << "cash1 serv " << cash1.r_cust_serv() << endl;
    cout << "cash1 wait " << cash1.r_wait_time() << endl;
    cout << "cash1 throw " << cash1.r_cust_throw() << endl;
    cout << "cash2 serv " << cash2.r_cust_serv() << endl;
    cout << "cash2 wait " << cash2.r_wait_time() << endl;
    cout << "cash2 throw " << cash2.r_cust_throw() << endl;
    cout << "cash3 serv " << cash3.r_cust_serv() << endl;
    cout << "cash3 wait " << cash3.r_wait_time() << endl;
    cout << "cash3 throw " << cash3.r_cust_throw() << endl;
    cout << "average wait time " << avg_wait << endl;
    cout << "total cust serv " << t_cust_serv << endl;
    cout << "total cust throw " << t_cust_throw << endl;
    cout << "total wait time " << t_wait_time << endl;
}






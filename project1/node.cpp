#include <iostream>
#include "node.hpp"

using namespace std;

Node::Node(void)
{
    //default case
    cust_serv_time = 0;
    cust_arriv_time = 0;
    next = NULL;
}
Node::Node(int arriv_time,int serv_time)
{
    //set customer data
    cust_serv_time = serv_time;
    cust_arriv_time = arriv_time;
    next = NULL;
}
void Node::change_pointer(Node* next_ptr)
{
    //change pointer
    next = next_ptr;
}

Node* Node::return_next()
{
    //return this ptr link
    return next;
}
void Node::process_data()
{
    //print out the letter
    cout << "Customer serve time " << cust_serv_time << endl;
    cout << "Customer arrive time " << cust_arriv_time << endl;
    
}
int Node::return_arriv_time()
{
    return cust_arriv_time;
}
int Node::return_serv_time()
{
    return cust_serv_time;
}

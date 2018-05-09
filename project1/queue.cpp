/*          Queue Pseudo code

Class Queue
	Data:	
		front – Pointer to Node that will hold the front pointer of the queue
		rear – pointer to Node that will hold the rear pointer of the queue
		Len -	number of Nodes in the linked list

Default constructor
	Queue – will be called when queue is created
		
	front = NULL
	rear = NULL
	len = 0

Member function
	enqueue (data)

	input: data to be inserted into queue (stored in Node)
	output: None
	returns: Nothing

	ptr = allocate a new Node (Put data in node)
	if front == NULL
		front = rear = ptr
	else
		rear link = ptr
		rear = ptr
	len = len + 1

Member function
	dequeue

	input:   None
	output: None
	returns: True if deleted, false if not in list

	if front != NULL
		temp = front link
		free front
		front = temp
		if last item is deleted from list (if front == NULL)
			rear = NULL
		len = len - 1
		return True
	else
		return False

Member function
	Queue rear
	input: None
	output: None
	returns: data from rear of queue  or 0 if queue empty

	if rear != NULL
		return rear data
	else
		return 0

Member function
	Queue front
	input: None
	output: None
	returns: data from front of queue  or 0 if queue empty

	if front != NULL
		return front data
	else
		return 0


Member function
	is_empty
	
	input: None
	output: None
    return:	True if empty, false if not

	if len = 0		or if front == NULL
		return True
	else	
		return False

Member function 
	list_count

	input: None
	output: None
    Return:	number of items in list

	return list len

Member function
*    min_past
*    input: none
*    output: none
*    return none
*    functionality: calculate the wait time
* 
Member function
*   r_cust_serv 
*   functionality: return the t_cust_serv
Member function 
*   r_cust_throw
*   functionality: return the t_cust_throw in class
Member function
*   r_wait_time 
*   fucntionality: return the t_wait_time in class


Create queue – make an instance of class queue
Enqueue – call class enqueue function
Dequeue – call class dequeue function
Queue front – call class queue front function
Queue rear – call class queue rear function
Is empty – call class is empty function
Number of nodes – call list count function
*/
#include <iostream>
#include "queue.hpp"

using namespace std;

Queue::Queue()
{
    //default case everything to 0 and NULL
    front = rear = temp = NULL;
    t_wait_time = t_cust_serv = t_cust_throw = serv_time = len = 0;
}
//put in a new node
void Queue::enqueue(int g_arriv_time,int g_serv_time)
{
    if(len == 6)
    {
        //add 1 to throw customers
        t_cust_throw++;
    }
    else 
    {
        if(len == 0)
        {
            serv_time = g_serv_time;
        }
        Node* ptr = new Node(g_arriv_time,g_serv_time);
        if(front == NULL || rear == NULL)
        {
            front = rear = ptr;
        }
        else
        {
            rear->change_pointer(ptr);
            rear = ptr;
        }
        len++;
    }
}
//take a node at the front 
bool Queue::dequeue()
{
    if(front != NULL)
    {
        temp = front->return_next();
        delete front;
        front = temp;
        if(front == NULL)
        {
            rear = NULL;
        }
        len--;
        return true;
    }
    return false;
}

//return the front node
int Queue::get_front()
{
    if(front != NULL)
    {
        return front->return_serv_time();
    }
    else
    {
        return 0;
    }
}
//return the rear node
int Queue::get_rear()
{
    if(rear != NULL)
    {
        return rear->return_serv_time();
    }
    else
    {
        return 0;
    }
}
//return true/false whether the queue is empty
bool Queue::is_empty()
{
    if(len == 0 || front == NULL || rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//return how many node is in the queue
int Queue::list_count()
{
    return len;
}
//function that calculate wait time
void Queue::min_past()
{
    //reduce serving time 
    serv_time--; 

    //available 
    if(serv_time == 0 && len > 0)
    {
        dequeue();
        t_cust_serv++;
        if(len > 0)
        {
            serv_time = get_front();
        }
    }
    if(len > 0)
    {
        t_wait_time+=len-1;
    }
}
//return total wait time 
int Queue::r_wait_time()
{
    return t_wait_time;
}
//return total customer serves
int Queue::r_cust_serv()
{
    return t_cust_serv;
}
//return total customer throw
int Queue::r_cust_throw()
{
    return t_cust_throw;
}















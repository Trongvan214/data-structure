/*              Node Pseudo code

Class node
	Data:	
    *   key - the given value at that node
		left – the pointer that point to the left node
        right - the pointer that point to the right node

Default constructor
	Node – will be called when queue is created
		
	set all data in the class to NULL or 0;

Default constructor 
*   Node(int given_key) 
*   
*   past in the key value into the node
* 
Member function
	change_left (data)

	input: the location of the next left ptr
	output: None
	returns: Nothing
    * 
    * 
Member function
	change_right (data)

	input: the location of the next left ptr
	output: None
	returns: Nothing

Member function
	return_left

	input:   None
	output: None
	returns: return the value of the left ptr (address)
    * 
    * 
Member function
	return_right

	input:   None
	output: None
	returns: return the value of the right ptr (address)

Member function
	return_key

	input: None
	output: None
	returns: the key 

Member function
	compare_key
    * 
	input: given_key
	output: None
	returns: true/false whether the given key = the key in class

Memeber function 
	process_data
    * 
	input: None
	output: the value of the key
	returns: nothing

*/
#include <iostream>
#include "node.hpp"

using namespace std;

//default constructor
Node::Node(void)
{
    //default case
    item.key = 0;
    item.s = '\0';
    left = NULL;
    right = NULL;
}
//constructor with pass in key
Node::Node(data given_item)
{
    item = given_item;
    left = NULL;
    right = NULL;
}
//change the left pointer to the given ptr
void Node::change_left_ptr(Node* next_ptr)
{
    left = next_ptr;
}
//change the right pointer to the given ptr
void Node::change_right_ptr(Node* next_ptr)
{
    right = next_ptr;
}
//return the left ptr
Node* Node::return_left()
{
    return left;
}
//return the right ptr
Node* Node::return_right()
{
    return right;
}
//return the item
data Node::return_item()
{
    return item;
}
int Node::return_key()
{
    return item.key;
}
//compare the given key value with the key
bool Node::compare_item(data given_item)
{
    if(item.key == given_item.key && item.s == given_item.s)
    {
        return true;
    }
    return false;
}
//cout the key value
void Node::process_data()
{
    cout << "The item value is " << item.key << "\t";
    cout << item.s << endl;
}


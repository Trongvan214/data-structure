/*              Stack Pseudo code
Class Stack
	Data:	
		top – Pointer to Node that will hold the top pointer of the stack
		Len -	number of Nodes in the linked list

Default constructor
	Stack – will be called when stack is created
		
	top = NULL
	len = 0

Member function
	push (data)

	input: data to be inserted into stack (stored in Node)
	output: None
	returns: Nothing

	ptr = allocate a new Node (Put data in node)
	ptr link = top
	top = ptr
	len = len + 1

Member function
	pop

	input:   None
	output: None
	returns: nothing

	if top != NULL
		temp = top link
		free top
		top = temp
		len = len - 1
		return True
	else
		return False

Member function
	Stack top
	input: None
	output: data from top of stack or 0 if stack empty
	returns: data from top of stack or 0 if stack empty

	if top != NULL
		return top data
	else
		return 0

Member function
	is_empty
	
	input: None
	output/return:	True if empty, false if not

	if len = 0		or if top == NULL
		return True
	else	
		return False

Member function 
	list_count

	input: None
	output/Return:	number of items in list

	return list len


Create stack – make an instance of class stack
Pop – call class pop function
Push – call class push function
Stack_top – call class stack_top function
Is empty – call class is empty function
Number of nodes – call list count function
*/
#include "stack.hpp"

#include <iostream>

using namespace std;

Stack::Stack()
{
    top = temp = NULL;
    len = 0;
}

void Stack::push(char new_char)
{
    Node* ptr = new Node(new_char);
    ptr->change_pointer(top);
    top = ptr;
    len++;    
}

bool Stack::pop()
{
    if(top != NULL)
    {
        temp = top->return_next();
        delete top;
        top = temp;
        len--;
        return true;
    }
    else 
    {
        return false;
    }
    
}

char Stack::stack_top()
{
    if(top != NULL)
    {
        return top->return_letter();
    }
    return 0;
}

bool Stack::is_empty()
{
    if(len == 0 || top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Stack::list_count()
{
    return len;
}


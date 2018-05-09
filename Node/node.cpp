#include <iostream>
#include "node.hpp"

using namespace std;

Node::Node(void)
{
    //default case
    letter = {0};
    next = NULL;
}
Node::Node(char letter)
{
    //set the letter
    letter = letter;
    next = NULL;
}
void Node::change_pointer(Node* next_ptr)
{
    //change pointer
    next = next_ptr;
}

Node* Node::return_next()
{
    //return the pointer
    return next;
}

char Node::return_char()
{
    return letter;
}

bool Node::compare_letter(char given_letter)
{
   //compare the given letter to the one in class
   return letter == given_letter;
}

void Node::process_data()
{
    //print out the letter
    cout << "Letter: " << letter << endl;
}

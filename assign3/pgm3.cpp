//Author: Trong Van
//Student ID: x454v285
//Programming Number: 3

/*Description: define a preparatory class that you will be using for linked 
 *list.  
 * 
 * Constructor name: Node               =>
 * Parameters: none (void)
 * Functionality: set your favorite book and set node pointer for null
 * 
 * Constructor name: Node               =>
 * Parameters: 
 *           1st: book title
 *           2nd: author
 *           3rd: date read
 * Functionality: take in the information for the book and set it
 * 
 * Function Name: change_pointer        =>
 * Parameters: 
 *           1st: new node to point to 
 * Functionality: set the current pointer to point to the one given
 * 
 * Function Name: return_pointer        =>
 * Parameters: none
 * Functionality: return the current pointer
 * 
 * Function Name: return_structure      =>
 * Parameters: none
 * Functionality: return the stucture
 * 
 * Function Name: compare_date          =>
 * Parameters: 
 *           1st: give a title to compare
 * Functionality: compare the given book to the one in the class
 * 
 * Function Name: process_data          =>
 * Parameters: none
 * Functionality: print the date of the book
 * 
 * ------------------Program start ------------
 *          create head node
 *          create 5 nodes 
 *          point head to first node and the rest..
 * 
 */
 
#include <iostream>
#include <string>
#include "Node.hpp"

using namespace std;

int main() 
{
    Node *head,
         *ptr1 = new Node("Pride and Prejudice","Jane Austen","11/11/2015"),
         *ptr2 = new Node("The Da Vinci Code ","Dan Brown","05/19/2006"),
         *ptr3 = new Node("To Kill a Mockingbird","Harper Lee","07/11/1960"),
         *ptr4 = new Node("The Catcher in the Rye","J.D.Salinger","07/16/1951"),
         *ptr5 = new Node("The Great Gatsby","F. Scott Fitzgerald","05/012013");
         
    head = ptr1;
    ptr1->change_pointer(ptr2);
    ptr2->change_pointer(ptr3);
    ptr3->change_pointer(ptr4);
    ptr4->change_pointer(ptr5);
    
    while(head != NULL)
    {
        head->process_date();
        head = head->return_pointer();
    }
}

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
 * Function Name: compare_data          =>
 * Parameters: 
 *           1st: give a title to compare
 * Functionality: compare the given book title to the one in the class
 * 
 * Function Name: process_data          =>
 * Parameters: none
 * Functionality: print the date of the book
 * 
 * ------------------Program start ------------
 *          create head node
 *          create 5 nodes 
 *          point head to first node and the rest..
 *          test all functions
 * 
 */
 
#include <iostream>
#include <string>
#include "node.hpp"

using namespace std;

int main() 
{
    //declaring the head pointer
    Node *head,
        //declaring the nodes 
         *ptr1 = new Node("Pride and Prejudice","Jane Austen","11/11/2015"),
         *ptr2 = new Node("The Da Vinci Code","Dan Brown","05/19/2006"),
         *ptr3 = new Node("To Kill a Mockingbird","Harper Lee","07/11/1960"),
         *ptr4 = new Node("The Catcher in the Rye","J.D.Salinger","07/16/1951"),
         *ptr5 = new Node("The Great Gatsby","F. Scott Fitzgerald","05/012013"),
         *ptr6 = new Node();
    
    //make the head point the first node
    head = ptr1;
    //than the next node to the next for the rest
    ptr1->change_pointer(ptr2);
    ptr2->change_pointer(ptr3);
    ptr3->change_pointer(ptr4);
    ptr4->change_pointer(ptr5);
    ptr5->change_pointer(ptr6);
    
    //testing the compare_data
    //all test should be true mean it's = 
    ptr1->compare_data("Pride and Prejudice")==0?cout<<"T\n":cout<<"F\n";
    ptr2->compare_data("The Da Vinci Code")==0?cout<<"T\n":cout<<"F\n";
    ptr3->compare_data("To Kill a Mockingbird")==0?cout<<"T\n":cout<<"F\n";
    ptr4->compare_data("The Catcher in the Rye")==0?cout<<"T\n":cout<<"F\n";
    ptr5->compare_data("The Great Gatsby")==0?cout<<"T\n":cout<<"F\n";
    ptr6->compare_data("Welcome to the dead house")==0?cout<<"T\n":cout<<"F\n\n";
    
    //loop through until the last node
    while(head != NULL)
    {
        //print out the return structure way to get the data
        cout << "return_structure way: " << endl;
        cout << head->return_structure().title << "\t";
        cout << head->return_structure().author << "\t";
        cout << head->return_structure().date << endl;
        //print out the data using process way
        head->process_date();
        //print out where the node point to
        cout << "Node point to " << head->return_pointer() << "\n\n";
        //set head to node where it's point to
        head = head->return_pointer();
        
    }
    return 0;
}

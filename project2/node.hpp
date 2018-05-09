/* Name: 	Trong Van
*  ID: 	 	X454V285
* 
* Name: 	Mohammad Alhaj
* ID: 	 	K362J964
* Project: #2
* 
* Psuedocode:
* 
* Class Name: Node
* 
* 
* Data:       data: item - holds the data about an item
*             Node pointer: left  - points to left node
* 			  				right - points to right node
* 
* Mutator Functions:
* 
*             Set left pointer - changes the pointer value.  
*             	Input Parms: Node pointer: temporary pointer
*             	Output Parms: None
* 
* 			  Set left pointer - changes the pointer value.  
*             	Input Parms: Node pointer: temporary pointer
*             	Output Parms: None
*                
* Accessor Functions:
* 
*             Return left pointer - returns pointer value  
* 
* 			  Return right pointer - returns pointer value
* 
*             Return item - returns data from the structure 
* 		
* 			  Return key - returns the key of an item
*                
* Functions:
*             Node - sets variables to default values
* 
* 			  Node - sets data variables  
*             	Input Parms: given key
*             	Output Parms: None
* 
* 			  Compare item - compares item data
*             	Input Parms: given key
*             	Output Parms: true/false
* 
*   		  Process data - prints item value 
* 
*/

#ifndef __NODE__
#define __NODE__

#include <iostream>
#include "data.hpp"
using namespace std;  

//creates a node class
class Node 
{
    data item;
    Node* left;
    Node* right;  
public: 
    Node(void);
    Node(data given_key);
    void change_left_ptr(Node *next_ptr);
    void change_right_ptr(Node *next_ptr);
    Node* return_left();
    Node* return_right();
    data return_item();
    int return_key();
    bool compare_item(data given_key);
    void process_data();
        
};
#endif

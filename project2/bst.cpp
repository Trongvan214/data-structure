/*              Binary Search Tree Pseudo Code
 * Constructor function: BTS
 * input: none
 * output: none
 * return: none
 * functionality: set root to null
 * 
 * function name: create_leaf 
 * input: key
 * output: none
 * return: none
 * functionality: create a leaf with the key = given key
 * 
 * function name: add_leaf_priv
 * input: key, ptr
 * output: none
 * return none
 * functionlity: create a leaf and attach it in the right place
 * 
 * function name: add_leaf
 * input: key
 * output: none
 * return: none
 * functionlity: call add_leaf_priv and pass in root and key to priv add_leaf
 * 
 * function name: print_in_order_priv
 * input: ptr
 * output: the data in order from least to greatest
 * return: none
 * functionlity: traverse (in order) and cout all the values
 * 
 * function name: print_in_order
 * input: none;
 * output: none
 * return: none
 * functionlity: a public function to call and this call priv function with 
 * root pass in (so people don't have access to root*/

#include <iostream>
#include "bst.hpp" 

using namespace std;

//default constructor 
BST::BST() 
{
    count = 0;
    root = NULL;
}
//automatic add all nodes
BST::BST(data list[], int given_size) 
{
    count = 0;
    root = NULL;
    for(int i=0;i<given_size;i++)
    {
        add_leaf(list[i]);
    }
}
//create leaf help prevent new dynamic menory everytime in recursive function
Node* BST::create_leaf(data item)
{
    return new Node(item);
}
//public add leaf so they can't get access to root 
void BST::add_leaf(data item)
{
    add_leaf_priv(item,root);
}
//take a given key and add it to the tree
void BST::add_leaf_priv(data item, Node* ptr)
{
    //if no node in the tree case
    if(root == NULL)
    {
        //count operation
        count+=1;
        
        root = create_leaf(item);
    }
    //if key is less than ptr
    else if(item.key < ptr->return_key())
    {
        //if more left node
        if(ptr->return_left() != NULL)
        {
            //go to left node
            add_leaf_priv(item, ptr->return_left());
        }
        //if no more left node
        else 
        {
            //count operation
            count+=1;
            
            ptr->change_left_ptr(create_leaf(item));
        }
    }
    //if key is greater than ptr
    else if(item.key > ptr->return_key())
    {
        //if more right node
        if(ptr->return_right() != NULL)
        {
            //go to the right node
            add_leaf_priv(item, ptr->return_right());
        }
        //if no right node
        else 
        {
            //count operation
            count+=1;
            
            ptr->change_right_ptr(create_leaf(item));
        }
    }
    //else mean node in tree already
}
//call the print in order priv and past in root as ptr
void BST::print_in_order(ostream& stream)
{
    print_in_order_priv(root,stream);
}
//function that print the tree in order from left to right
void BST::print_in_order_priv(Node* ptr, ostream& stream)
{
    if(root != NULL)
    {
        if(ptr->return_left() != NULL)
        {
            print_in_order_priv(ptr->return_left(),stream);
        }
        stream << ptr->return_key() << " " << ptr->return_item().s << endl;
        if(ptr->return_right() != NULL)
        {
            print_in_order_priv(ptr->return_right(),stream);
        }
    }
    else 
    {
        cout << "The tree is empty" << endl;
    }
}
 int BST::return_count()
 {
     return count;
 }


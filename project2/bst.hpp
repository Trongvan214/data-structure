#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

#include <fstream>

#include "node.hpp"
#include "data.hpp"

using namespace std;

class BST {
    //variables
    int count;
    Node* root;
    //private memeber functions
    Node* create_leaf(data item);
    void add_leaf_priv(data item, Node* ptr);
    void print_in_order_priv(Node* ptr, ostream& stream);
    //public member functions
    public:
        BST();
        BST(data[], int given_size);
        void add_leaf(data item);
        void print_in_order(ostream& stream);
        int return_count();
        
};
#endif

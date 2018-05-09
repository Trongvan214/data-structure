#ifndef __STACK__
#define __STACK__

#include "node.hpp"

class Stack 
{
    Node *top, *temp;
    int len;
    public: 
        Stack();
        void push(char each_char);
        bool pop();
        char stack_top();
        bool is_empty();
        int list_count();
};
#endif

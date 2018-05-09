#ifndef node_hpp
#define node_hpp

using namespace std;

class Node 
{
    char letter;
    Node* next;
    public: 
        Node(void);
        Node(char new_letter);
        void change_pointer(Node *next_ptr);
        Node* return_next();
        char return_letter();
        bool compare_letter(char given_letter);
        void process_data(); 
        
};
#endif

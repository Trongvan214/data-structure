//Author: Trong Van
//Student ID: x454v285
//Programming Number: 5

/*Description:  program that checks to see if a string is a palindrome*/

#include <iostream>
#include <cstring>

#include "stack.hpp"
#include "queue.hpp"

//function prototypes
void put_in(Queue* q, Stack* s, char* c, int len);
void compare_stack_and_queue(Stack s, Queue q);
void pali_check(char* input, int len);

using namespace std;

int main()
{
    //test case 1
    char test1[100] = "race car";
    cout << "The phrase “race car” ";
    pali_check(test1, strlen(test1));
    
    //test case 2
    char test2[100] = "man made";
    cout << "The phrase “man made” "; 
    pali_check(test2, strlen(test2));
    
    //user input 
    char user_input[100];
    cout << "Please enter a phase: ";
    cin.getline(user_input, 100);
    int len = strlen(user_input);
    //print the user input word 
    cout << "The phase (";
    for(int i = 0;i < len; i++)
    {
        cout << user_input[i];
    }
    cout << ") ";
    pali_check(user_input, len);
    return 0;
}
 
//check to see if the given word is a pali or not
void pali_check(char* input, int len)
{
    Stack s;
    Queue q;
    put_in(&q, &s, input, len);
    compare_stack_and_queue(s, q);
}

//put the word into a queue and stack
void put_in(Queue* q, Stack* s, char* c, int len)
{
    for(int i = 0; i < len; i++)
    {
        //format out punct. and space
        if(!(c[i] == ' '    || c[i] == ','    || c[i] == ']'
        || c[i] == '['   || c[i] == '.'    || c[i] == '\''
        || c[i] == '!'    || c[i] == '?'    || c[i] == ':'
        || c[i] == ';'    || c[i] == '-'    || c[i] == '_'
        || c[i] == '('    || c[i] == ')'    || c[i] == '\"'))
        {
            //put in the lower case of the char
            s->push(tolower(c[i]));
            q->enqueue(tolower(c[i]));
        }
    }
}

//compare the queue and stack
void compare_stack_and_queue(Stack s, Queue q) 
{
    bool is_equal = true;
    while(s.list_count() != 0 && is_equal)
    { 
        //make compare the in lower case
        if(s.stack_top() == q.get_front())
        { 
            s.pop();
            q.dequeue(); 
        }
        else 
        {
            is_equal = false;
        }
         
    }
    if(s.list_count() == 0)
    { 
        cout << "is a palindrome" << endl;
    }
    else 
    {
        cout << "is not a palindrome" << endl;
    }
}


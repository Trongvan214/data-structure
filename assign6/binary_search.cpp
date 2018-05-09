/*              Binary Search Pseudo Code
 * Constructor function: Binary_search
 * input: none
 * output: none
 * return: none
 * functionality: make the array and set the value
 * 
 * function name: Search 
 * input: target value to search
 * output: where the value given is at or not found
 * return: none
 * functionality: binary search the given value and print where its located*/

#include <iostream>
#include "binary_search.hpp" 

using namespace std;

//default constructor build the array
Binary_search::Binary_search() 
{
    //generated the array that is 5 at the begining and +5 ...
    for(int i = 0;i < 1000;i++)
    {
        data[i] = (i+1)*5;
    }
}
//function that does binary search on the given value
void Binary_search::search(int target)
{
    int begin = 0, end = 999, mid;
    cout << "Searching for " << target << endl;
    while(begin<=end)
    {
        cout << "\tChecking indexes " << begin << " : " << end << endl;
        mid = (begin+end)/2;
        if(target > data[mid])
        {
            //look at higher value 
            begin = mid + 1;
        }
        else if(target < data[mid])
        {
            //look at lower value
            end = mid - 1;
        }
        else 
        {
            begin = end + 1;
        }
    }
    if(target != data[mid])
    {
        cout << "\n\tValue is not found (-1)" << endl;
    }
    else 
    {
        cout << "\n\tFound at index " << mid << endl;
    }
}

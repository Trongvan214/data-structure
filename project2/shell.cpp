#include <iostream>

#include "shell.hpp"

using namespace std;

//function to sort arr using shellSort 
Shell::Shell(data list[], int given_size)
{
    item = list;
    size = given_size;
    count = 0;
    sort(item,size);
}
void Shell::sort(data list[], int size)
{
    // Start with a big gap, then reduce the gap
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            //increase operation
            count+=1;
            
            int temp = list[i].key;
            int j = i;            
            while(j >= gap && list[j - gap].key > temp)
            {
                list[j].key = list[j - gap].key;
                j-=gap;
            }
            // put temp (the original a[i]) in its correct location
            list[j].key = temp;
        }
    }
}

//print the list out 
void Shell::print(ostream& stream)
{
    for(int i=0;i<size;i++)
    {
        stream << item[i].key << " " << item[i].s << endl;
    }
    cout << endl;
}

//return the count 
int Shell::return_count()
{
    return count;
}


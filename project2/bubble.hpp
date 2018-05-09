#ifndef __BUBBLE__ 
#define __BUBBLE__

#include <fstream>
#include "data.hpp"
class Bubble 
{
    //count the number of operation
    int count, size;
    data* item;
    void sort(data list[], int size);
    public: 
        Bubble(data list[], int given_size);
        int return_count();
        void print(ostream& stream);
};
#endif

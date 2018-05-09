#ifndef __SHELL__
#define __SHELL__

#include <fstream>
#include "data.hpp"

class Shell 
{
    //count the number of operation
    int count, size;
    data* item;
    void sort(data list[], int size);
    public: 
        Shell(data list[], int given_size);
        int return_count();
        void print(ostream& stream);
};
#endif

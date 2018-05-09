#ifndef __QUICK__
#define __QUICK__

#include <fstream>
#include "data.hpp"
class Quick
{
    //count the number of operation
    int count, size;
    data* item;
    void sort(data list[], int left, int right);
    public: 
        Quick(data list[], int given_size);
        int return_count();
        void print(ostream& stream);
};
#endif

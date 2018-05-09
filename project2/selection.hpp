#ifndef __SELECTION__
#define __SELECTION__

#include <fstream>
#include "data.hpp"

class Selection 
{
    //count the number of operation
    int count, size;
    data* item;
    void sort(data list[], int size);
    public: 
        Selection(data list[], int given_size);
        int return_count();
        void print(ostream& stream);
};
#endif

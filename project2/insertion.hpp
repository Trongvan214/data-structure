#ifndef __INSERTION__
#define __INSERTION__

#include <fstream>
#include "data.hpp"

class Insertion 
{
    //count the number of operation
    int count, size;
    data* item;
    void sort(data list[], int size);
    public: 
        Insertion(data list[], int given_size);
        int return_count();
        void print(ostream& stream);
};
#endif

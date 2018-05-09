//Author: Trong Van
//Student ID: x454v285
//Programming Number: 6

/*Description:  implement a binary search tree*/
/*
 * ---------------Program Start---------------------*
 *            set ramdom seed
 *            create a new bts
 *            generate 5 numbers that in the array
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "binary_search.hpp"

using namespace std;

int main()
{
    srand(time(0));
    Binary_search bst;
    bst.search(rand()%1001*5);
    bst.search(rand()%1001*5);
    bst.search(rand()%1001*5);
    bst.search(rand()%1001*5);
    bst.search(rand()%1001*5);
    return 0;
}

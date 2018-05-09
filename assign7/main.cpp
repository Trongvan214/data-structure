//Author: Trong Van
//Student ID: x454v285
//Programming Number: 7

/*Description:  hashing a random data set and find it later
 * 
 * Function Name: put_in
 * input: data array, storage array
 * output: none
 * return: none
 * 
 * Function Name: search
 * input: storage array, search value
 * output: index it was found or don't exit
 * return none
 *
 * ---------------Program Start---------------------*
 *            set ramdom seed
 *            generate number between 2300 and 2600 put in data
 *            filled the storage array with the value -1
 *            take the random data and store in storage
 *            generate test cases
 *            
 */
 
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void put_in(int data[], int storage[]);
void search(int storage[], int target);

int main() 
{
    //random seed generate
    srand(time(0));
    ofstream write("results.txt");
    int data[100];
    int storage[125];
    //filled the storage with default value of -1
    fill_n(storage, 125, -1);
    write << "Numbers generated" << endl;
    //generation ramdom values
    for(int i=0;i<100;i++)
    {
        data[i] = (rand()%301)+2300;
        //write generate value file
        write << data[i] << endl;
    }
    put_in(data, storage);
    //write to the file
    write << "Array" << endl;
    for(int i=0;i<125;i++)
    {
        write << i << "\t" << storage[i] << endl;
    }
    //test cases
    search(storage, (rand()%301)+2300);
    search(storage, (rand()%301)+2300);
    search(storage, (rand()%301)+2300);
    search(storage, (rand()%301)+2300);
    search(storage, (rand()%301)+2300);
    write.close();
    return 0;
}
//fucntion that put the random generated number in the storage
void put_in(int data[], int storage[])
{
    int location;
    for(int i=0;i<100;i++)
    {
       location =  data[i]%101;
       //colision probing forward
       while(storage[location] != -1)
       {
           location+=3;
            //if forward no spot start 0 again
            if(location > 125)
            {
                //can't -126 and include 0 index because 
                //there a super small chance when a number can't be store
                //infinite loop happen if so (test if you like) 
                //line 84 and 115 switch -125 to -126
                location = location-125;
            }
       }
       storage[location] = data[i];
    }
}
//a function that search for the given target in the storage
void search(int storage[], int target)
{
    int location = target%101;
    bool will_search = false;
    cout << "Searching for " << target << endl;
    //quick check to see if the number is in storage
    for(int i=0;i<125;i++)
    {
        if(storage[i] == target)
        {
            will_search = true;
            //complating on whether to use break for efficiency
        }
    }
    if(will_search)
    {
        //colision probing forward
        while(storage[location] != target)
        {
            cout << "Search for location " << location << endl;
            location+=3;
            if(location > 125)
            {
                location = location-125;
            }
        }
        cout << "Found at location " << location << endl;
    }
    else 
    {
        cout << "Not Found" << endl;
    }
}

#include <iostream>
#include "quick.hpp"

using namespace std; 
//prototype
int partition(data list[], int left, int right);
void exchange3(data list[],int i,int j);

//pass in array and size and sort it right away
Quick::Quick(data list[], int given_size)
{
    count = 0;
    item = list;
    size = given_size;
    sort(list,0,size-1);
}
//sort function that sort the array
void Quick::sort(data list[], int left, int right)
{
    count+=1;
    //jump out of the void function (mean this part is sorted)
    if(left >= right)
    {
        return;
    }
    int arrPart = partition(list,left,right);
    //arrPart-1 cause the return value is the middle and sorted
    sort(list,left,arrPart-1);
    //arrpart+1 for the same reason
    sort(list,arrPart+1,right);
}
//return count
int Quick::return_count()
{
    return count;
}
//print the list out 
void Quick::print(ostream& stream)
{
    for(int i=0;i<size;i++)
    {
        stream << item[i].key << " " << item[i].s << endl;
    }
    cout << endl;
}

//function that move arround a small piece of the list
int partition(data list[], int left, int right) {
    int mid = left + (right - left) / 2;
    int pivot = list[mid].key;
    //put pivot in value in the left
    exchange3(list, mid, left);
    //left+1 cause pivot is at index 0
    int i = left + 1;
    int j = right;
    while (i <= j) 
    {
        //left find value that's greater
        while(i <= j && list[i].key <= pivot) {
            i++;
        }
        //right find the value that's less than pivot
        while(i <= j && list[j].key > pivot) {
            j--;
        }
        //exchange them 
        if (i < j) {
            exchange3(list,i,j);
        }
    }
    //put pivot back in the middle (i-1) is the middle
    exchange3(list,i-1,left);
    //return middle of this partition
    return i - 1;
}
//swamp the values at the given array locations
//share with all sort
void exchange3(data list[],int i,int j)
{
    data temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}


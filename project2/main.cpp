/*Name: 	Trong Van
*ID:        X454V285
* 
*Name: 	    Mohammad Alhaj
*ID: 	    K362J964
* 
* Project: #2
* 
* Description: This project is about creating different sorting algorithm and 
*               testing them out and different array sizes and cases to see 
*               which is the fastest smallest and just analyzes how it work
* 
* ------------------Program Start--------------------------
*               declare the data and generate them
*               testing them on all the sorts 
*               collect their data and sent it to the correct files
*               write an analyzes on what you see
**/
#include <iostream>	 
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include "data.hpp"
#include "quick.hpp"
#include "shell.hpp"
#include "bubble.hpp"
#include "insertion.hpp"
#include "selection.hpp"
#include "bst.hpp"

//function prototype
void randomGen(data list[], int SIZE);
void sortGen(data list[], int SIZE);
void writeSortInfo(int s, int b, int q, int ss, int i,
                    int bb, int SIZE, ostream& write, bool isOrder);
void writeAnalyze();

using namespace std;

int main()            
{
    srand(time(0));
    //declare the array and sizes
    const int SIZE1 = 50, SIZE2 = 5000, SIZE3 = 100000;
    data arr1[SIZE1];
    data arr2[SIZE2];
    data arr3[SIZE3];
    data sorted[SIZE2];
    //generate randoms number for all the array
    randomGen(arr1,SIZE1);
    randomGen(arr2,SIZE2);
    randomGen(arr3,SIZE3);
    //generate a sort array
    sortGen(sorted,SIZE2);
    //write object
    cout << "Prepare to wait, it take a while" << endl;
    cout << "YOU CAN MODIFY THE SIZE (LINE 46)" << endl;
    cout << "ctr+c to quit current" << endl;
    ofstream write;
    
/*----write to quicksort-----*/
    
    //size = 50
    write.open("qui050.txt");
    Quick qui050(arr1,SIZE1);
    qui050.print(write);
    write.close();
    
    //size = 5000
    write.open("qui500.txt");
    Quick qui500(arr2,SIZE2);
    qui500.print(write);
    write.close();
    
    //size = 100000
    write.open("qui100.txt");
    Quick qui100(arr3,SIZE3);
    qui500.print(write);
    write.close();

    
/*----write to selection sort-----*/

    //size = 50
    write.open("sel050.txt");
    Selection sel050(arr1,SIZE1);
    sel050.print(write);
    write.close();
    
    //size = 5000
    write.open("sel500.txt");
    Selection sel500(arr2,SIZE2);
    sel500.print(write);
    write.close();
    
    //size = 100000
    write.open("sel100.txt");
    Selection sel100(arr3,SIZE3);
    sel100.print(write);
    write.close();
    
/*----write to insertion sort-----*/
    
    //size = 50
    write.open("ins050.txt");
    Insertion ins050(arr1,SIZE1);
    ins050.print(write);
    write.close();
    
    //size = 5000
    write.open("ins500.txt");
    Insertion ins500(arr2,SIZE2);
    ins500.print(write);
    write.close();
    
    //size = 100000
    write.open("ins100.txt");
    Insertion ins100(arr3,SIZE3);
    ins100.print(write);
    write.close();

/*----write to bubble sort-----*/
    
    //size = 50;
    write.open("bub050.txt");
    Bubble bub050(arr1,SIZE1);
    bub050.print(write);
    write.close();
    
    //size = 5000;
    write.open("bub500.txt");
    Bubble bub500(arr2,SIZE2);
    bub500.print(write);
    write.close();    
    
    //size = 100000;
    write.open("bub100.txt");
    Bubble bub100(arr3,SIZE3);
    bub100.print(write);
    write.close();
    
/*----write to shell sort-----*/

    //size = 50;
    write.open("sll050.txt");
    Shell sll050(arr1,SIZE1);
    sll050.print(write);
    write.close();
    
    //size = 5000;
    write.open("sll500.txt");
    Shell sll500(arr2,SIZE2);
    sll500.print(write);
    write.close();    
    
    //size = 100000;
    write.open("sll100.txt");
    Shell sll100(arr3,SIZE3);
    sll100.print(write);
    write.close();
    
/*----write to bst sort-----*/

    //size = 50;
    write.open("bst050.txt");
    BST bst050(arr1,SIZE1);
    bst050.print_in_order(write);
    write.close();
    
    //size = 5000;
    write.open("bst500.txt");
    BST bst500(arr2,SIZE2);
    bst500.print_in_order(write);
    write.close();    
    
    //size = 100000;
    write.open("bst100.txt");
    BST bst100(arr3,SIZE3);
    bst100.print_in_order(write);
    write.close();
   
/*----sorted arr test-----*/

    Quick quiSorted(sorted,SIZE2);
    Shell sllSorted(sorted,SIZE2);
    Insertion insSorted(sorted,SIZE2);
    Bubble bubSorted(sorted,SIZE2);
    Selection selSorted(sorted,SIZE2);
    BST bstSorted(sorted,SIZE2);
    
/*----write to sortinfo-----*/

   write.open("sortinfo.txt");
    
    //info for size 50
    writeSortInfo(  sel050.return_count(),
                    bub050.return_count(),
                    qui050.return_count(),
                    sll050.return_count(),
                    ins050.return_count(),
                    bst050.return_count(),
                    SIZE1,
                    write,
                    false);
    //info for size 5000
    writeSortInfo(  sel500.return_count(),
                    bub500.return_count(),
                    qui500.return_count(),
                    sll500.return_count(),
                    ins500.return_count(),
                    bst500.return_count(),
                    SIZE2,
                    write,
                    false);
    //info for size 100000
    writeSortInfo(  sel100.return_count(),
                    bub100.return_count(),
                    qui100.return_count(),
                    sll100.return_count(),
                    ins100.return_count(),
                    bst100.return_count(),
                    SIZE3,
                    write,
                    false);
    //info for sorted 
    writeSortInfo(  selSorted.return_count(),
                    bubSorted.return_count(),
                    quiSorted.return_count(),
                    sllSorted.return_count(),
                    insSorted.return_count(),
                    bstSorted.return_count(),
                    SIZE2,
                    write,
                    true);
                    
    write.close();
    
    writeAnalyze();

	return 0;
}
//generator a random number and string for the whole array
void randomGen(data list[], int SIZE)
{
    string s[5] = {"banana","apple","orange","mango","watermelon"};
    for(int i=0;i<SIZE;i++)
    {
        list[i].key = rand()%(SIZE*2);
        list[i].s = s[rand()%5];
    }
}
//generator a sorted number for the array
void sortGen(data list[], int SIZE)
{
    string s[5] = {"banana","apple","orange","mango","watermelon"};
    for(int i=0;i<SIZE;i++)
    {
        list[i].key = 5*i;
        list[i].s = s[i%5];
    }
}
//write to the sortinfo.txt
void writeSortInfo(int s, int b, int q, int ss, int i,
                    int bb, int SIZE, ostream& write, bool isOrder)
{
    int sel = SIZE*SIZE;
    int bub = SIZE*SIZE;
    int ins = SIZE*SIZE;
    int qui = log10(SIZE)*SIZE;
    int sll = pow(SIZE,1.25);
    int bts = SIZE;
    write << "Infomation for size " << SIZE << endl;
    write << "Big – O cal selection sort O(n^2): " << sel << endl;
    write << "Big – O cal insert sort O(n^2): " << ins << endl;
    write << "Big – O cal bubble sort: O(n^2): " << bub << endl;
    write << "Big – O cal quick sort O(n*log(n): " << qui << endl; 
    write << "Big – O cal shell sort O(n^1.25): " << sll << endl;
    write << "Big – O cal bst O(n): " << bts << endl;
    write << endl;
    //it's the sorted data pass in this use format
    if(isOrder)
    {
        write << "Selection sort operations (sorted): " << s << endl;
        write << "Straight insertion sort operations (sorted): " << i << endl;
        write << "Bubble sort operations (sorted): " << b << endl;
        write << "Quick sort operations (sorted): " << q << endl;
        write << "Shell sort operations (sorted): " << ss << endl;
        write << "Binary search tree operations (sorted): " << bb << endl;
    }
    else 
    {
        write << "Selection sort operations (unsorted): " << s << endl;
        write << "Straight insertion sort operations (unsorted): " << i << endl;
        write << "Bubble sort operations (unsorted): " << b << endl;
        write << "Quick sort operations (unsorted): " << q << endl;
        write << "Shell sort operations (unsorted): " << ss << endl;
        write << "Binary search tree operations (unsorted): " << bb << endl;
    }
    write << "----------------------------------------------------" << endl;
    write << endl;
}

//write my thoughts about all the sorts 
void writeAnalyze()
{
    ofstream write("analyze.txt");
    write << "My thought on all the sorts is that bubble is the worst when\n";
    write << "it comes to almost all the different cases. In term of which\n";
    write << "perform the fastest it's certainly quicksort. It dominated\n";
    write << "most cases, but couldn't beat insertion on sorted array.\n";
    write << "Bubble is good when it comes to small sizes and easy to make.\n";
    write << "Overall, all the sorts were very interesting in terms of the\n";
    write <<"logic behind it. I think personally quick and shell is the best\n";  
    write.close();
}

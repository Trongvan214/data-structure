//Author: Trong Van
//Student ID: x454v285
//Programming Number: 1

/*The program let you keep track of your inventory of your store by entering in
 * the the cost, item name, how many, and total cost of it all...
 * It will automatically save every details about it in another file. */

/*
 * Function Name: guideMenu   =>
 * Parameters: none
 * Return: void
 * Functionality: print out a menu
 * 
 * Function Name: programMenu  =>
 * Parameters: 
 * 			1st: take the list(array of struct)
 * 			2nd: keep track of how many list
 * Return: void
 * Functionality: ask for user input and do certain task
 * 
 * Function Name: printFullList   =>
 * Parameters: 
 * 			1st: take stream type(cout or ifstream)
 * 			2nd: take the list 	
 * 			3rd: the index (which array #)
 * Return: void
 * Functionality: print out the details of that list (partName, Number ..)
 * 
 * Function Name: askForFullList   =>
 * Parameters:
 * 			1st: take the list
 * 			2nd: the index 
 * Return: void
 * Functionality: prompt the user to enter that list info (partName, Number..)
 * 
 * Function Name: writeToFile     =>
 * Parameters:
 * 			1st: take the list
 * 			2nd: total number of list enter
 * Return: void
 * Functionality: put the array of list to a file
 * 
 *------------------Program starts-----------------
 * 
 *	if the inventory file exist 
 * 		print out the list of array
 * 	else 
 * 		print out the guideMenu
 * 		start programMenu
 * 			ask user for input 
 * 				if user input = 1
 * 					printFullList to print out the lists
 * 				else if user input = 2
 * 					start askForFullList and for user to fill in list info
 * 				else if  user input = 3
 * 					start ask for which list to modify
 * 					than start askForFullList and fill in list info
 * 				else if user input = 4
 * 					print out the total cost of all the list added together
 * 				else if user input = 5 
 * 					end the program start writeToFile
 * 					which put everything in a file 
 * 
 * */
 
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct item 
{
    int partNumber;
    string description;
    int quantity;
    float itemPrice;
    float totalCost;
};

//function prototypes 
void guideMenu();
void programMenu(item* list, int* totalListEnter);
void printFullList(ostream& stream, item* list, int index);
void askForFullList(item* list, int index);
void writeToFile(item* list, int totalListEnter);

int main () 
{	
    //array of list
    item list[100]; 
    int totalListEnter = 0;
    string line;
    ifstream read("inventory.txt");
    if(read.good())
    {  
        while(getline(read, line))
        {
            cout << line << endl;
        }
        read.close();
    }
    else 
    {
        read.close();
        guideMenu();
        //past in the address of list and totalListEnter
        programMenu(list,&totalListEnter);
    }
   return 0;
}
//give the users inforamtion about the choices they can choose
void guideMenu() 
{
    cout << "1: Print out all parts" << endl;
    cout << "2: Enter a new part" << endl;
    cout << "3: Modify existing part" << endl;
    cout << "4: Print inventory total" << endl;
    cout << "5: Exit the program\n\n";
}
//the main program what let user choose what they pick
//paramter both point to the address to modify and not make of a copy 
void programMenu(item* list, int* totalListEnter)
{
    int userMenuInput;
    float totalInventorySum = 0;
    //hasItem control whether we can print all the list out or not
    bool hasItem = false;
    //do-while will repeat until input 5 was enter
    do
    {
        cout << "Please choose one of the choices\n";
        cin >> userMenuInput;
        //input 1 to print all the list that's created
        if(userMenuInput == 1)
        {
            if(hasItem)
            {
                //dereference to get the value
                for(int i = 0; i < *totalListEnter; i++)
                {
                    printFullList(cout,list,i);
                }
            }
            else 
            {
                cout << "There are no item in here yet\n\n";
            }
        }
        //input 2 to add more list
        else if(userMenuInput == 2)
        {
            hasItem = true;
            //ask the information about the list item
            //value of the totalListEnter act as the current list array #
            askForFullList(list,*totalListEnter);
            //add up the total from each list
            totalInventorySum += list[*totalListEnter].totalCost;
            //changing to the next empty list and total up list
            *totalListEnter = *totalListEnter+1;
        }
        //input 3 to modify existed list
        else if(userMenuInput == 3)
        {
            //modify# will be -1 alot of time because index start at 0 
            //so this is needed to access the right list
            int modifyPartNumber;
            //ask user until they give a part that is correspond to a list
            do
            {
            cout << "Enter part to modify: " ;
            cin >> modifyPartNumber;
            } while(modifyPartNumber > *totalListEnter);
            printFullList(cout,list,modifyPartNumber-1);
            askForFullList(list,modifyPartNumber-1);
        }
        //print out the total cost of inventory
        else if(userMenuInput == 4)
        {
            cout << "Total cost of inventory: $" << totalInventorySum << endl;
        }
    } while(userMenuInput != 5);
    //when user press 5 put in the whole inventory of list in a file
    writeToFile(list, *totalListEnter);
}

//To print out all the details on a certain list
//1 stream object that I can use to either cout || write to a file
//2 parameter point to the list address to modify/read from
//3 parameter is the list # that we will read from
void printFullList(ostream& stream, item* list, int index)
{
	stream << setw(5) << left << list[index].partNumber;
    stream << setw(30) << left << list[index].description; 
    stream << setw(5) << left <<list[index].quantity; 
    stream << setw(5) << "$" << list[index].itemPrice; 
    stream << setw(5) << "$" << list[index].totalCost << endl;
}
//To ask for the details of a given list
//1 parameter point to the list address to modify/read from
//2 parameter is the list # that the info will save in
void askForFullList(item* list, int index)
{
    cout << "Enter Item: ";
    cin.ignore();
    //cin that lets us have spaces
    getline(cin, list[index].description);
    cout << "Enter quantity: ";
    cin >> list[index].quantity;
    cout << "Enter cost: ";
    cin >> list[index].itemPrice;
    cout << endl;
    list[index].partNumber = index+1;
    list[index].totalCost = list[index].quantity * list[index].itemPrice;
}
//write the whole inventory of list to a file
//1 parameter point to the list address to modify/read from
//2 parameter is the value of the totalListEnter
void writeToFile(item* list, int totalListEnter)
{
    ofstream write("inventory.txt");
    for(int i = 0; i < totalListEnter; i++)
    {
        printFullList(write, list, i);
    }
}


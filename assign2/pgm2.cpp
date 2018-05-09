//Author: Trong Van
//Student ID: x454v285
//Programming Number: 2

/*you are suppose to create a class that have let users add trips and you can 
 * than calculated and find all the information about their fuel usage.*/

/* Constructor Name: Odometer      =>
 * Parameters: no./ne (void)
 * Functionality: set all the miles, gallons, and m/gal to 0
 * 
 * Constructor Name: Odometer   =>
 * Parameters: 
 *          1st: takes in the numbers of gallons
 *          2nd: takes in the numbers of miles
 * Functionality: set the init value for gallons and miles
 * 
 * Function Name: addTrip   =>
 * Parameters:
 *          1st: takes in the numbers of gallons
 *          2nd: takes in the numbers of miles
 * Return: void
 * Functionality: updating  the total miles, gallons uage 
 *                & calculated the new miles per gallons
 * 
 * Function Name: checkMileage  =>
 * Parameters:
 *          1st: takes in the number of gallons
 * Return: float
 * Functionality: given the # of gallons find miles base on miles per gallons
 * 
 * Function Name: printInfo =>
 * Parameters: none
 * Return: void
 * Functionality: print out all the total miles, gallons, and lastest m/gal
 * 
 * ------------------Program starts-----------------
 *      When created an instance of a class
 *          if create with no parameter
 *              will set all the variables (miles,gallons,m/gal) to 0
 *          else and create with parameters
 *              set the init value for gallons and miles = parameters
 *          
 *      now you can use any of the functions to either add trips, check miles
 *      or print out all the information.
 * 
 */
 
#include <iostream>
using namespace std;


class Odometer 
{
    //all privates
    int milesDriven;
    float totalGallons, mperg; //mperg miles per gallons
    //all public
    public: 
        Odometer(void);
        Odometer(float gallons, int miles);
        void addTrip(float gallons, int miles);
        float checkMileage(float gallons);
        void printInfo();
};
Odometer::Odometer(void)
{
    milesDriven = totalGallons = mperg = 0;
}
Odometer::Odometer(float gallons, int miles)
{
    //set the init value of miles and gallons = to parameters
    milesDriven = miles;
    totalGallons = gallons;
    mperg = miles/gallons;
    
}
void Odometer::addTrip(float gallons, int miles)
{
    //add more miles to existing one
    milesDriven+=miles;
    //add more gallons to existing one
    totalGallons+=gallons;
    //find the new miles per gallons
    mperg = miles/gallons;
}
float Odometer::checkMileage(float gallons)
{
    return gallons * mperg;
}
void Odometer::printInfo()
{
    //print out miles, gallons, miles per gallons
    cout << "Miles driven: " << milesDriven << "\t";
    cout << "Gallons Used: " << totalGallons << "\t";
    cout << "Miles Per Gallon: " << mperg << endl;
}  
int main(void) 
{
    //setting everything to 0
    Odometer od;
    //add a trip using 20 gallons and went a total of 200 miles
    od.addTrip(20, 200);
    //add another trip using 30 gallons and went a total of  300 miles 
    od.addTrip(30,300);
    //do a check on the miles per gallons with 40 gallons
    cout << "How many miles you can get with the given gallons ";
    cout << od.checkMileage(40) << endl;
    //print out all the information about the trips 
    od.printInfo();
    
    //set the init values for total miles and total gallons used
    Odometer od1(20, 700);
    //do a check on the miles per gallons with 20 gallons
    cout << "How many miles you can get with the given gallons ";
    cout << od1.checkMileage(20) << endl;
    //another another trip 
    od1.addTrip(40, 300);
    //print out all the info about the trip
    od1.printInfo();
    
    Odometer od2(50.50, 500);
    cout << "How many miles you can get with the given gallons ";
    cout << od2.checkMileage(30) << endl;
    od2.addTrip(40, 300);
    od2.addTrip(10, 50);
    od2.printInfo();
    return 0;
}

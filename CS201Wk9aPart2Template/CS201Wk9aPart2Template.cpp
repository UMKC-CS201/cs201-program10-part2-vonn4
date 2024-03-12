// CS201Wk8PersonClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Function.h"


//add Static Member initialization
int Person::totalPeople = 0;
int Student::totalStudents = 0;
int Staff::totalStaff = 0;


int main()
{
    //create a vector of Person type
    vector<Person> myPeeps;
    vector<Student> myStudents;
    vector<Staff> myStaff;
    vector<Person> allPeople;

    // read the file & load into vector of Personal type
    readFile(myPeeps, myStudents, myStaff, allPeople);

    cout << "MY PEOPLEssss: " << endl;
    // print the vector
    printVector(myPeeps);
    printVector(myStudents);
    printVector(myStaff);
    printVector(allPeople);

}
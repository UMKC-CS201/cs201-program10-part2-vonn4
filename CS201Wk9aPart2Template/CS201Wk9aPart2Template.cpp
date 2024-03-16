// CS201Wk8PersonClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Name: Victor-Daniel Olatunji 
//PGM: 

#include "Function.h"
#include "Person.h"


//add Static Member initialization
int Person::totalPeople = 0;
int Student::totalStudents = 0;
int Staff::totalStaff = 0;
int Teacher::totalTeachers = 0;
int Employee::totalEmployees = 0;


int main()
{
    //create a vector of Person type
    vector<Person> myPeeps;
    vector<Student> myStudents;
    //vector<Staff> myStaff;
    vector<Teacher> myTeachers;
    vector<Employee> myEmployees;
    vector<Person*> allPeople; //stores a pointer (the base class) to an object

    // read the file & load into vector of Personal type
    readFile(myPeeps, myStudents, myTeachers, myEmployees, allPeople);//***remember to modify this for the teachers and employees***

    // print the vector
    printVector(myPeeps);
    printVector(myStudents);
    //printVector(myStaff);
    printVector(myTeachers);
    printVector(myEmployees);
    printVector(allPeople);

}






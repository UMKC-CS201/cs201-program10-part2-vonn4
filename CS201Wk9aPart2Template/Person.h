#pragma once
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

class Person {
protected:
    char type; 
  string lname;
  string fname;
  int age;

public:
  Person();                            //constructor: default
  Person(string l, string f, int a);   //constructor: overloaded (needs correction)

  //add other accessors & mutators
  string getFName() { return fname; }         //accessor (first name)
  string getLName() { return lname; }
  int getAge() { return age; }
  void setFName(string f) { fname = f; }    //mutator (first name)
  void setLName(string l) { lname = l; }
  void setAge(int a) { this->age = a; }
  virtual void print();

  // add static member to count Persons created
  // where would this be updated?
  static int totalPeople;
};

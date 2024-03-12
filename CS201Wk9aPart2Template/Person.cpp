#include "Function.h"

//default constructor
Person::Person() {       //scope identifier Person::
  type  = 'P';
  lname = " ";
  fname = " ";
  age = 0;
  totalPeople++;
}

//correct the overloaded constructor
Person::Person(string l, string f, int a) {
  type  = 'P';
  lname = l;
  fname = f;
  age = a;
  totalPeople++;
}

//update this to print neatly
void Person::print () {
  //cout << "Name: " << fname << " " << lname << endl;
  //cout << "Age:  " << age << endl << endl;
  cout << type << left << setw(4) << " "
    << setw(15) << lname
    << setw(15) << fname
    << setw(5) << right << age << endl;
}
#pragma once
#include <iostream>
#include <iomanip>
#include "Staff.h"

class Teacher : public Staff {
private:
  string subject;

public:
  Teacher() : Staff() {
    subject = " ";
  }

Teacher(char t, string l, string f, int a, int h, float hr, string sub) :
  Staff(t, l, f, a, h, hr) {
  subject = sub;
  totalTeachers++;
  }
  string getSubject(){ return subject; }
void setSubject(string sub) { subject = sub; }
void print() {
  cout << type << left << setw(4) << " "
  << setw(15) << lname
  << setw(15) << fname
  << setw(5) << right << age
  << setw(10) << " " << hours << ", " << "hrlyRate: " << fixed << setprecision(2) << hrlyRate << ", " << "Subject:  " << subject << endl;
}
  static int totalTeachers;
};
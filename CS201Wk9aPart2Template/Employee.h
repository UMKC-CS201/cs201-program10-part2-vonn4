#pragma once
#include <iostream>
#include <iomanip>
#include "Staff.h" 

class Employee : public Staff {

private:
  float vacHours;
public:
  Employee() : Staff() {
    vacHours = 0.0;
    
  }
  Employee(char t, string l, string f, int a, int h, float hr, float v)
    : Staff(t, l, f, a, h, hr) {
      vacHours = v;
      totalEmployees++;
    }
  float getVacHours() { return vacHours; }
  void setVacHours(float v) { vacHours = v; }

  void print() {
    cout << Employee::type << left << setw(4) << " "
      << setw(15) << lname
      << setw(15) << fname
      << setw(5) << right << age
      << setw(10) << " " << hours <<  ", " << "hrlyRate: " << fixed << setprecision(2) << hrlyRate << ", " << "vacHours: " << fixed << setprecision(2) << vacHours << endl;
  }

  static int totalEmployees;
};
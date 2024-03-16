#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Staff.h"
#include "Teacher.h"
#include "Employee.h"


using namespace std;

int readFile(vector<Person>& person, vector<Student>& student, vector<Teacher>& teacher, vector<Employee>& employee, vector<Person*>& allPeople);
void printVector(vector<Person> person);
void printVector(vector<Student> student);
//void printVector(vector<Staff> staff);
void printVector(vector<Teacher> teacher);
void printVector(vector<Employee> employee);
void printVector(vector<Person*> allPeople);

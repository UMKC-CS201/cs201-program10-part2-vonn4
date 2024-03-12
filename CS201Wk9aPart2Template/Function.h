#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Staff.h"

using namespace std;

int readFile(vector<Person>&,vector<Student>&, vector<Staff>&, vector<Person> &all);
void printVector(vector<Person>);
void printVector(vector<Student>);
void printVector(vector<Staff>);

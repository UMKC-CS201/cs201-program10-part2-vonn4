#include "Student.h"

Student::Student() : Person() {
	type = 'S';
	gpa = 0.0;
	totalStudents++;
}

Student::Student(string l, string f, int a, float g)
	: Person(l, f, a) {
	type = 'S';
	gpa = g;
	totalStudents++;
}

void Student::print() {
	cout << type << left << setw(4) << " "
		<< setw(15) << lname
		<< setw(15) << fname
		<< setw(5) << right << age 
		<< setw(13) << gpa << endl;
}
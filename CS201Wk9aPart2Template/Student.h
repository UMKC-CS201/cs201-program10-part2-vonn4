#pragma once
#include "Person.h"

class Student : public Person {
private:
	float gpa;

public:
	Student();
	Student(string l, string f, int a, float g);

	float getGPA(){ return gpa; }
	void  setGPA(float g) { gpa = g; }

	void print();
	static int totalStudents;
};
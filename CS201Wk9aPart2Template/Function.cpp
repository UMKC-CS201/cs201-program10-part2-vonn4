#include "Function.h"

int readFile(vector<Person>& people, vector<Student>& students, vector<Teacher>& teacher, vector<Employee>& employee, vector<Person*> &allPeople) {
	//***remember to modify this for the teachers and employees***

  //OPEN THE INPUT FILE
	ifstream inFile;
	inFile.open("people.txt");
	if (!inFile.is_open()) {
		cout << "File is not open" << endl;
		return 1;
	}

  //SET TEMPORARY VARIABLES FOR INPUTTING PERSON INFORMATION
	string inRec, tempStr;
	vector <string> row;

  //LOOP THROUGH THE INPUT FILE
	while (getline(inFile, inRec)) {
    //CHANGE THE INPUT RECORD inRec TO BECOME STRING STREAM inSS
    //THIS WILL ALLOW US TO USE THE RECORD inRec AS THOUGH IT IS
    //AN INPUT STREAM (USEFUL WHEN INPUT IS NOT FIXED)
		stringstream inSS(inRec);
		row.clear();
    // loop through string stream, partioning on ','
    // push each string onto the row vector
		while (getline(inSS, tempStr, ',')) {
			row.push_back(tempStr);
		}
    // try to create a person object 
    // calling constructor with lastname row[1], firstname row[2] and age
    // convert the string 'age' to an integer
    try{
		if (row[0][0] == 'S') {
			Student tempS(row[1], row[2], stoi(row[3]), stof(row[4]));
			students.push_back(tempS);
			Student* tempSP = new Student(row[1], row[2], stoi(row[3]), stof((row[4])));
			allPeople.push_back(tempSP);
		}
	
		else if (row[0][0] == 'T') {
			Teacher tempT('T', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), row[6]);
			// if valid, push the object onto the vector
			teacher.push_back(tempT);
			Teacher* tempTP = new Teacher('T', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), row[6]);
			allPeople.push_back(tempTP);
		}
		else if (row[0][0] == 'E') {
			Employee tempE('E', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), stof(row[6]));
			// if valid, push the object onto the vector
			employee.push_back(tempE);
			Employee* tempEP = new Employee('E', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), stof(row[6]));
			allPeople.push_back(tempEP);
		}
		
    else  {
			Person tempP(row[1], row[2], stoi(row[3]));
			// if valid, push the object onto the vector
			people.push_back(tempP);
			Person* tempPP = new Person(row[1], row[2], stoi(row[3]));
			//create a Person and allocate memory for it
			//pointer of person type with the same information as person
			allPeople.push_back(tempPP);
      }
    }
    catch(...){
      cout << "RECORD: " << inRec << " IS IN ERROR\n";
    }
  }
	inFile.close();
	return 0;
}

// write the code to print the vector
void printVector(vector<Person> people) {
 
  cout << "\n\nTYPE" << setw(11) << "LAST NAME"
  << setw(17) << "FIRST NAME" << setw(8) << "AGE"
  << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  for (int i = 0; i < people.size(); i++)
      people.at(i).print(); 

  cout << "\nTOTAL PEOPLE: " << Person::totalPeople << endl;
}
// write the code to print the vector
void printVector(vector<Student> student) {

	cout << "\n\nTYPE" << setw(11) << "LAST NAME"
		<< setw(17) << "FIRST NAME" << setw(8) << "AGE"
		<< setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
	for (int i = 0; i < student.size(); i++)
		student.at(i).print();

	cout << "\nTOTAL STUDENTS: " << Student::totalStudents << endl;
}

// write the code to print the vector
//void printVector(vector<Staff> staff) {
//
//  cout << "\n\nTYPE" << setw(11) << "LAST NAME"
//    << setw(17) << "FIRST NAME" << setw(8) << "AGE"
//    << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
//  for (int i = 0; i < staff.size(); i++)
//    staff.at(i).print();
//
//  cout << "\nTOTAL STAFF: " << Staff::totalStaff << endl;
//}

void printVector(vector<Person*> allPeople) {

	cout << "\n\nTYPE" << setw(11) << "LAST NAME"
		<< setw(17) << "FIRST NAME" << setw(8) << "AGE"
		<< setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
	for (int i = 0; i < allPeople.size(); i++)
		allPeople.at(i)->print();

	cout << "\nTOTAL PEOPLE: " << Student::totalStudents + Teacher::totalTeachers + Employee::totalEmployees +Person::totalPeople << endl;
}

/*
Questions for Professor Gladbach:
1. How should I set up my print functions - do I need the * and the &?
2. I get an error about the .exe file not being found, what can I do about this?
3. Have I made all the necessary changes to my allPeople declaration in main.cpp, function.cpp, and function.h?
*/


//statements for print function of teacher and employee objects

void printVector(vector<Teacher> teacher){

  cout << "\n\nTYPE" << setw(11) << "LAST NAME"
	<< setw(17) << "FIRST NAME" << setw(8) << "AGE"
	<< setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  for (int i = 0; i < teacher.size(); i++)
	teacher.at(i).print();

  cout << "\nTOTAL TEACHERS: " << Teacher::totalTeachers << endl;
}

void printVector(vector<Employee> employee){

  cout << "\n\nTYPE" << setw(11) << "LAST NAME"
	<< setw(17) << "FIRST NAME" << setw(8) << "AGE"
	<< setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  for (int i = 0; i < employee.size(); i++)
	employee.at(i).print();

  cout << "\nTOTAL EMPLOYEES: " << Employee::totalEmployees << endl;
}


//statements for pushing teacher and employee objects to respective vectors
/*
else if (row[0][0] == 'T') {
			Teacher tempT('W',row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), row[6] );
			// if valid, push the object onto the vector
			teacher.push_back(tempT);
			Teacher* tempTP = new Teacher('W', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), row[6]);
			allPeople.push_back(tempTP);
		}
*/

/*
else if (row[0][0] == 'E'){
			Employee tempE('W',row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), stof(row[6]) );
			// if valid, push the object onto the vector
			employee.push_back(tempE);
			Teacher* tempEP = new Teacher('W', row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]), stof(row[6]));
			allPeople.push_back(tempEP);
}
*/
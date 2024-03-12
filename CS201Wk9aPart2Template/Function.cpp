#include "Function.h"

int readFile(vector<Person>& people, vector<Student>& students, 
             vector<Staff>& staff, vector<Person> &allPeople) {

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
			allPeople.push_back(tempS);
		}
		else if ((row[0][0] == 'E') || (row[0][0] == 'T')) {
			Staff tempE('W',row[1], row[2], stoi(row[3]), stoi(row[4]), stof(row[5]));
			// if valid, push the object onto the vector
			staff.push_back(tempE);
			allPeople.push_back(tempE);
		}
    else  {
        Person tempP(row[1], row[2], stoi(row[3]));
        // if valid, push the object onto the vector
        people.push_back(tempP);
        allPeople.push_back(tempP);
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
void printVector(vector<Staff> staff) {

  cout << "\n\nTYPE" << setw(11) << "LAST NAME"
    << setw(17) << "FIRST NAME" << setw(8) << "AGE"
    << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;
  for (int i = 0; i < staff.size(); i++)
    staff.at(i).print();

  cout << "\nTOTAL STAFF: " << Staff::totalStaff << endl;
}


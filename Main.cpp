#include <string>
#include <sstream>
#include <iostream>
#include "Roster.h"

using std::string;
using std::stringstream;
using std::cout;

int main() {

	cout << "Name:     Allen Richardson\n";
	cout << "ID:              001406429\n";
	cout << "Class:              C867\n\n";
	
	StudentRoster studentRoster;
	string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Allen,Richardson,aric499@wgu.edu,24,20,25,30,SOFTWARE",
	};
	for (int i = 0; i < 5; i++) {

		string studentString = studentData[i];
		vector<string> st;
		stringstream studentStream(studentString);
		while (studentStream.good())
		{
			string substr;
			getline(studentStream, substr, ',');
			st.push_back(substr);
		}
		DegreeProgramEnum degreeProgram = DegreeProgramEnum::SOFTWARE;

		if (st.at(8).back() == 'Y') 
			degreeProgram = DegreeProgramEnum::SECURITY;
		if (st.at(8).back() == 'K')
			degreeProgram = DegreeProgramEnum::NETWORK;

			int* tempArray = new int[3];
			tempArray[0] = stoi(st.at(5));
			tempArray[1] = stoi(st.at(6));
			tempArray[2] = stoi(st.at(7));
						
			studentRoster.addStudent(st.at(0), st.at(1), st.at(2), st.at(3),
				(st.at(4)), stoi(st.at(5)), stoi(st.at(6)), stoi(st.at(7)), degreeProgram);
		

	}
	studentRoster.printAll();

	cout << "Displaying all Software students:\n";
	studentRoster.printByDegreeProgram(DegreeProgramEnum::SOFTWARE);

	cout << "\nDisplaying all Network students:\n";
	studentRoster.printByDegreeProgram(DegreeProgramEnum::NETWORK);

	cout << "\nDisplaying all Security students:\n";
	studentRoster.printByDegreeProgram(DegreeProgramEnum::SECURITY);

	cout << "\nDisplaying invalid emails\n";
	studentRoster.printInvalidEmail();

	cout << "\nDisplaying the average days remaining in course\n";
	for (int i = 0; i < studentRoster.numStudentRoster; i++) {

		studentRoster.printAverageDaysInCourse(studentRoster.studentRoster[i]->getIds());
	}

	cout << "\nRemoving A1: John Smith for bad performation: \n";
	studentRoster.removeStudent("A1");

	studentRoster.printAll();

	cout << "\nVerify removed: \n";
	studentRoster.removeStudent("A1");

	return 0;

}
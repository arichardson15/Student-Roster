#include <iostream>
#include "Roster.h"
using std::cout;

void StudentRoster::addStudent(string ids, string firstName, string lastName, string email, string age, int day1, int day2, int day3, DegreeProgramEnum degreeProgram)
{
	int courseArray[] = { day1,day2,day3 };
	studentRoster[++addPosition] = new Student(ids, firstName, lastName, email, age, courseArray, degreeProgram);
}

void StudentRoster::printAll()
{
	cout << "Displaying all students:\n";
	Student::displayHeader();
	for (int i = 0; i <= addPosition; i++)
	{
		studentRoster[i]->display();
	}
	cout << '\n';
}

void StudentRoster::printAverageDaysInCourse(string ids)
{
	cout << "Average days remaining for " << ids << ":\t";
	for (int i = 0; i <= StudentRoster::addPosition; i++)
	{
		if (studentRoster[i]->getIds() == ids)
		{

			cout << ((double)studentRoster[i]->getDays()[0]
				+ (double)studentRoster[i]->getDays()[1]
				+ (double)studentRoster[i]->getDays()[2]) / 3.0
				<< '\n';
		}
	}
}

void StudentRoster::printByDegreeProgram(DegreeProgramEnum degreeProgram)
{
	Student::displayHeader();
	for (int i = 0; i <= addPosition; i++)
	{
		if (studentRoster[i]->getDegreeProgram() == degreeProgram) {
			studentRoster[i]->display();
		}

	}
}

void StudentRoster::printInvalidEmail()
{
	for (int i = 0;i <= addPosition; i++) {

		bool email = true;
		string sn = studentRoster[i]->getEmail();
		if (sn.find("@") == string::npos) {
			email = false;
		}
		if (sn.find(".") == string::npos) {
			email = false;
		}
		if (sn.find(" ") != string::npos) {
			email = false;
		}

		if (email != true) {
			cout << "Invalid emails:" << sn << '\n';
		}
	}
		
}

void StudentRoster::removeStudent(string ids){

	bool found = false;
	for (int i = 0; i <= addPosition; i++){

		if (studentRoster[i]-> getIds() == ids){

			found = true;
			Student* temp = studentRoster[i];
			studentRoster[i] = studentRoster[addPosition];
			studentRoster[addPosition] = temp;
			cout << ids << " has been removed.\n\n";
			addPosition--;

					
		}
	}
	if (!found) cout << "Delete confirmed:" << ids << " is gone.\n";
}

StudentRoster::~StudentRoster(){
	for (int i = 0; i < numStudentRoster; i++) {

		delete studentRoster[i];
		studentRoster[i] = nullptr;
	}
}
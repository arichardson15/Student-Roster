#include <iostream>
#include "Student.h"
using std::cout;

Student::Student(string ids, string firstName, string lastName, string email, string age, int daysInCourse[courseArraySize], DegreeProgramEnum degreeProgram) {

	this->ids = ids;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}

Student::~Student()
{

}

string Student::getIds()
{
	return ids;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmail()
{
	return email;
}

string Student::getAge()
{
	return age;
}

int* Student::getDays()
{
	return daysInCourse;
}

DegreeProgramEnum Student::getDegreeProgram()
{
	return degreeProgram;
}

void Student::setIds(string ids)
{
	this->ids = ids;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setAge(string age)
{
	this->age = age;
}

void Student::setDays(int daysincourse[courseArraySize])
{
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
}

void Student::setDegreeProgram(DegreeProgramEnum degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

void Student::displayHeader()
{
	cout << "Ids\tFirst\tLast\t\tAge\tDays Remaining\tDegree Program\n";

}

void Student::display()
{
	cout << ids << '\t';
	cout << firstName << '\t';
	cout << lastName << '\t';
	cout << '\t' << age << '\t';
	cout << daysInCourse[0] << ',';
	cout << daysInCourse[1] << ',';
	cout << daysInCourse[2] << '\t';
	cout << DegreeProgramStrings[(int)degreeProgram] << "\n";

}

#pragma once
#include <string>
#include "Degree.h"
using std::string;

class Student
{
public:
	const static int courseArraySize = 3;
private:
	string ids = "";
	string firstName = "";
	string lastName = "";
	string email = "";
	string age = "";
	int daysInCourse[3] = { 0,0,0 };
	DegreeProgramEnum degreeProgram = DegreeProgramEnum::SOFTWARE;
public:
	Student(string Ids, string firstName, string lastName, string email, string age, int daysInCourse[courseArraySize], DegreeProgramEnum degreeProgram);
	~Student();
	string getIds();
	string getFirstName();
	string getLastName();
	string getEmail();
	string getAge();
	int* getDays();
	DegreeProgramEnum getDegreeProgram();

	void setIds(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setAge(string);
	void setDays(int[courseArraySize]);
	void setDegreeProgram(DegreeProgramEnum);

	static void displayHeader();

	void display();
};
#pragma once
#include <vector>
#include "Student.h"
using std::vector;

class StudentRoster
{
public:
	static const int numStudentRoster = 5;
	Student* studentRoster[numStudentRoster];

private:
	int addPosition = -1;
	vector<string> parsedStudentInfo;

public:
	void addStudent(string ids, string firstName, string lastName, string email, string age, int day1, int day2, int day3, DegreeProgramEnum st);
	void printAll();
	void printAverageDaysInCourse(string ids);
	void printByDegreeProgram(DegreeProgramEnum degreeProgram);
	void printInvalidEmail();
	void removeStudent(string ids);

	~StudentRoster();

};
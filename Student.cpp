#include "Student.h"

using namespace std;

Student::Student() {

}

Student::~Student() {

}

Student::Student(int sID, string sName, string sLevel, string sMajor, double sGPA, int sAdvisorID) {
	ID = sID;
	name = sName;
	level = sLevel;
	major = sMajor;
	gpa = sGPA;
	advisorID = sAdvisorID;
}

string Student::getMajor() {
	return major;
}

double Student::getGPA() {
	return gpa;
}

void Student::setAdvisor(int sAdvisorID) {
	sAdvisorID = advisorID;
}

int Student::getAdvisor() {
	return advisorID;
}

void Student::printStudent() {
	cout << "Student ID: " << ID << ", ";
	cout << "Student Name: " << name << ", ";
	cout << "Grade: " << level << ", ";
	cout << "Major: " << major << ", ";
	cout << "GPA: " << gpa << ", ";
	cout << "Advisor ID: " << advisorID << endl;
}
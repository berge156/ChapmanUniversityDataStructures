#include <iostream>
#include "Person.h"

using namespace std;

class Student : public Person {
public:

	Student();
	Student(int sID, string sName, string sLevel, string sMajor, double sGPA, int sAdvisorID);
	~Student();

	string major;
	double gpa;
	int advisorID;

	string getMajor();
	double getGPA();

	void setAdvisor(int sAdvisorID);
	int getAdvisor();

	void printStudent();

	bool operator == (const Student &s) {
		return (this->ID == s.ID);
	}
	bool operator != (const Student &s) {
		return (this->ID != s.ID);
	}
	bool operator < (const Student &s) {
		return (this->ID < s.ID);
	}
	bool operator > (const Student &s) {
		return (this->ID > s.ID);
	}
	bool operator <= (const Student &s) {
		return (this->ID <= s.ID);
	}
	bool operator >= (const Student &s) {
		return (this->ID >= s.ID);
	}
	

	friend ostream& operator << (ostream& output, const Student &s) {
		output << "Student ID: " << s.ID << endl;
		output << "Student Name: " << s.name << endl;
		output << "Grade: " << s.level << endl;
		output << "Major: " << s.major << endl;
		output << "GPA: " << s.gpa << endl;
		output << "Advisor ID: " << s.advisorID << endl;
		return output;
	}
};
#include <iostream>
#include "DoublyLinkedList.h"
#include "Person.h"

using namespace std;

class Faculty : public Person {
public:
	string department;
	unsigned int numAdvisee;
	unsigned int maxSize;

	int *adviseeArr;

	Faculty();
	~Faculty();
	Faculty(int mID, string mName, string mLevel, string mDepartment);

	void printFaculty();
	void printAdvisee();

	string getDepartment();

	int getAdviseeID();
	void addAdvisee(int mID);
	bool removeAdvisee(int adviseeID);

	int getSizeArr();

	bool operator == (const Faculty &f) {
		return (this->ID == f.ID);
	}
	bool operator != (const Faculty &f) {
		return (this->ID != f.ID);
	}
	bool operator < (const Faculty &f) {
		return (this->ID < f.ID);
	}
	bool operator > (const Faculty &f) {
		return (this->ID > f.ID);
	}
	bool operator <= (const Faculty &f) {
		return (this->ID <= f.ID);
	}
	bool operator >= (const Faculty &f) {
		return (this->ID >= f.ID);
	}
	

	friend ostream& operator << (ostream& output, const Faculty &f) {
		output << "Faculty ID: " << f.ID << endl;
		output << "Faculty Name: " << f.name << endl;
		output << "Level: " << f.level << endl;
		output << "Department: " << f.department << endl;
		output << "Advisee ID: "; //NEED CODE TO FIND THE NODE THAT IS THE ADVISEE NODE
		return output;
	}
};
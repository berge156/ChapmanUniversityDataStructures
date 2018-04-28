#include "Faculty.h"

using namespace std;

Faculty::Faculty() {

}

Faculty::~Faculty() {
	delete []adviseeArr;
}

Faculty::Faculty(int mID, string mName, string mLevel, string mDepartment) {
	ID = mID;
	name = mName;
	level = mLevel;
	department = mDepartment;

	adviseeArr = new int[5];
	numAdvisee = 0;
	maxSize = 5;

	for(int i = 0; i < 5; ++i) {
		adviseeArr[i] = -1;
	}
}

void Faculty::printFaculty() {
	cout << "Faculty ID: " << ID << ", ";
	cout << "Faculty Name: " << name << ", ";
	cout << "Level: " << level << ", ";
	cout << "Department: " << department << ", ";
	cout << "Advisee ID: ";
	printAdvisee();
}

void Faculty::printAdvisee() {
	if(numAdvisee == 0) {
		cout << "There are no advisees";
	}
	else {
		for(int i = 0; i < maxSize; ++i) {
			if(adviseeArr[i] != -1) {
				cout << adviseeArr[i];
				if(i < numAdvisee - 1) {
					cout << ", ";
				}
			} 
		}
	}
	cout << endl;
}

string Faculty::getDepartment() {
	return department;
}

int Faculty::getAdviseeID() {
	return numAdvisee;
}

void Faculty::addAdvisee(int mID) {
	if(numAdvisee != maxSize) {
		int temp = 0;

		for(int i = 0; i < maxSize; ++i) {
			if(adviseeArr[i] == ID) {
				temp = maxSize;
			}
		}

		while(temp < maxSize) {
			if(adviseeArr[temp] == -1) {
				adviseeArr[temp] = ID;
				++numAdvisee;
				break;
			}

			++temp;
		}
	}
	else {
		if(numAdvisee == maxSize) {
			int *tempArray = new int[numAdvisee];

			for(int i = 0; i < numAdvisee; ++i) {
				tempArray[i] = adviseeArr[i];
			}

			adviseeArr = new int[numAdvisee + 1];
			maxSize = numAdvisee + 1;

			for(int i = 0; i < numAdvisee + 1; ++i) {
				adviseeArr[i] = -1;
			}
			adviseeArr[++numAdvisee] = ID;
		}
	}
}

bool Faculty::removeAdvisee(int adviseeID) {
	bool removed = false;

	for(int i = 0; i < maxSize; ++i) {
		if(adviseeArr[i] == adviseeID) {
			adviseeArr[i] = -1;
			--numAdvisee;
			removed = true;
			cout << "The advisee has been removed" << endl;
		}	
		
	}
	return removed;
}

int Faculty::getSizeArr() {
	return maxSize;
}






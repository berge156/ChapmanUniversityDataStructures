#include <iostream>

#ifndef included
#define included

using namespace std;

class Person {

public:
	Person();
	~Person();

	int ID;
	string name;
	string level;

	int getID();
	void setID(int id);

	string getName();
	string getLevel();
	
};

#endif
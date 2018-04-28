#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string>
#include <fstream>
#include <sstream>
#include "BST.h"

using namespace std;

class Menu {
public:
	BST<Student> mainStudent;
	BST<Faculty> mainFaculty;

	Menu();
	~Menu();

	void readFile();
	void writeFile();
	void printMainStudent(TreeNode<Student> *s);
	void printMainFaculty(TreeNode<Faculty> *f);

	void outputMainStudent(TreeNode<Student> *s, string student);
	void outputMainFaculty(TreeNode<Faculty> *f, string faculty);

	TreeNode<Student>* getMainStudentRoot();
	TreeNode<Faculty>* getMainFacultyRoot();

	void printMenu();
	void printAllStudents();
	void printAllFaculty();
	void printStudent();
	void printFaculty();
	void printAdvisor();
	void printAdvisee();

	void addStudent();
	void deleteStudent();
	void addFaculty();
	void deleteFaculty();
	void changeAdvisor();
	void removeAdvisee();

	void rollback();

	void exit();
};
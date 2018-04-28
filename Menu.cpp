#include "Menu.h"

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::readFile() {
	ifstream mainStuFile;
	ifstream mainFacFile;

	sting input;
	int numStu = 0;
	int numFac = 0;
	int totFac = 0;
	int totAdvisee = 0;
	int numLine = 1;

	//Student Variables Intialized
	int sID = 0;
	string sName = "";
	string sLevel = "";
	string sMajor = "";
	double gpa = 0.0;
	int advisorID = 0;

	//Faculty Variables Initialized
	int fID = 0;
	string fName = "";
	string fLevel = "";
	string department = "";
	int adviseeID = 0;

	mainFacFile.open("facultyTable.txt");

	if(mainFacFile.is_open()) {
		try {
			getline(mainFacFile, input);

			if(input != "") {
				numFac = atoi(input.c_str());
			}
		}
		catch(exception e) {
			cout << "Something is Wrong With the File" << endl;
		}
	}

}

void Menu::writeFile() {
	ofstream mainStuFile;
	ofstream mainFacFile;

	mainStuFile.open("studentTable.txt");
	if(mainStuFile.is_open()) {
		mainStuFile << mainStudent.getSize() << endl;
		TreeNode<Student> *s = mainStudent.getRoot();
		outputMainStudent(s, "studentTable.txt");
	}

	mainStuFile.close();

	mainFacFile.open("facultyTable.txt");
	if(mainFacFile.is_open()) {
		mainFacFile << mainfaculty.getSize() << endl;
		TreeNode<Faculty> *f = mainFaculty.getRoot();
		outputMainFaculty(f, "facultyTable.txt");
	}
	mainFacFile.close();
}

void Menu::printMainStudent(TreeNode<Student> *s) {

}

void Menu::printMainFaculty(TreeNode<Faculty> *f) {

}

void Menu::outputMainStudent(TreeNode<Student> *s, string student) {

}

void Menu::outputMainFaculty(TreeNode<Faculty> *f, string faculty) {

}

TreeNode<Student>* Menu::getMainStudentRoot() {

}

TreeNode<Faculty>* Menu::getMainFacultyRoot() {

}

void Menu::printMenu() {

	string input;
	int numInput;
  bool triggered;
  bool running = true;

	cout <<"-------------------- MENU --------------------"<<endl;
	cout << 1 << "Print all students and their information (sorted by ascending ID #)"<<endl;
	cout << 2 << "Print all faculty and their information (sorted by ascending ID #)"<<endl;
	cout << 3 << "Find and display student information given the students ID"<<endl;
	cout << 4 << "Find and display faculty information given the faculty ID"<<endl;
	cout << 5 << "Given a student’s ID, print the name and info of their faculty advisor" << endl;
	cout << 6 << "Given a faculty ID, print ALL the names and info of his/her advisees." << endl;
	cout << 7 << "Add a new student" << endl;
	cout << 8 << "Delete a student given the ID" << endl;
	cout << 9 << "Add a new faculty member" << endl;
	cout << 10 << "Delete a faculty member given the id" << endl;
	cout << 11 << "Change a student’s advisor given the student ID and the new faculty ID." << endl;
	cout << 12 << "Remove an advisee from a faculty member given the ID's" << endl;
	cout << 13 << "Rollback" << endl;
	cout << 14 << "Exit the Program." << endl;

	cin >> input;

    try {
      numInput = atoi(input.c_str());

      if(numInput < 0 || numInput > 14) {
        cout << "Your Response was INVALID. Please try again. \n" << endl;
        triggered = true;
        numInput = 15;
      }
    }
    catch(exception e) {
      triggered = false;
      numInput = 15;
    }

    switch(numInput) {
      case 1:
        printAllStudents();
        break;
      case 2:
        printAllFaculty();
        break;
      case 3:
        printStudent();
        break;
      case 4:
        printFaculty();
        break;
      case 5:
        printAdvisor();
        break;
      case 6:
        printAdvisee();
        break;
      case 7:
        addStudent();
        break;
      case 8:
        deleteStudent();
        break;
      case 9:
        addFaculty();
        break;
      case 10:
        deleteFaculty();
        break;
      case 11:
        changeAdvisor();
        break;
      case 12:
        removeAdvisee();
        break;
      case 13:
        rollback();
        break;
      case 14:
        exitMenu();
        return;
      default:
        if(triggered == true) {
          continue;
        }
        else {
          cout << "Your Response was INVALID. Please try again. \n" << endl;
          continue;
        }
    }
  }

void Menu::printAllStudents() {

}

void Menu::printAllFaculty() {

}

void Menu::printStudent() {

	if (mainStudent.isEmpty())
	{
		cout << "There is no current Students in the Database" << endl;
	}

	else
	{
		printMainStudent(mainStudent.getRoot());
	}

}

void Menu::printFaculty() {

	if (mainFaculty.isEmpty())
	{
		cout << "There is no current faculty in the database" << endl;
	}

	else
	{
		printMainFaculty(mainFaculty.getRoot());
	}

}

void Menu::printAdvisor() {

}

void Menu::printAdvisee() {

}

void Menu::addStudent() {

}

void Menu::deleteStudent() {

}

void Menu::addFaculty() {

}

void Menu::deleteFaculty() {

}

void Menu::changeAdvisor() {

}

void Menu::removeAdvisee() {

}

void Menu::rollback() {

}

void Menu::exitMenu() {

	cout << "Thank you for using our program. See you soon..." << endl;

}

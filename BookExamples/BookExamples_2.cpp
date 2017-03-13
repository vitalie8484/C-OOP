#include <iostream>
#include <string>

using namespace std;

class GradeBook2
{
public:
	void setCourseName(string name)
	{
		courseName = name;
	}

	string getCourseName() const
	{
		return courseName;
	}

	void displayMessage() const
	{
		cout << "Welcome to the grade book for " << getCourseName() << "!" << endl;
	}
	
private:
	string courseName;
};

//int main()
//{
//	string nameOfCourse;
//	GradeBook2 gradeBook;
//
//	cout << "Initial course name is:" << gradeBook.getCourseName() << endl;
//
//	cout << "\nPlease enter the course name:" << endl;
//	getline(cin, nameOfCourse);
//	gradeBook.setCourseName(nameOfCourse);
//
//	cout << endl;
//
//	gradeBook.displayMessage();
//
//	nameOfCourse = "qqqqq";
//
//	cout << endl;
//
//	gradeBook.displayMessage();
//}
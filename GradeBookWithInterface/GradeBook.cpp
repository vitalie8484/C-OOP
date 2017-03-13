#include <iostream>
#include "GradeBook.h"

using namespace std;

GradeBook::GradeBook(string name) : courseName(name)
{

}

void GradeBook::setGradeBook(string name)
{
	courseName = name;
}

string GradeBook::getGradeBook() const
{
	return courseName;
}

void GradeBook::displayMessage() const
{
	cout << "Welcome to the grade book for " << getGradeBook() << "!" << endl;
}
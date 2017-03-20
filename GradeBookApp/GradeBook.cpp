#include <iostream>
#include <iomanip>
#include "GradeBook.h"

using namespace std;

GradeBook::GradeBook(string name) 
	: aCount(0),
	  bCount(0),
	  cCount(0),
	  dCount(0),
	  fCount(0)
{
	setCourseName(name);
}

void GradeBook::setCourseName(string name)
{
	if (name.size() <= 25)
	{
		courseName = name;
	}
	else
	{
		courseName = name.substr(0, 25);
		cerr << "Name \"" << name << "\" exceeded maximum length (25). \n"
			<< "Limiting courseName to first 25 characters.\n" << endl;
	}
}

string GradeBook::getCourseName() const
{
	return courseName;
}

void GradeBook::displayMessage() const
{
	cout << "Welcome to the grade book for " << getCourseName() << "!\n" << endl;
}

void GradeBook::inputGrades()
{
	int grade;

	cout << "Enter the letter grades." << endl
		<< "Enter the EOF character to end input." << endl;

	while ((grade = cin.get()) != EOF)
	{
		switch (grade)
		{
			case 'A':
			case 'a':
				++aCount;
				break;

			case 'B':
			case 'b':
				++bCount;
				break;

			case 'C':
			case 'c':
				++cCount;
				break;

			case 'D':
			case 'd':
				++dCount;
				break;

			case 'F':
			case 'f':
				++fCount;
				break;

			case '\n':
			case '\t':
			case ' ':
				break;

			default:
				cout << "Incorect letter grade entered."
					<< " Enter a new grade." << endl;
				break;
		}
	}
}

void GradeBook::displayGradeReport() const
{
	cout << "\n\nNumber of students who received each letter grade:"
		<< "\nA: " << aCount
		<< "\nB: " << bCount
		<< "\nC: " << cCount
		<< "\nD: " << dCount
		<< "\nF: " << fCount
		<< endl;
}

//void GradeBook::determineClassAverage() const
//{
//	int total = 0;
//	unsigned int gradeCounter = 0;
//
//	cout << "Enter grade or -1 to quit: ";
//	int grade = 0;
//	cin >> grade;
//
//	while (grade != -1)
//	{
//		total = total + grade;
//		gradeCounter = gradeCounter + 1;
//
//		cout << "Enter grade or -1 to quite: ";
//		cin >> grade;
//	}
//
//	if (gradeCounter != 0)
//	{
//		double avarage = static_cast<double>(total) / gradeCounter;
//
//		cout << "\nTotal of all " << gradeCounter << " grades entered is " << total << endl;
//		cout << setprecision(2) << fixed;
//		cout << "Class average is " << avarage << endl;
//	}
//	else
//		cerr << "No grades where entered" << endl;	
//}
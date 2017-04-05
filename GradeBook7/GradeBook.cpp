#include <iostream>
#include <iomanip>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook(const string& name, std::array<std::array<int, tests>, students>& gradesArray)
	: courseName(name), grades(gradesArray)
{

}

void GradeBook::setCourseName(const string& name)
{
	courseName = name;
}

string GradeBook::getCourseName() const
{
	return courseName;
}

void GradeBook::displayMessage() const
{
	cout << "Welcome to the grade book for \"" << getCourseName << "\"!" << endl;
}

void GradeBook::processGrades() const
{
	outputGrades();

	cout << "\nLowest grade in the grade book is " << getMinimum()
		<< "\nHighest grade in the grade book is " << getMaximum() << endl;

	outputBarChart();
}

int GradeBook::getMinimum() const
{
	int lowGrade = 100;

	for (auto const &student : grades)
	{
		for (auto const &grade : student)
		{
			if (lowGrade > grade)
			{
				lowGrade = grade;
			}
		}
	}

	return lowGrade;
}

int GradeBook::getMaximum() const
{
	int highGrade = 0;

	for (auto const &student : grades)
	{
		for (auto const &grade : student)
		{
			if (highGrade < grade)
			{
				highGrade = grade;
			}
		}
	}

	return highGrade;
}

double GradeBook::getAverage(const array<int, tests> &setOfGrades) const
{
	int total = 0;

	for (int grade : setOfGrades)
	{
		total += grade;
	}

	return static_cast<double>(total) / setOfGrades.size();
}

void GradeBook::outputBarChart() const
{
	cout << "\nOverall grade distribution:" << endl;

	const size_t frequecySize = 11;
	array<unsigned int, frequecySize> frequency = {};

	for (auto const &student : grades)
	{
		for (auto const &grade : student)
		{
			++frequency[grade / 10];
		}
	}

	for (size_t count = 0; count < frequecySize; count++)
	{
		if (0 == count)
		{
			cout << "  0-9: ";
		}
		else if (10 == count)
		{
			cout << "  100: ";
		}
		else
		{
			cout << count * 10 << "-" << (count * 10) + 9 << ": ";
		}

		for (unsigned int stars = 0; stars < frequency[count]; ++stars)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void GradeBook::outputGrades() const
{
	cout << "\nThe grades are:\n\n";

	cout << setw(12) << "";
	for (size_t test = 0; test < tests; ++test)
	{
		cout << "Test " << test + 1 << " ";
	}
	cout << "Average" << endl;

	for (size_t student = 0; student < grades.size(); student++)
	{
		cout << "Student " << setw(2) << student + 1;

		for (size_t test = 0; test < grades[student].size(); test++)
		{
			cout << setw(8) << grades[student][test];

			double average = getAverage(grades[student]);

			cout << setw(9) << setprecision(2) << fixed << average << endl;
		}
	}
}
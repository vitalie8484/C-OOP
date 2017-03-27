// GradeBookApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GradeBook.h"


int main()
{
	GradeBook myGradeBook("C++ Programming");

	myGradeBook.displayMessage();
	myGradeBook.inputGrades();
	myGradeBook.displayGradeReport();
}


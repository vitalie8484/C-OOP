// GradeBookApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GradeBook.h"


int main()
{
	GradeBook myGradeBook("C++ Programing Language");

	myGradeBook.displayMessage();
	myGradeBook.determineClassAverage();
}


// GradeBookApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GradeBook.h"


int main()
{
	GradeBook myGradeBook("C++ Programing");

	myGradeBook.displayMessage();
	myGradeBook.determineClassAverage();
}


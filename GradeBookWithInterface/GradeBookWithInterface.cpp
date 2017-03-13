// GradeBookWithInterface.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GradeBook.h"

int main()
{
	GradeBook book1("Biologia");
	GradeBook book2("Fizica");

	book1.displayMessage(); 
	book2.displayMessage();
}

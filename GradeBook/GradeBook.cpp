// GradeBook.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GradeBook.h"

using namespace std;

int main()
{
	GradeBook book1("Book 1");
	GradeBook book2("Book 2");

	book1.displayMessage();
	book2.displayMessage();
    return 0;
}


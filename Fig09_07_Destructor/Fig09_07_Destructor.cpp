#include <iostream>
#include "CreateAndDestroy.h"
using namespace std;

void create(void);

CreateAndDetroy first(1, "(global before main)");

int main()
{
	cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
	static CreateAndDetroy second(2, "(local static in main)");

	create();

	cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;
	CreateAndDetroy fourth(4, "(local automatic in main)");

	cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;

    return 0;
}

void create()
{
	cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
	CreateAndDetroy fifth(5, "(local automatic in create)");
	static CreateAndDetroy sixth(6, "(local static in create)");
	CreateAndDetroy seventh(7, "(local automatic in create)");
	cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
}


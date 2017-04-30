#include <iostream>
#include "CreateAndDestroy.h"
using namespace std;

CreateAndDetroy::CreateAndDetroy(int ID, string messageString)
	: objectID(ID), message(messageString)
{
	cout << "Object " << objectID << " constructors runs " << message << endl;
}

CreateAndDetroy::~CreateAndDetroy()
{
	cout << (objectID == 1 || objectID == 6 ? "\n" : "");
	cout << "Object " << objectID << " destructors runs " << message << endl;
}
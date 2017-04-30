#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList* myList = new LinkedList(1);
	cout << *myList;
	cout << myList->getSize() << endl;

	myList->add(2);
	cout << *myList;
	cout << myList->getSize() << endl;

	myList->addAt(0, 0);
	myList->addAt(4, 3);
	myList->addAt(3, 3);
	cout << *myList;
	cout << myList->getSize() << endl;

	myList->addAt(200, 2);
	cout << *myList;
	cout << myList->getSize() << endl;

	myList->remove(3);
	cout << *myList;
	cout << myList->getSize() << endl;

	cout << "GET function:" << endl;
	cout << myList->get(0) << " " << myList->get(2) << " " << myList->get(4) << endl;

	cout << "indexOf function:" << endl;
	cout << myList->indexOf(200) << " " << myList->indexOf(3) << " " << myList->indexOf(4) << endl;

	myList->clear();
	cout << *myList;
	cout << myList->getSize() << endl;

	try
	{
		myList->addAt(200, 0);
		cout << *myList;
		cout << myList->getSize() << endl;
	}
	catch (out_of_range& ex)
	{
		cout << "ERROR: " << ex.what() << endl;
	}
	

	delete myList;

	return 0;
}
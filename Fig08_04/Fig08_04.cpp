#include <iostream>
using namespace std;

int main()
{
	int a = 7;
	int* aPtr = &a;

	cout << "The address of a is " << &a << endl;
	cout << "The value of aPtr is " << aPtr << endl;
	cout << "The value of a is " << a << endl;
	cout << "The value of *aPtr is " << *aPtr << endl;

    return 0;
}


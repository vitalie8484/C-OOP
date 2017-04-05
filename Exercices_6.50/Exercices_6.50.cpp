#include <iostream>
using namespace std;

int tripleByValue(int);
void tripleByReference(int &);

int main()
{
	int count = 0;

	cout << "Enter a number : " << endl;
	cin >> count;
	cout << "The triple by value of " << count << " is " << tripleByValue(count) << endl;
	tripleByReference(count);
	cout << "The triple by reference function changed the original value to " << count << endl;

    return 0;
}

int tripleByValue(int a)
{
	return a * 3;
}

void tripleByReference(int& b)
{
	b *= 3;
}


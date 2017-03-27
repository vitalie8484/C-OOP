#include <iostream>
using namespace std;

int number = 7;

int main()
{
	double number = 10.5;

	cout << "Local variable: " << number << endl;
	cout << "Global variable: " << ::number << endl;

    return 0;
}


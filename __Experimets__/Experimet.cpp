#include <iostream>
#include <climits>

using namespace std;

int main()
{
	bool b = false;
	int n = 0;

	if (n == 0) b = true; else b = false;
	cout << b << endl;

	b = !n;
	cout << b << endl;
}
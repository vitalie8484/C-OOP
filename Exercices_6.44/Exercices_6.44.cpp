#include <iostream>
using namespace std;

int mystery(int, int);

int main()
{
	int x = 0;
	int y = 0;

	cout << "Enter two integers: ";
	cin >> x >> y;
	cout << "The result is " << mystery(x, y) << endl;

    return 0;
}

int mystery(int a, int b)
{
	if (1 == b)
	{
		return a;
	}
	else
	{
		return a + mystery(a, b - 1);
	}
}


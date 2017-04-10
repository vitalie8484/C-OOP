#include <iostream>
#include <string>
using namespace std;

void stringReverse(string const &, int);

int main()
{
	stringReverse("123456789", 0);
    return 0;
}

void stringReverse(string const & str, int index)
{
	if (index == str.size() - 1)
	{
		cout << str[index];
	}
	else
	{
		stringReverse(str, index + 1);
		cout << str[index];
	}
}

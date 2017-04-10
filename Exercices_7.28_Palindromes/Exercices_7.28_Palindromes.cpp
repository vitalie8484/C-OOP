#include <iostream>
#include <string>
using namespace std;

bool testPalindrome(string, int);

int main()
{
	string s = "able was i ere i saw elba";
	cout << boolalpha << testPalindrome(s, 0) << endl;
    return 0;
}

bool testPalindrome(string str, int pos)
{
	if (pos == str.size() / 2)
	{
		if (str.size() % 2 == 1)
		{
			return true;
		}
		else
		{
			return str[pos] == str[str.size() - pos];
		}
	}
	else
	{
		return (str[pos] == str[str.size() - pos - 1]) && testPalindrome(str, pos + 1);
	}
}




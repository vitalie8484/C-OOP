#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

map<int, string, greater<int>> values;

string toRoman(int);

int main()
{ 
	values.insert(make_pair(1000, "M"));
	values.insert(make_pair(900, "CM"));
	values.insert(make_pair(500, "D"));
	values.insert(make_pair(400, "CD"));
	values.insert(make_pair(100, "C"));
	values.insert(make_pair(90, "XC"));
	values.insert(make_pair(50, "L"));
	values.insert(make_pair(40, "XL"));
	values.insert(make_pair(10, "X"));
	values.insert(make_pair(9, "IX"));
	values.insert(make_pair(5, "V"));
	values.insert(make_pair(4, "IV"));
	values.insert(make_pair(1, "I"));

	int i = 0;

	cout << "Entrer un nombre: (ou EOF pour terminer)" << endl;
	cin >> i;

	while (i != EOF)
	{
		cout << "Entrer un nombre: (ou EOF pour terminer)" << endl;
		cin >> i;
		cout << i << " -> " << toRoman(i) << endl;
	}

    return 0;
}

string toRoman(int number) 
{
	map<int, string>::iterator it = values.begin();

	while (it != values.end())
	{
		int key = it->first;
		string value = it->second;

		if (number >= key)
		{
			if (number == key)
			{
				return value;
			}
			else
			{
				return value + toRoman(number - key);
			}
		}
		it++;
	}
}


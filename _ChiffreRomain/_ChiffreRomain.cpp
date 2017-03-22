#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i = 1;
	while (i > 0)
	{
		string rez = "";
		cout << "Entrer un nombre (0 - 2500) ou un nombre negatif pour ferme l'application: " << endl;
		cin >> i;
	
		int decimal = i;

		if (decimal >= 1000)
		{
			while (decimal >= 1000)
			{
				rez = rez + "M";
				decimal -= 1000;
			}
		} 

		if (decimal >= 900)
		{
			rez = rez + "CM";
			decimal -= 900;
		} 
		else if (decimal >= 500)
		{
			rez = rez + "D";
			decimal -= 500;
			while (decimal >= 100)
			{
				rez = rez + "C";
				decimal -= 100;
			}
		}
		else if (decimal >= 400)
		{
			rez = rez + "CD";
			decimal -= 400;
		}
		else if (decimal >= 100)
		{
			while (decimal >= 100)
			{
				rez = rez + "C";
				decimal -= 100;
			}
		}

		if (decimal >= 90)
		{
			rez = rez + "XC";
			decimal -= 90;
		}
		else if (decimal >= 50)
		{
			rez = rez + "L";
			decimal -= 50;
			while (decimal >= 10)
			{
				rez = rez + "X";
				decimal -= 10;
			}
		}
		else if (decimal >= 40)
		{
			rez = rez + "XL";
			decimal -= 40;
		}
		else if (decimal >= 10)
		{
			while (decimal >= 10)
			{
				rez = rez + "X";
				decimal -= 10;
			}
		}

		if (decimal >= 9)
		{
			rez = rez + "IX";
			decimal -= 9;
		}
		else if (decimal >= 5)
		{
			rez = rez + "V";
			decimal -= 5;
			while (decimal >= 1)
			{
				rez = rez + "I";
				decimal -= 1;
			}
		}
		else if (decimal >= 4)
		{
			rez = rez + "IV";
			decimal -= 4;
		}
		else if (decimal >= 1)
		{
			while (decimal >= 1)
			{
				rez = rez + "I";
				decimal -= 1;
			}
		}

		cout << rez << endl;
	}
	
    return 0;
}


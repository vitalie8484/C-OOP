#include <iostream>
#include <string>

using namespace std;

string getTextFromConsole() {
	string text = "";
	do {
		getline(cin, text);
	} while (text == "");
	return text;
}

int main()
{
	double temperature = 0;
	string unite = "";

	cout << "Rentrer une temperature (nombre entier):\n";
	cin >> temperature;

	cout << "Rentrer une unite de mesure (C ou F):\n";
	do
	{
		unite = getTextFromConsole();
		if (unite == "F" || unite == "C")
		{
			break;
		} 
		else 
		{
			cout << "Rentrer une unite de mesure correct (C ou F):\n";
		}
	} while (true);
	
	if (unite == "F")
	{
		cout << temperature << " F = " << ((temperature - 32)/1.8) << " C" << endl;
	}
	else
	{
		cout << temperature << " C = " << ((temperature * 1.8) + 32) << " F" << endl;
	}


    return 0;
}


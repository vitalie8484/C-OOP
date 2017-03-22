#include <iostream>

using namespace std;

int main()
{
	int moyenne = 0;
	cout << "Rentrer la moyenne (0 - 100):\n";
	while (true)
	{
		cin >> moyenne;
		if ((moyenne >= 0) && (moyenne <= 100))
		{
			break;
		}
		cout << "Rentrer un entiere valide. Rentrer la moyenne (0 - 100):\n";
	}
	
	char note = 'E';
	if (moyenne >= 91)
	{
		note = 'A';
	}
	else if (moyenne >= 75)
	{
		note = 'B';
	}
	else if (moyenne >= 65)
	{
		note = 'C';
	}
	else if (moyenne >= 60)
	{
		note = 'D';
	}
	 
	cout << "La note finale de l'etudiant est: " << note << endl;

    return 0;
}


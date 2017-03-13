// Exercices_Repetition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int nr = 0;
	unsigned int contor = 1;
	int total = 0;

	cout << "Entrez le nombre des etudients: " << endl;
	cin >> nr;

	cout << "Entrez les notes pour chaque etudiant: " << endl;
	while (contor <= nr)
	{
		cout << "La note pour l'etudiant numero " << contor << " est:";
		int note = 0;
		cin >> note;
		total = total + note;
		contor = contor + 1;
	}

	cout << endl;

	int med = total / nr;
	cout << "Le total des tous " << nr << " notes est " << total << endl;
	cout << "La moyenne de clase est " << med << endl;

    return 0;
}


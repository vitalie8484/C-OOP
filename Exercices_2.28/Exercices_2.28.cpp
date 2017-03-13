// Exercices_2.28.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::getline;


int main()
{
	cout << "Inserer un nombre entier qui conntien cinque ciffre:";

	string s = "";
	getline(cin, s);

	int length = 5;
	while (s.length() != length)
	{
		cout << "Le nombre \"" << s << "\" ne contien pas cinque ciffre!! Esseye ancore une fois:";
		getline(cin, s);
	}

	int n = atoi(s.c_str());

	int d = 0;
	do {
		d = n % 10;
		n = n / 10;
		cout << d << "   ";
	} while (n != 0);

    return 0;
}


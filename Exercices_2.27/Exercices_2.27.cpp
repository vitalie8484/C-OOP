// Exercices_2.27.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char c = ' ';
	cin >> c;

	while (c != 'q') {
		cout << c << " = " << static_cast<int>(c) << endl;
		cin >> c;
	}
    return 0;
}


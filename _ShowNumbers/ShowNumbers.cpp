// ShowNumbers.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int i = 0;
	while (i < 10000)
	{
		if (i % 2 == 0)
		{
			cout << i << "\n";
		}
		i++;
	}
    return 0;
}


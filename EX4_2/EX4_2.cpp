#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "L'equivalent int (entier) des caracteres suivants : A, Z, b, f, 0, 1, 9, * et /:" << endl;
	cout << "[A] = " << static_cast<int>('A') << endl;
	cout << "[Z] = " << static_cast<int>('Z') << endl;
	cout << "[b] = " << static_cast<int>('b') << endl;
	cout << "[f] = " << static_cast<int>('f') << endl;
	cout << "[0] = " << static_cast<int>('0') << endl;
	cout << "[1] = " << static_cast<int>('1') << endl;
	cout << "[9] = " << static_cast<int>('9') << endl;
	cout << "[*] = " << static_cast<int>('*') << endl;
	cout << "[/] = " << static_cast<int>('/') << endl;

    return 0;
}


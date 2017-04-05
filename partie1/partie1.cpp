#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
using namespace std;

array<char, 9> table = {};
unsigned int steps = 0;
default_random_engine engine(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> guessPlayer(1, 2);
uniform_int_distribution<unsigned int> guessNumber(1, 9);

void game();
void iniTable();
bool findInTable(int);
void replaceInTable(int, char);
void show();
int getRandomNumberForPC();
char gameFinished();

int main()
{
	cout << "GAME - Tic Tac Toe" << endl;
	char yes = 'y';

	while (yes == 'y')
	{
		game();
		cout << "-----------------------------------------------------------------------------"
			<< endl
			<< "Do you want to play one more time? Press y"
			<< endl;
		cin.ignore();
		yes = cin.get();
	}

	cout << "Goodbye!" << endl;

	return 0;
}

void game()
{
	char me = 'X';
	char pc = 'O';
	bool myStep = false;
	unsigned int number = 0;

	iniTable();
	show();

	if (guessPlayer(engine) == 1)
	{
		me = 'X';
		pc = 'O';
		myStep = true;
		cout << "Player 1 is you." << endl << "You - X" << endl << "PC - O" << endl;
	}
	else
	{
		me = 'O';
		pc = 'X';
		cout << "Player 1 is the PC." << endl << "PC - X" << endl << "You - O" << endl;
	}

	while (gameFinished() == '-')
	{
		if (myStep)
		{
			cout << "You need to insert a number: ";
			cin >> number;
			while (!findInTable(number))
			{
				cout << "You inserted a wrong number. Try one more time: ";
				cin >> number;
			}
		}
		else
		{
			number = getRandomNumberForPC();
			cout << "The PC selected number: " << number << endl;
		}

		replaceInTable(number, myStep ? me : pc);
		show();
		myStep = !myStep;
	}

	switch (gameFinished())
	{
	case '+':
		cout << "Nobody won :(" << endl;
		break;
	case 'X':
		cout << (me == 'X' ? "You won. Congratulation :) " : "PC won.") << endl;
		break;
	case 'O':
		cout << (me == 'O' ? "You won. Congratulation :) " : "PC won.") << endl;
		break;
	default:
		break;
	}
}

void iniTable()
{
	for (unsigned int count = 0; count < table.size(); count++)
	{
		table[count] = '1' + count;
	}
	steps = 0;
}

bool findInTable(int i)
{
	bool exists = find(begin(table), end(table), '0' + i) != end(table);
	return exists;
}

void replaceInTable(int i, char c)
{
	table[i - 1] = c;
	++steps;
}

void show()
{
	for (unsigned int position = 1; position <= table.size(); position++)
	{
		cout << ((position % 3 == 2) ? " | " : "") << table[position - 1] << ((position % 3 == 2) ? " | " : "");
		if ((3 == position) || (6 == position))
		{
			cout << "\n- + - + -\n";
		}
	}
	cout << endl;
}

int getRandomNumberForPC()
{
	int number = 0;
	while (!findInTable(number))
	{
		number = guessNumber(engine);
	}
	return number;
}

char gameFinished()
{
	if (steps == 9)
	{
		return '+';
	}
	else if (table[0] == table[1] && table[1] == table[2])
	{
		return table[0];
	}
	else if (table[3] == table[4] && table[4] == table[5])
	{
		return table[3];
	}
	else if (table[6] == table[7] && table[7] == table[8])
	{
		return table[6];
	}
	else if (table[0] == table[3] && table[3] == table[6])
	{
		return table[0];
	}
	else if (table[1] == table[4] && table[4] == table[7])
	{
		return table[1];
	}
	else if (table[2] == table[5] && table[5] == table[8])
	{
		return table[2];
	}
	else if (table[6] == table[4] && table[4] == table[2])
	{
		return table[6];
	}
	else if (table[0] == table[4] && table[4] == table[8])
	{
		return table[0];
	}
	else
	{
		return '-';
	}
}

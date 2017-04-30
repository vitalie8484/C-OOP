#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void moveTortoise(unsigned int* const);
void moveHare(unsigned int* const);
void display(const unsigned int* const, const unsigned int* const);

default_random_engine engine(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> randInt(1, 10);

int main()
{
	unsigned int positionTortoise = 1;
	unsigned int positionHare = 1;

	cout << "BANG !!!!!" << endl;
	cout << "AND THEY'RE OFF !!!!!" << endl;

	while ((positionTortoise <= 70) && (positionHare <= 70))
	{
		moveTortoise(&positionTortoise);
		moveHare(&positionHare);

		display(&positionTortoise, &positionHare);
	}

	if (positionHare == positionTortoise)
	{
		cout << "\nIt's a tie" << endl;
	}
	else if (positionHare > positionTortoise)
	{
		cout << "\nHare wins" << endl;
	}
	else
	{
		cout << "\nTORTOISE WINS!!! YAY!!!" << endl;
	}

    return 0;
}

void display(const unsigned int* const posTortoise, const unsigned int* const posHare)
{
	for (unsigned int i = 0; i < 90; ++i)
	{
		if ((*posTortoise == *posHare) && (*posHare == i))
		{
			cout << "OUTCH!!!";
		}
		else if ((*posTortoise == i) || (*posHare == i))
		{
			cout << (*posTortoise == i ? "T" : "H");
		}
		else
		{
			cout << (i <= 70 ? " " : "");
		}
	}
	cout << endl;
}

void moveTortoise(unsigned int* const position)
{
	unsigned int i = randInt(engine);
	switch (i)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		*position += 3;
		break;
	case 6:
	case 7:
		if (*position <= 6)
		{
			*position = 1;
		}
		else
		{
			*position -= 6;
		}
		break;
	case 8:
	case 9:
	case 10:
		++(*position);
		break;
	default:
		cout << "Unreachable statement" << endl;
		break;
	}
}

void moveHare(unsigned int* const position)
{
	unsigned int i = randInt(engine);
	switch (i)
	{
	case 1:
	case 2:
		break;
	case 3:
	case 4:
		*position += 9;
		break;
	case 5:
		if (*position <= 12)
		{
			*position = 1;
		}
		else
		{
			*position -= 12;
		}
		break;
	case 6:
	case 7:
	case 8:
		++(*position);
		break;
	case 9:
	case 10:
		if (*position <= 2)
		{
			*position = 1;
		}
		else
		{
			*position -= 2;
		}
		break;
	default:
		cout << "Unreachable statement" << endl;
		break;
	}
}

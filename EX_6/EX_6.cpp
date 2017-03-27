#include <iostream>
#include <string>
using namespace std;

int main()
{
	string phrase = "";
	cout << "Entrer une phrase:" << endl;
	getline(cin, phrase);

	unsigned int voyelles = 0;

	for (unsigned int i = 0; i < phrase.length(); i++)
	{
		char c = phrase.at(i);
		switch (c)
		{
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'U':
		case 'u':
		case 'I':
		case 'i':
		case 'O':
		case 'o':
		case 'Y':
		case 'y':
			++voyelles;
		}
	}

	cout << "Le nombre de voyelles dans la phrase: " << voyelles << endl;
    return 0;
}
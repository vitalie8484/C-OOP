#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

int main()
{
	const size_t responseSize = 20;
	const size_t frequencySize = 6;

	const array<unsigned int, responseSize> responses = 
	{ 1, 2, 5, 4, 3, 5, 2, 1, 3, 1, 4, 3, 3, 3, 2, 3, 3, 2, 2, 5 };

	array<unsigned int, frequencySize> frequency = {};

	for (size_t answer = 0; answer < responses.size(); ++answer)
	{
		++frequency[responses[answer]];
	}

	cout << "Rating" << setw(15) << "Frequency" << endl;

	for (size_t i = 1; i < frequency.size(); ++i)
	{
		cout << setw(6) << i << setw(15) << frequency[i] << endl;
	}

    return 0;
}
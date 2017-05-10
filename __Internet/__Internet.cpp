#include <iostream>
#include <cstdlib>
using namespace std;

void

class aaa
{
public:
	aaa() { cout << "CTOR, "; }
	~aaa() { cout << "XXXX"; }
};

int main()
{
	for (size_t i = 1; i <= 2; i++)
	{
		aaa bc;
	}

	return 0;
}
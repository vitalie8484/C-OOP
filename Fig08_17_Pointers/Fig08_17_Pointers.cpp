#include <iostream>
using namespace std;

int main()
{
	int b[] = { 10, 20, 30, 40 };
	int *bPtr = b;
	cout << "Array b displayed with" << endl;

	cout << " -> Array subscript notation:" << endl;
	for (size_t i = 0; i < 4; ++i)
	{
		cout << "b[" << i << "] = " << b[i] << endl;
	}

	cout << " -> Pointer/offset notation where the pointer is the array name:" << endl;
	for (size_t offset1 = 0; offset1 < 4; ++offset1)
	{
		cout << "*(b + " << offset1 << ") = " << *(b + offset1) << endl;
	}

	cout << " -> Pointer subscript notation:" << endl;
	for (size_t j = 0; j < 4; ++j)
	{
		cout << "bPtr[" << j << "] = " << bPtr[j] << endl;
	}

	cout << " -> Pointer/offset notation:" << endl;
	for (size_t offset2 = 0; offset2 < 4; offset2++)
	{
		cout << "*(bPtr + " << offset2 << ") = " << *(bPtr + offset2) << endl;
	}

    return 0;
}

 
#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	size = 0;

	root = nullptr;
	conductor = nullptr;
}

LinkedList::LinkedList(int value)
{
	size = 1;

	root = new node;
	root->next = 0;
	root->val = value;
	conductor = root;
}

LinkedList::~LinkedList()
{
	cout << "------DESTROY LinkedList------" << endl;
	clear();
}

void LinkedList::add(const int value)
{
	conductor = root;
	if (conductor != 0 && size > 0)
	{
		while (conductor->next != 0)
		{
			conductor = conductor->next;
		}

		conductor->next = new node;
		conductor = conductor->next;
		conductor->next = 0;
		conductor->val = value;
	}
	else
	{
		root = new node;
		root->next = 0;
		root->val = value;

		conductor = root;
	}

	++size;
}

void LinkedList::addAt(const int value, const int index)
{
	if (index < 0 || index > size)
	{
		throw out_of_range("Index out of range!!!");
	}

	conductor = root;

	if (size == 0 || index == size)
	{
		add(value);
	}
	else
	{
		node* newNode = new node;
		newNode->val = value;

		if (index == 0)
		{
			newNode->next = root;
			root = newNode;
		}
		else
		{
			rsize_t i = 0;
			while (i < (index - 1))
			{
				conductor = conductor->next;
				++i;
			}
			newNode->next = conductor->next;
			conductor->next = newNode;
		}

		conductor = root;
		++size;
	}
}

void LinkedList::remove(const int index)
{
	if (index < 0 || index > size)
	{
		throw out_of_range("Index out of range!!!");
	}

	conductor = root;

	node* deleteNode;
	if (index == 0)
	{
		deleteNode = root;
		root = deleteNode->next;
		delete deleteNode;

	}
	else if (index == size)
	{
		while (conductor->next != 0)
		{
			conductor = conductor->next;
		}
		deleteNode = conductor;
		conductor = root;
		delete deleteNode;
	}
	else
	{
		rsize_t i = 0;
		while (i < index - 1)
		{
			conductor = conductor->next;
			++i;
		}
		deleteNode = conductor->next;
		conductor->next = deleteNode->next;
		delete deleteNode;
	}

	--size;
	if (size == 0)
	{
		root = nullptr;
		conductor = nullptr;
	}
}

void LinkedList::clear()
{
	conductor = root;
	if (conductor != 0 && size > 0)
	{
		cout << "------DELETE all LinkedList nodes------" << endl;
		rsize_t initSize = size;
		while (conductor->next != 0)
		{
			root = conductor;
			conductor = conductor->next;
			cout << "DELETE node[" << initSize - size << "] = " << root->val << endl;
			delete root;
			--size;
		}
		cout << "DELETE node[" << initSize - size << "] = " << conductor->val << endl;
		delete conductor;
		--size;
	}
	root = nullptr;
	conductor = nullptr;
}

int LinkedList::get(const int index)
{
	if (index < 0 || index > size)
	{
		throw out_of_range("Index out of range!!!");
	}

	conductor = root;

	if (index == 0)
	{
		return conductor->val;

	}
	else if (index == size)
	{
		while (conductor->next != 0)
		{
			conductor = conductor->next;
		}
		return conductor->val;
	}
	else
	{
		rsize_t i = 0;
		while (i < index)
		{
			conductor = conductor->next;
			++i;
		}
	}
	return conductor->val;
}

int LinkedList::indexOf(const int value)
{
	int rez = 0;
	rsize_t index = 0;
	if (size == 0)
	{
		throw out_of_range("The LinkedList is empty");
	}
	else
	{
		conductor = root;
		rez = conductor->val;
		if (rez == value)
		{
			return index;
		}
		else
		{
			while (conductor->next != 0)
			{
				++index;
				conductor = conductor->next;
				rez = conductor->val;
				if (rez == value)
				{
					return index;
				}
			}
		}
	}
	throw out_of_range("This value doesn't exist in LinkedList");
}

size_t LinkedList::getSize() const
{
	return size;
}

ostream& operator<<(ostream& output, LinkedList& list)
{
	size_t i = 0;
	list.conductor = list.root;
	if (list.conductor != 0 && list.size > 0)
	{
		output << "------LinkedList nodes------" << endl;
		output << "node[" << i << "] = " << list.conductor->val << endl;

		while (list.conductor->next != 0)
		{
			++i;
			list.conductor = list.conductor->next;
			output << "node[" << i << "] = " << list.conductor->val << endl;
		}
	}
	else
	{
		output << "------This LinkedList doesn't have any nodes------" << endl;
	}

	return output;
}
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList
{
	struct node
	{
		int val;
		node* next;
	};

	friend std::ostream& operator<<(std::ostream &, LinkedList &);

public:
	LinkedList();
	LinkedList(int);
	~LinkedList();

	void add(const int);
	void addAt(const int, const int);
	void remove(const int);
	void clear();
	int get(const int index);
	int indexOf(const int);
	size_t getSize() const;

private:
	size_t size;
	node* root;
	node* conductor;
};

#endif // !LINKED_LIST_H
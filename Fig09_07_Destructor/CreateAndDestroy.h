#include <string>

#ifndef CREATE_H
#define CREATE_H

class CreateAndDetroy
{
public:
	CreateAndDetroy(int, std::string);
	~CreateAndDetroy();

private:
	int objectID;
	std::string message;
};

#endif // !CREATE_H

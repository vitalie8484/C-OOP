#pragma once

#include <iostream>
#include <string>

class GradeBook
{
public:
	explicit GradeBook(std::string name) : courseName(name)
	{

	}

	void setCourseName(std::string name)
	{
		courseName = name;
	}

	std::string getCourseName() const
	{
		return courseName;
	}

	void displayMessage() const
	{
		std::cout << "The message is : " << getCourseName() << std::endl;
	}

private:
	std::string courseName;
};
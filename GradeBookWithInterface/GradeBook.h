#pragma once
#include <string>

class GradeBook
{
public:
	explicit GradeBook(std::string);
	void setGradeBook(std::string);
	std::string getGradeBook() const;
	void displayMessage() const;

private:
	std::string courseName;
};
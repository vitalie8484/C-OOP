#pragma once
#include <string>

class GradeBook
{
public:
	explicit GradeBook(std::string);
	void setCourseName(std::string);
	std::string getCourseName() const;
	void displayMessage() const;
	void inputGrades();
	void displayGradeReport() const;
	int maximum(int, int, int) const;
private:
	std::string courseName;
	int maximumGrade;
};
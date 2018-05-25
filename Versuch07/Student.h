#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
class Student
{
public:
	Student();
	Student(unsigned int matNr, std::string name, std::string dateOfBirth,
			std::string address);
	unsigned int getMatNr();
	std::string getName();
	std::string getDateOfBirth();
	std::string getAddress();

	/*
	 *  Operator Overloading, using const functions as Templates are defind as const
	 */
	bool operator == (const Student student) const;
	bool operator > (const Student student) const;
	bool operator < (const Student student) const;
	std::ostream& print(std::ostream& out) const;

private:
	unsigned int matNr;
	std::string name;
	std::string dateOfBirth;
	std::string address;
};

std::ostream& operator << (std::ostream& out, const Student& stud);

#endif

#include <iostream>
#include "Student.h"

Student::Student(unsigned int matNr, std::string name, std::string dateOfBirth,
		std::string address) :
		matNr(matNr), name(name), dateOfBirth(dateOfBirth), address(address)
{
}

Student::Student() :
		matNr(0), name(""), dateOfBirth(""), address("")
{
}

unsigned int Student::getMatNr()
{
	return this->matNr;
}

std::string Student::getName()
{
	return this->name;
}

std::string Student::getDateOfBirth()
{
	return this->dateOfBirth;
}

std::string Student::getAddress()
{
	return this->address;
}
/**
 * @brief Prints Student Information
 *
 *		This function together with the overloaded "<<" operator function allows to  print instances of the Student
 *		class directly with std::cout commands. The data is handeled primaraly by the "<<" operator function, whereas
 *		this function brings the information into a readable format.
 *
 * @param  std::ostream& out The ostream parameter for the std::cout function
 * @return std::ostream& out Formatted student information encoded
 */
std::ostream& Student::print(std::ostream& out) const
{
	return out << name << ", MatNr. " << matNr
				<< " geb. am " << dateOfBirth << " wohnhaft in "
				<< address << std::endl;
}

/**
 * @brief Overloaded ostream operator
 *
 *		This function provides and overloaded definition of the "<<" operator of the std::ostream. This allows
 *		to print Student type instances directly with std::cout commands, otherwise implementations such as the ones
 *		in Versuch 5-6 are needed.
 *
 *		Extra:
 *		ATTENTION! This function has to be defined outside the Student Class, as it has to be accessed
 *		externally by ostream and std operator handlers. You can find the definition of this function in the Student.h
 *		header filed just outside the Student Class definition. I would like to stress on it again for the reader:
 *		without proper initialization or definition your program will NOT compile, as you will get "no match for operand
 *		std::cout<<" errors. I know for myself, as I have spent hours debugging this issue. So please make sure it is not
 *		only present here, but also outside the Student Class definition in the header file mentioned above.
 *
 * @param  std::ostream& out the ostream std::cout variable
 * @param  Student& student The student to be printed out
 * @return call print function to print studen information in a formatted manner
 */
std::ostream& operator << (std::ostream& out, const Student& student)
{
	return student.print(out);
}

/**
 * @brief Overloaded Equivalence operator
 *
 * 		This overloaded operator serves the same binary function as "==" in C++.
 * 		The two students are equivalent if, and only if, their MatNrs are the same.
 *
 * @param  Student student The student to be compared with
 * @return bool True if equivalent, False otherwise
 */
bool Student::operator ==(const Student student) const
{
	if (matNr == student.matNr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief Overloaded 'Greater than' operator
 *
 * 		This overloaded operator serves the same binary function as ">" in C++.
 * 		One student is "greater" than the other if his/her MatNr is greater than
 * 		that of the student given as a parameter.
 * 		For example, let Student u.matNr = 1000 and Student v.matNr = 2000. Then
 * 		u > v ----> False
 * 		v > u ----> True
 *
 * @param  Student student The student to be compared with the first operand
 * @return bool True if first Operand > second Operand, False otherwise
 */
bool Student::operator >(const Student student) const
{
	if (matNr > student.matNr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief Overloaded 'Less than' operator
 *
 * 		This overloaded operator serves the same binary function as "<" in C++.
 * 		One student is "less" than the other if his/her MatNr is less than
 * 		that of the student given as a parameter.
 * 		For example, let Student u.matNr = 1000 and Student v.matNr = 2000. Then
 * 		u < v ----> True
 * 		v < u ----> False
 *
 * @param  Student student The student to be compared with the first operand
 * @return bool True if first Operand < second Operand, False otherwise
 */
bool Student::operator <(const Student student) const
{
	if (matNr < student.matNr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

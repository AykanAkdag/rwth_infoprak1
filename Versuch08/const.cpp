/**
 * @file
 *
 * @brief Contains the method declarations used in the Const Class
 *
 */
#include <iostream>
#include "const.h"

/**
 * @brief Constuctor method for Const Class
 *
 * 		This constructor initializes a Const class instance with an integer
 * 		value given to it that is then saved in it's private variable "value".
 *
 * @param initval The value with which it initializes
 */
Const::Const(double initval)
{
	value = initval;
}
/**
 * @brief Destructor method for Const Class
 */
Const::~Const()
{
}

/**
 * @brief Polymorphous Evaluate method for Const Class
 *
 * @return double Result of this expression
 */
double Const::evaluate() const
{
	return value;
}

/**
 * @brief Polymorphous Print method for Const Class
 *
 */
void Const::print() const
{
	std::cout << value;
}





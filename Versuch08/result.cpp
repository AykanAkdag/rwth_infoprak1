/**
 * @file
 *
 * @brief Contains the method declarations used in the Result Class
 *
 */

#include <iostream>
#include "result.h"

/**
 * @brief Constuctor for Result Class
 */
Result::Result(Expression* currexpr)
{
	expr = currexpr;
}

/**
 * @brief Destructor for Result Class
 */
Result::~Result()
{
	delete expr;
}

/**
 * @brief Polymorphous evaluate method for Result Class
 */
double Result::evaluate() const
{
	return expr->evaluate();
}
/**
 * @brief Polymorphous print method for Result Class
 */
void Result::print() const
{
	return expr->print(); //calls the print function for the given expression
}

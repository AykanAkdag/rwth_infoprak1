/**
 * @file
 *
 * @brief Contains the method declarations used in the Add Class
 *
 */

#include "add.h"
#include <iostream>

/**
 * @brief Constructor method for the Add class
 *
 * 		This constructor makes sure to initialize the left and right operands.
 *
 * @param  lhs left hand side Expression
 * @param  rhs right hand side Expression
 */
Add::Add(Expression* lhs, Expression* rhs)
{
	leftOperand = lhs;
	rightOperand = rhs;
}
/**
 * @brief Destructor method for the Add class
 *
 * 		This destructor deletes the expressions stored in the Add Class and thus frees
 * 		up the memory.
 */
Add::~Add()
{
	delete leftOperand;
	delete rightOperand;
}

/**
 * @brief Adds the expressions together
 *
 * 		This function adds the left and the right expressions together. They may be
 * 		simple doubles or long expressions of the Expression datatype. This is why evaluation
 * 		of both operands is needed before the addition operation can be performed, as to
 * 		make sure to complete all the previous operations first.
 *
 * @return The sum of the left and the right expressions
 */
double Add::evaluate() const
{
	return leftOperand->evaluate() + rightOperand->evaluate();
}

/**
 * @brief Prints out the addition
 *
 * 		This functions outputs the addition operation performed in a human readable fashion
 * 		with brackets and a "+" symbol.
 */
void Add::print() const
{
	std::cout << "(";
	leftOperand->print();
	std::cout << " + ";
	rightOperand->print();
	std::cout << ")";
}



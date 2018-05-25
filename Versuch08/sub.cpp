/**
 * @file
 *
 * @brief Contains the method declarations used in the Sub Class
 *
 */

#include <iostream>
#include "sub.h"

/**
 * @brief Constructor method for the Sub class
 *
 * 		This constructor makes sure to initialize the left and right operands.
 *
 * @param  lhs left hand side Expression
 * @param  rhs right hand side Expression
 */
Sub::Sub(Expression* lhs, Expression* rhs)
{
	leftOperand = lhs;
	rightOperand = rhs;
}

/**
 * @brief Destructor method for the Mul class
 *
 * 		This destructor deletes the expressions stored in the Mul Class and thus frees
 * 		up the memory.
 */
Sub::~Sub()
{
	delete leftOperand;
	delete rightOperand;
}

/**
 * @brief Subtracts the expressions
 *
 * 		This function subtracts the right expression from the and the left one. They may be
 * 		simple doubles or long expressions of the Expression datatype. This is why evaluation
 * 		of both operands is needed before the subtraction operation can be performed, as to
 * 		make sure to complete all the previous operations first.
 *
 * @return The difference of the left and the right expressions
 */
double Sub::evaluate() const
{
	return leftOperand->evaluate() - rightOperand->evaluate();
}

/**
 * @brief Prints out the difference
 *
 * 		This functions outputs the subtraction operation performed in a human readable fashion
 * 		with brackets and a "-" symbol.
 */
void Sub::print() const
{
	std::cout << "(";
	leftOperand->print();
	std::cout << " - ";
	rightOperand->print();
	std::cout << ")";
}

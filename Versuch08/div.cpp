/**
 * @file
 *
 * @brief Contains the method declarations used in the Div Class
 *
 */

#include <iostream>
#include "div.h"

/**
 * @brief Constructor method for the Div class
 *
 * 		This constructor makes sure to initialize the left and right operands.
 *
 * @param  lhs left hand side Expression
 * @param  rhs right hand side Expression
 */
Div::Div(Expression* lhs, Expression* rhs)
{
	leftOperand = lhs;
	rightOperand = rhs;
}

/**
 * @brief Destructor method for the Div class
 *
 * 		This destructor deletes the expressions stored in the Div Class and thus frees
 * 		up the memory.
 */
Div::~Div()
{
	delete leftOperand;
	delete rightOperand;
}

/**
 * @brief Divides the expressions
 *
 * 		This function divides the left and the right expressions. They may be
 * 		simple doubles or long expressions of the Expression datatype. This is why evaluation
 * 		of both operands is needed before the division operation can be performed, as to
 * 		make sure to complete all the previous operations first.
 *
 * @return The quotient of the left and the right expressions
 */
double Div::evaluate() const
{
	return leftOperand->evaluate() / rightOperand->evaluate();
}

/**
 * @brief Prints out the product
 *
 * 		This functions outputs the multiplication operation performed in a human readable fashion
 * 		with brackets and a "*" symbol.
 */
void Div::print() const
{
	std::cout << "(";
	leftOperand->print();
	std::cout << " / ";
	rightOperand->print();
	std::cout << ")";
}

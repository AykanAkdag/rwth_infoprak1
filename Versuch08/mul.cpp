/**
 * @file
 *
 * @brief Contains the method declarations used in the Mul Class
 *
 */

#include <iostream>
#include "mul.h"

/**
 * @brief Constructor method for the Mul class
 *
 * 		This constructor makes sure to initialize the left and right operands.
 *
 * @param  lhs left hand side Expression
 * @param  rhs right hand side Expression
 */
Mul::Mul(Expression* lhs, Expression* rhs)
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
Mul::~Mul()
{
	delete leftOperand;
	delete rightOperand;
}

/**
 * @brief Multiplies the expressions
 *
 * 		This function multiplies the left and the right expressions. They may be
 * 		simple doubles or long expressions of the Expression datatype. This is why evaluation
 * 		of both operands is needed before the multiplication operation can be performed, as to
 * 		make sure to complete all the previous operations first.
 *
 * @return The product of the left and the right expressions
 */
double Mul::evaluate() const
{
	return leftOperand->evaluate() * rightOperand->evaluate();
}

/**
 * @brief Prints out the product
 *
 * 		This functions outputs the multiplication operation performed in a human readable fashion
 * 		with brackets and a "*" symbol.
 */
void Mul::print() const
{
	std::cout << "(";
	leftOperand->print();
	std::cout << " * ";
	rightOperand->print();
	std::cout << ")";
}

/*
 * Praktikum Informatik 1 MMXVII
 * Versuch 8: Taschenrechner
 *
 * Datei:  expression.cpp
 * Inhalt: Sourcedatei Abstrakte Klasse Expression
 *
 * @author Can Oezmaden
 * @date Juli 2017
 */

#include "expression.h"
#include <iostream>
/**
 * @brief Constructor method for Expression Class
 */
Expression::Expression()
{
	std::cout << "Created Expression" << std::endl;
}

/**
 * @brief Destructor method for Expression Class
 */
Expression::~Expression()
{
	std::cout << "Deleted Expression" << std::endl;
}

/**
 * @brief Calculates the expression
 *
 * 		This function is the one actually calculation an expression.
 *
 * @return Returns the calculation result
 */
double Expression::evaluate() const
{
	return 0;
}
/**
 * @brief Prints the expression
 *
 * 		This function prints the currerntly calculated mathematical expression to the user in the most
 * 		human-readable way possible.
 */
void Expression::print() const
{
	std::cout << "This expression is equal to := " << this;
}



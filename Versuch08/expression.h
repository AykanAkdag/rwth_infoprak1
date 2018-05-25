/** @file
 * @brief Header file for the Expression Class
 *
 * Praktikum Informatik 1 MMXVII
 * Versuch 8: Taschenrechner
 *
 * Datei:  expression.h
 * Inhalt: Headerdatei Abstrakte Klasse Expression
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H
/**
 * @brief Abstract Expression Class
 *
 * 		This class is a parent for all the other implemented classes in this calculator.
 */
class Expression
{
public:
	Expression();
	virtual ~Expression();
	virtual double evaluate() const = 0; // calculates and returns the value of expression
	virtual void print() const = 0; // prints the mathematical expression as string
};

#endif

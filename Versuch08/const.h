/**
 * @file
 *
 * @brief Header file for the Const Class
 */

#ifndef CONST_H_
#define CONST_H
#include "expression.h"

/**
 * @brief Saves a value for further calculation
 *
 * 		This Class saves a value inside its private "value" variable
 *
 */
class Const: public Expression
{
public:
	Const(double initval);
	~Const();
	double evaluate() const; //polymorphous evaluate from parent class
	virtual void print() const;  //polymorphous print from parent class
private:
	double value; //saved value of the expression
};



#endif /* CONST_H_ */

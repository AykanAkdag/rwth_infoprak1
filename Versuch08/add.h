/**
 * @file
 *
 * @brief Header file for the Add Class
 */
#ifndef ADD_H
#define ADD_H_
#include "expression.h"

/**
 * @brief Addition expression
 *
 * 		This Class serves as a representation of the "+" operation.
 */
class Add : public Expression //parent class: Expression
{
public:
	Add(Expression* lhs, Expression* rhs); //constructor method: the operands must be given to the expression
								   //at the initialization
	~Add();
	virtual double evaluate() const;
	virtual void print() const;

private:
	Expression* leftOperand;
	Expression* rightOperand;
};

#endif /* ADD_H_ */

/**
 * @file
 *
 * @brief Header file for the Div Class
 */
#ifndef DIV_H_
#define DIV_H_
#include "expression.h"

/**
 * @brief Division expression
 *
 * 		This Class serves as a representation of the "/" operation.
 */
class Div : public Expression
{
public:
	Div(Expression* lhs, Expression* rhs);
	~Div();
	virtual double evaluate() const;
	virtual void print() const;
private:
	Expression* leftOperand;
	Expression* rightOperand;
};

#endif /* DIV_H_ */

/**
 * @file
 *
 * @brief Header file for the Mul Class
 */
#ifndef MUL_H_
#define MUL_H_
#include "expression.h"

/**
 * @brief Multiplication expression
 *
 * 		This Class serves as a representation of the "*" operation.
 */
class Mul : public Expression
{
public:
	Mul(Expression* lhs, Expression* rhs);
	~Mul();
	virtual double evaluate() const;
	virtual void print() const;
private:
	Expression* leftOperand;
	Expression* rightOperand;
};

#endif /* MUL_H_ */

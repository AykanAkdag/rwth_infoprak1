/**
 * @file
 *
 * @brief Header file for the Sub Class
 */
#ifndef SUB_H_
#define SUB_H_
#include "expression.h"

/**
 * @brief Subtraction expression
 *
 * 		This Class serves as a representation of the "-" operation.
 */
class Sub : public Expression
{
public:
	Sub(Expression* lhs, Expression* rhs);
	~Sub();
	virtual double evaluate() const;
	virtual void print() const;
private:
	Expression* leftOperand;
	Expression* rightOperand;
};

#endif /* SUB_H_ */

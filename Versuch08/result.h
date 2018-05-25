/**
 * @file
 *
 * @brief Header file for the Result Class
 */

#ifndef RESULT_H_
#define RESULT_H_
#include "expression.h"

/**
 * @brief Calculates and saves the result
 *
 *		This Class is implemented to evaluate an expression and forward the result to the next
 *		operation, if such exists.
 */
class Result : public Expression
{
public:
	Result(Expression* currexpr); //Construct the instance with a pointer to the expression
	~Result();
	virtual double evaluate() const;
	virtual void print() const;
private:
	Expression* expr;
};

#endif /* RESULT_H_ */

/** @mainpage
 *
 * Praktikum Informatik 1 MMXVII
 * Versuch 08: Taschenrechner
 *
 * @file
 * @brief Main Routine
 * Datei:  taschenrechner.cpp
 * Inhalt: Hauptprogramm
 *
 * @author Can Oezmaden
 * @date Juli 2017
 */

#include <iostream>
#include "expression.h"
#include "const.h"
#include "result.h"
#include "add.h"
#include "mul.h"
#include "sub.h"
#include "div.h"

/**
 * @brief Test function for the Const Class
 *
 * 		This function is called from the main routine to complete the check for the
 * 		implementation of the Const Class.
 */
void testConst()
{
	std::cout << "------Testing Const Class------" << std::endl;
	Const c(4);
	c.print();
	std::cout << " = " << c.evaluate() << std::endl;
}

/**
 * @brief Test function for the Result Class
 *
 * 		This function is called from the main routine to complete the check for the
 * 		implementation of the Result Class.
 */
void testResult()
{
	std::cout << "------Testing Result Class------" << std::endl;
	Result res ( new Const(4) );
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @brief Test function for the Add Class
 *
 * 		This function is called from the main routine to complete the check for the
 * 		implementation of the Add Class.
 */
void testAddConst()
{
	std::cout << "------Testing Add Class------" << std::endl;
	Result res (new Add (
				new Const(7),
				new Const(8)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @brief Test function for the Add Class and Mul Class together
 *
 * 		This function is called from the main routine to complete the check for the
 * 		implementation of Add and Mul Classes and the way they work together.
 */
void testMulAddConst()
{
	std::cout << "------Testing Add & Mul Classes------" << std::endl;
	Result res (	new Add (
					new Const(4),
					new Mul (
						new Const(9),
						new Const(5)
					)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @brief Test function for the Sub, Mul and Add Classes
 *
 * 		This function is called from the main routine to complete the check for the
 * 		implementation of Add, Sub and Mul Classes and the way they work together.
 */
void testSubMulAddConst()
{
	std::cout << "------Testing Sub, Mul & Add Classes------" << std::endl;
	Result res (new Add (
					new Const(4),
					new Mul (
						new Const(9),
						new Sub (
							new Const(7),
							new Const(2)
						)
					)
				)
			);
	res.print();
	std::cout << " = " << res.evaluate() << std::endl;
}

/**
 * @brief Final general test
 *
 * 		This function is called from the main routine to complete the check for the
 * 		all the implementated classes.
 */
void finalTest()
{
	std::cout << "------FINAL TEST------" << std::endl;
	Result res (new Add (
					new Const(4),
					new Mul (
						new Const(9),
						new Sub (
							new Const(7),
							new Div (
								new Const(10),
								new Const(5)
								)
							)
						)
					)
		   );

	res.print();
	std::cout << " = ";
	std::cout << res.evaluate();
	std::cout << std::endl;

//// Das Ergebnis sollte etwa so aussehen:
//// (4 + (9 * (7 - (10 / 5)))) = 49
//
}

/**
 * @brief Main routine
 */
int main()
{
	// Implementieren Sie zuerst die Klassen Const und Result und testen Sie das Ergebnis.
	testConst();
	std::cout << "------Const Class Test End------\n" << std::endl;
	testResult();
	std::cout << "------Result Class Test End------\n" << std::endl;
	
	// Ergänzen Sie ihr Programm nach und nach um weitere Rechenoperationen
	testAddConst();
	std::cout << "------Add Class Test End------\n" << std::endl;
	testMulAddConst();
	std::cout << "------Add & Mul Classes Test End------\n" << std::endl;
	testSubMulAddConst();
	std::cout << "------Sub, Mul & Add Classes Test End------\n" << std::endl;
	std::cout << "Der finale Test: kommt noch..." << std::endl;
	finalTest();
	std::cout << "Expected Answer: (4 + (9 * (7 - (10 / 5)))) = 49 " << std::endl;
	std::cout << "------FINAL TEST OVER------\n" << std::endl;
	return 0;
}


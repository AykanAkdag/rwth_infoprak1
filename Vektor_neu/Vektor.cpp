//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Vektor.h"
#include <cmath>
#define PI 3.14159265
#define EPSILON 0.1

/**
 * @brief Converts radians to degrees
 *
 *	 This function converts an angle given in radians to degrees
 *
 * @param  rad Angle in radians
 * @return double Angle in degrees
 */
double rad2deg(double rad)
{
	return rad*(180/PI);
}

/**
 * @brief Constructor method for a vector
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
}

/**
 * @brief Destructor method for a vector
 */
Vektor::~Vektor()
{
}

/**
 * @brief Prints the coordinates of a vector
 */
void Vektor::ausgabe() const
{
	std::cout << "X:" << this->x << std::endl;
	std::cout << "Y:" << this->y << std::endl;
	std::cout << "Z:" << this->z << std::endl;
}

/**
 * @brief Returning the X coordinate of a vector
 *
 *	 This method returns the numerical value of the x coordinate of a given vector in the Class Vektor
 *
 * @return double Coordinate in the x-plane
 */
double Vektor::getX() const
{
	return this->x;
}

/**
 * @brief Returning the Y coordinate of a vector
 *
 *	 This method returns the numerical value of the y coordinate of a given vector in the Class Vektor
 *
 * @return double Coordinate in the y-plane
 */
double Vektor::getY() const
{
	return this->y;
}

/**
 * @brief Returning the Z coordinate of a vector
 *
 *	 This method returns the numerical value of the z coordinate of a given vector in the Class Vektor
 *
 * @return double Coordinate in the z-plane
 */
double Vektor::getZ() const
{
	return this->z;
}

/**
 * @brief Returning the lenght of a vector
 *
 *	 This method returns the Euclidean norm of a given vector in the Class Vektor
 *
 * @return double Coordinate in the z-plane
 */
double Vektor::length() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));

}

/**
 * @brief Subtraction of two vectors
 *
 *	 This method calculates the difference between two given vectors. Let v be the minuend and w the subtraend.
 *	 To calculate v-w this method has to be called in the form: v.sub(w). Attention! v-w != w.sub(v) as subtraction
 *	 is not commutative in the vector space R^3.
 *
 * @param  input The 2nd vector (w)
 * @return Vektor The resulting vector difference
 */
Vektor Vektor::sub(const Vektor& input) const
{
	return Vektor(this->x-input.x, this->y-input.y, this->z-input.z);
}

/**
 * @brief Addition of two vectors
 *
 *	 This method calculates the sum of two given vectors. Let v and w be summands.
 *	 To calculate v+w this method has to be called in the form: v.add(w) or w.add(v) as
 *	 addition operation is commutative in the vector space R^3.
 *
 * @param  input The 2nd vector (w)
 * @return Vektor The resulting vector sum
 */
Vektor Vektor::add(const Vektor& input) const
{
	return Vektor(this->x+input.x, this->y+input.y, this->z+input.z);
}

/**
 * @brief Checks if vectors are orthogonal
 *
 *	 This method checks if the given vectors are orthogonal to one another, that is - is the angle
 *	 between them = 90 deg? This requires the calculation of the dot product and when it's equal to
 *	 0 then the conclusion could be made that the input vectors are orthogonal. As calculations with
 *	 floating point arithmetic are not 100% accurate, an EPSILON preprocessor constant is checked as
 *	 a small tolerance value.
 *
 * @param  input The 2nd vector
 * @return true if vectors are orthogonal, false otherwise
 *
 */
bool Vektor::ortho(const Vektor& input) const
{
	if(this->scalarProd(input) > -EPSILON && this->scalarProd(input) < EPSILON )
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief Calculates the scalar (dot) product of two vectors
 *
 *	 This method calculates the dot product of two input vectors. Let v and w be vectors, then
 *	 v.w = v.scalarProd(w) = w.scalarProd(x) as the product is commutative.
 *
 * @param  input The 2nd vector (w)
 * @return double The scalar product
 *
 */
double Vektor::scalarProd(const Vektor& input) const
{
	return this->x*input.x + this->y*input.y + this->z*input.z;
}

/**
 * @brief Calculates the angle between two vectors in deg
 *
 *	 This method calculates the angle between two input vectors. It uses the fact that the dot product divided
 *	 by the sum of lenghts of two vectors is the cosine of the angle between them. Then the arccos function
 *	 provided in the cmath library is applied to get the angle and the radian output is converted into degrees
 *
 * @param  input The 2nd vector
 * @return double The angle between the vectors
 *
 */

double Vektor::angle(const Vektor& input) const
{
	return rad2deg(acos(this->scalarProd(input)/(this->length()*input.length())));
}

/**
 * @brief Rotates the vector around the Z plane
 *
 *	This method multiplies the vector given to it with a rotation matrix about the z plane.
 *
 * @param  rad The angle in radians
 * @return Vektor Rotated vector
 */
void Vektor::rotateAroundZ(double rad)
{
	double rotx = cos(rad)*x - sin(rad)*y;
	double roty = sin(rad)*x + cos(rad)*y;
	this->x = rotx;
	this->y = roty;
}

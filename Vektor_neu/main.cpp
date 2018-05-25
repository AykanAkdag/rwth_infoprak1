//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 04: Einführung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

/**
* @mainpage Reversi
*
* Documentation of the Versuch 4, vectors and horizont sightline.
*
* @author Can Oezmaden
* @date 2017
*/



#include <iostream>
#include <iomanip>
#include "Vektor.h"
#include <cmath>
#include <string>

#define HUMANHEIGHT 1.8
#define EARTHRADIUS 6371
#define PLATFORM    830
#define ANGLESTEP   0.0000001

int main()
{
	int counter = 0;
	double rad = 0;

	Vektor earthradius = Vektor(0, EARTHRADIUS, 0);
	Vektor human = earthradius.add(Vektor(0, (HUMANHEIGHT+PLATFORM)/1000, 0));
	Vektor sightline = earthradius.sub(human);

	//Checking if the sightline is tangent to the earth curvature
	while (!sightline.ortho(earthradius))
	{
		earthradius.rotateAroundZ(ANGLESTEP);
		sightline = earthradius.sub(human);

		rad += ANGLESTEP;
		counter++;
	}

	std::cout << "Sie koennen " << sightline.length() << " km weit sehen\n";
	std::cout << "Sie sind " << HUMANHEIGHT + PLATFORM << " Meter hoch\n";
	std::cout << "Der Winkel betraegt " << std::setprecision(5) << rad*180/3.14159265 << " Grad \n";
	std::cout << "Anzahl steps: " << counter;
	return 0;
}

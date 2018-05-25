/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//
// Autor: Can Oezmaden
// Mtr: 375074
//
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	// Struktur Definition
	struct Person
	{
		std::string sNachname;
		std::string sVorname;
		int iGeburtsjahr = 0;
		int iAlter = 0;
	};

	//
	Person nBenutzer;

	//Personalinformation Angaben
	std::cout << "Bitte geben Sie Ihre Vorname ein: ";
	std::cin  >> nBenutzer.sVorname;
	std::cout << "Bitte geben Sie Ihre Nachname ein: ";
	std::cin  >> nBenutzer.sNachname;
	std::cout << "Bitter geben Sie Ihr Geburtsjahr ein: ";
	std::cin  >> nBenutzer.iGeburtsjahr;
	std::cout << "Bitter geben Sie Ihr Alter ein: ";
	std::cin  >> nBenutzer.iAlter;

	// 1.7.2.1
	//Einzeln kopieren

	std::cout << "\nKopiere in Einzeln Schritten..." << std::endl;

	Person nKopieEinzeln;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;

	std::cout <<"\nKopien erfolgreich erstellt! Die Daten sind" << std::endl;
	std::cout << "Vorname: " << nKopieEinzeln.sVorname << std::endl;
	std::cout << "Nachname: " << nKopieEinzeln.sNachname << std::endl;
	std::cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << std::endl;
	std::cout << "Alter: " << nKopieEinzeln.iAlter << std::endl;

	// 1.7.2.2
	// Gesamtekopie

	std::cout << "\nKopiere die gesamte Struct..." << std::endl;
	Person nKopieGesamt;
	nKopieGesamt = nBenutzer;

	std::cout <<"\nKopie erfolgreich erstellt! Die Daten sind" << std::endl;
	std::cout << "Vorname: " << nKopieGesamt.sVorname << std::endl;
	std::cout << "Nachname: " << nKopieGesamt.sNachname << std::endl;
	std::cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << std::endl;
	std::cout << "Alter: " << nKopieGesamt.iAlter << std::endl;

	return 0;
	
}

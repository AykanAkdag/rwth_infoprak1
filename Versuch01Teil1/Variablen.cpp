//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//
// Autor: Can Oezmaden
// Mt.Num: 375074
//
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	// Deklaration der Variablen
	int        iErste = 0,       iZweite = 0;
	int        iSumme = 0,     iQuotient = 0;
	double     dSumme = 0,     dQuotient = 0;
	double dSummeCast = 0, dQuotientCast = 0;

	//Eingaben vom Benutzer
	std::cout << "Bitte geben Sie die erste Zahl ein: ";
	std::cin  >> iErste;
	std::cout << "Bitte geben Sie die zweite Zahl ein: ";
	std::cin  >> iZweite;

	//Berechnung als Integers
	iSumme     = iErste + iZweite;
	iQuotient  = iErste / iZweite;

	//Speicherung der Ergebnisse in doubles
	dSumme     = iErste + iZweite;
	dQuotient  = iErste / iZweite;

	//Typecasting in doubles und dann die gewoehnte Berechnung
	dSummeCast     = (double)iErste + (double)iZweite;
	dQuotientCast  = (double)iErste / (double)iZweite;

	//Ausgaben der Ergebnisse
	std::cout << "\nSie haben die Zahlen " << iErste << " und " << iZweite << " eingegeben."     << std::endl;
	std::cout << "Datentyp: Integer\n" << std:: endl;

	//Integer Ausgaben 1.7.1.1
	std::cout << "+++Endergebnis als Integer gespeichert+++\n";
	std::cout << "Die Summe von beiden lautet:    "<< iErste <<"+"<< iZweite <<"="<<iSumme    << std::endl;
	std::cout << "Die Quotient von beiden lautet: "<< iErste <<"/"<< iZweite <<"="<<iQuotient << std::endl;
	std::cout << "\n";

	//Double Ausgaben 1.7.1.2
	std::cout << "+++Endergebnis als Double gespeichert+++\n";
	std::cout << "Die Summe von beiden lautet:    "<< iErste <<"+"<< iZweite <<"="<<dSumme    << std::endl;
	std::cout << "Die Quotient von beiden lautet: "<< iErste <<"/"<< iZweite <<"="<<dQuotient << std::endl;
	std::cout << "\n";

	//Typecast Berechnung Ausgaben 1.7.1.3
	std::cout << "+++Typecasting der Eingaben in double bevor die Berechnung, Endergebnis Datentyp: double+++\n";
	std::cout << "Die Summe von beiden lautet:    "<< iErste <<"+"<< iZweite <<"="<<dSummeCast    << std::endl;
	std::cout << "Die Quotient von beiden lautet: "<< iErste <<"/"<< iZweite <<"="<<dQuotientCast << std::endl;

	//1.7.1.5
	//String Deklarationen
	std::string sVorname;
	std::string sNachname;
	std::string sVornameName;
	std::string sNameVorname;

	//Eingaben des Namens
	std::cout << "\nGeben Sie bitte Ihre Vorname ein (max 15 Zeichen): ";
	std::cin  >> sVorname;
	std::cout << "Geben Sie bitte Ihre Nachname ein (max 20 Zeichen): ";
	std::cin  >> sNachname;

	//String Verkettung
	sVornameName =  sVorname + " "  + sNachname;
	sNameVorname = sNachname + ", " + sVorname;

	//Ausgaben des Namens
	std::cout << "\nIhre Name in der Form [Name Vorname]: "<< sNameVorname << std::endl;
	std::cout << "Ihre Name in der Form [Vorname, Name]: "<< sVornameName << std::endl;

	// 1.7.1.5
	//Beginn des Blockes
	{
		//Deklaration der Felder
		int iFeld[2] = {1, 2}; // Ansprechung: iFeld[0]=1 iFeld[1]=2.
		int spielfeld[2][3] = {{1, 2, 3},
						 {4, 5, 6}}; //Ansprechung Beispiel: spielfeld[1][2]= 5, spielfeld[0][2]=3.

		//Felder Ausgabe
		std::cout << "\nAusgabe von Array namens: iFeld" << std::endl;
		std::cout << iFeld[0] << std::endl;
		std::cout << iFeld[1] << std::endl;
		std::cout << "\nAusgabe von Array namens: spielfeld" << std::endl;
		std::cout << spielfeld[0][0] << " " << spielfeld[0][1] << " " << spielfeld[0][2] << std::endl;
		std::cout << spielfeld[1][0] << " " << spielfeld[1][1] << " " << spielfeld[1][2] << std::endl;

		//Konstante iZweite
		const int iZweite = 1;
		std::cout << "\nGebe die in dem Block neu definierte Konstante iZweite aus: "<< iZweite << std::endl;
	}

	//Ausgabe der Konstante iZweite nach dem Block
	std::cout << "\nGebe die Konstante iZweite noch mal aus (nach dem Block): "<< iZweite << std::endl; //Erwarte die erste Zuweisung zu iZweite

	// 1.7.1.6
	//Integer Deklarationen
	int iName1 = 0, iName2 = 0;

	//Wandle die erste und die zweite Buchstabe des Vornamens in eine Zahl
	char cName1 = sVorname[0];
	char cName2 = sVorname[1];
	iName1 = int(cName1);
	iName2 = int(cName2);

	//Gebe die ASCII Zahlen aus
	std::cout << "\nDie erste Buchstabe Ihres Vornames in ASCII ist: "<< iName1 << std::endl;
	std::cout << "Die zweite Buchstabe Ihres Vornames in ASCII ist: " << iName2 << std::endl;

	// 1.7.1.7
	//Offset abziehen und normalisieren um die Klein/Grossbuchstaben gleich abzulesen
	iName1 = ((iName1 - 65) % 32) + 1; // 65 ist Gross "A" in ASCII
	iName2 = ((iName2 - 65) % 32) + 1;

	std::cout << "\nNach der Normalisierung fuer klein/gross Buschtaben ->" << std::endl;
	std::cout << "Die erste Buchstabe Ihres Vornames ins Alphabet ist: "<< iName1 << std::endl;
	std::cout << "Die zweite Buchstabe Ihres Vornames ins Alphabet ist: " << iName2 << std::endl;

	return 0;
}

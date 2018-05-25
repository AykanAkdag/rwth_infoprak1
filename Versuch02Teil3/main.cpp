/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 2.3 Felder
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm, en/de-crypt Funktionen
//
// Autor: Can Özmaden
// Mtr: 375074
//
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#define ASCIIOFFSET 65

// Die Funktion fuer VERSCHLUESSELUNG
std::string encrypt(std::string input, char table[2][26])
{
	std::string cipher; // Das verschluesseltes Wort

	//Lese jedes Zeichen des inputs und finde die dazugehoerige Verschluesselung
	for (int i = 0; i < input.length(); ++i)
	{
		//Inktrementiere das Endergebniss mit string Vekettung
		cipher += table[1][input[i] - ASCIIOFFSET];
	}
	return cipher;
}

// Die Funktion fuer ENTSCHLUESSELUNG
std::string decrypt(std::string input, char table[2][26])
{
	std::string decipher; // Das entschluesseltes Wort
	int index;

	//Lese jedes Zeichen des inputs und finde die dazugehoerige Entschluesselung
	for (int i = 0; i < input.length(); ++i)
	{
		//Suche nach dem Index des Verschuesseltes Zeichen
		for (int j = 0; j < 26; ++j)
		{
			if (input[i] == table[1][j])
			{
				index = j;
			}
		}

		//Inkrementiere das entschluesseltes Wort mit dem naechsten Zeichen
		decipher += table[0][index];
	}
	return decipher;
}


int main()
{
	char lookuptable[2][26] = {{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'Q', 'X', 'Y', 'Z'}
	,{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'}};

	std::string input; //Eingabe des Benutzers
	std::string encrypted; //Zwischenspeicherung des verschluesseltes Wort

	bool error = true;

	while (error == true)
	{
		//Eingaben
		std::cout << "Bitte geben Sie das Wort zu verschluesseln ein (max. 5 Zeichen, Grossbuchstaben): " << std::endl;
		std::cin  >> input;

		if (input.length() > 5)
		{
			std::cout << "ERROR. Das Wort muss 5 Zeichen lang sein" << std::endl;
		}
		else
		{
			error = false;
		}
	}


	//Ausgaben
	std::cout << "\nSie haben das Wort "<< input << " eingegeben." << std::endl;

	//Verschluesselung
	std::cout << "...Verschluesselung laeuft..." << std::endl;
	encrypted =  encrypt(input, lookuptable);
	std::cout << "Das verschluesseltes Wort jetzt lautet: " << encrypted << std::endl;

	//Entschluesselung
	std::cout << "..Nun entschluessele das Wort zurueck..." << std::endl;
	std::cout << "Das Wort war: " << decrypt(encrypted, lookuptable) << std::endl;

	return 0;
}



/** @mainpage
 *
 * Praktikum Informatik 1@n
 * Versuch 7: Ueberladung
 *
 * @author Can Oezmaden, 375074
 * @date Juli 2017
 */

/**
 * @file main.cpp
 *
 * content: main routine
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include "Student.h"
#include <vector>

int main()
{

	typedef std::vector<Student>::iterator itType;
	typedef std::vector<Student>::reverse_iterator revitType;

	std::vector<Student> testList; //vector of Students

	Student student = Student();

	char abfrage;
	std::cout << "Wollen sie die Liste selbst fuellen? (j)/(n) ";
	std::cin >> abfrage;

	if (abfrage != 'j')
	{
		student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
		testList.push_back(student);
		student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
		testList.push_back(student);
		student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
		testList.push_back(student);
	}

	do
	{
		std::cout << "\nMenue:" << std::endl << "-----------------------------"
				<< std::endl <<
				   "(1): Datenelement hinzufuegen" << std::endl
				<< "(2): Datenelement abhaengen" << std::endl
				<< "(3): Datenbank vorwaerts ausgeben" << std::endl
				<< "(4): Datenbank rueckwaerts ausgeben" << std::endl
				<< "(5): Datenbank sortieren und ausgeben" << std::endl
				<< "(6): Datenelemnt gezielt loeschen und Datenbank ausgeben" << std::endl
				<< "(7): Beenden" << std::endl;
		std::cin >> abfrage;

		switch (abfrage)
		{
		case '1':
		{
			unsigned int matNr = 0;
			std::string name = "";
			std::string dateOfBirth = "";
			std::string address = "";

			std::cout
					<< "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
			std::cin.ignore(10, '\n'); // ignore character '\n', which still is in the buffer
			getline(std::cin, name);    // get entire line, including whitespace
			std::cout << "Geburtsdatum: ";
			getline(std::cin, dateOfBirth);
			std::cout << "Adresse: ";
			getline(std::cin, address);
			std::cout << "Matrikelnummer: ";
			std::cin >> matNr;

			student = Student(matNr, name, dateOfBirth, address);

			testList.push_back(student);
		}
			break;
		case '2':
		{
			if (!testList.empty()) //if not empty
			{
				std::cout << "Das erste Datenelemt wird entfernt\n";
				std::cout << testList.back();
				testList.pop_back();
			}
			else //empty
			{
				std::cout << "Die Liste ist leer!\n";
			}
		}
			break;

		case '3':
			std::cout << "Inhalt der Liste:\n";
			for(itType it = testList.begin(); it != testList.end(); ++it)
			{
				std::cout << *it;
			}
			break;

		case '4':
			std::cout << "Inhalt der Liste umgekehrt:\n";
			for (revitType revit = testList.rbegin(); revit != testList.rend(); ++revit)
			{
				std::cout << *revit;
			}
			break;
		case '5':
			std::cout << "Sortierung laeuft..." << std::endl;
			std::stable_sort(testList.begin(), testList.end(), std::greater<Student>()); //sorting using the implemented
																						 //overloaded greater operator
																						 //see (Student.cpp)

			std::cout << "\nInhalt der Liste nach der Sortierung (Absteigend):\n";//print in descending order
			for (itType it = testList.begin(); it != testList.end(); ++it)
			{
				std::cout << *it;
			}
			std::cout << "\nInhalt der Liste nach der Sortierung (Aufsteigend):\n";//print in ascending order
			for (revitType revit = testList.rbegin(); revit != testList.rend();
					++revit)
			{
				std::cout << *revit;
			}
			break;
		case '6':
		{
			unsigned int searchMatNr;
			Student delElem;
			bool success = false; //success flag in order to notify the user if no student is found

			std::cout << "____ Student/in loeschen ___" << std::endl;
			std::cout << "Bitte geben Sie die Matrikelnummer ein:\n";
			std::cin >> searchMatNr;
			delElem = Student(searchMatNr, "", "", ""); //create a student instance with that matnr

			for (itType it = testList.begin(); it != testList.end(); ++it)//iterate over the list
			{
				if (*it == delElem)//use the overloaded "==" (see Student.cpp)
				{
					std::cout << "Folgende/r Student/in wird geloescht:" << std::endl; //notify the user
					std::cout << *it;
					testList.erase(it); //delete the element
					success = true; //set success flag
					break;
				}
			}
			if(success == false) //fail case
			{
				std::cout << "Der Student/Die Studentin mit dieser MtNr ist nicht gefunden. Versuchen Sie noch mal.\n";
			}

			/*
			 *  Output the database after deleting an element
			 */
			std::cout << "\nInhalt der Liste nach der Loeschung:\n";
			for (itType it = testList.begin(); it != testList.end(); ++it)
			{
				std::cout << *it;
			}

		}
		break;
		case '7':
			std::cout << "Das Programm wird nun beendet";
			break;

		default:
			std::cout << "Falsche Eingabe, bitte nochmal";
			break;
		}
	} while (abfrage != '7');

	return 0;
}

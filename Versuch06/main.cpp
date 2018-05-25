/** @mainpage
 *
 * Praktikum Informatik 1@n
 * Versuch 6: Standard Template Library
 *
 * @author Can Oezmaden, 375074
 * @date Juni 2017
 *
 * *Die erklaerenden Texte wurden zum Teil von* wikipedia.org *uebernommen*@n
 * *Siehe hierzu die entsprechende* [Webseite][wikipedia].
 *
 * [wikipedia]: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 */

/**
 * @file main.cpp
 *
 * content: main routine
 */

#include <iostream>
#include <string>
#include "Student.h"
#include <vector>

int main()
{

	typedef std::vector<Student>::const_iterator itType;
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
		student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
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
					<< "Bitte geben sie die Daten für den Studenten ein.\nName: ";
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
				testList.back().print();
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
				Student currStudent = *it;
				currStudent.print();
			}
			break;

		case '4':
			std::cout << "Inhalt der Liste umgekehrt:\n";
			for (revitType revit = testList.rbegin(); revit != testList.rend(); ++revit)
			{
				Student currStudent = *revit;
				currStudent.print();
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

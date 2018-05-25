/** @mainpage
 *
 * Praktikum Informatik 1@n
 * Versuch 5: Dynamische Datenstrukturen
 *
 * @author Can Özmaden, 375074
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
#include "List.h"

int main()
{
	List testList;
	Student student = Student();

	char abfrage;
	std::cout << "Wollen sie die List selbst fuellen? (j)/(n) ";
	std::cin >> abfrage;

	if (abfrage != 'j')
	{
		student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
		testList.enqueue_head(student);
		student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
		testList.enqueue_head(student);
		student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
		testList.enqueue_head(student);
	}

	do
	{
		std::cout << "\nMenue:" << std::endl << "-----------------------------"
				<< std::endl <<
				   "(1): Datenelement hinzufuegen" << std::endl
				<< "(2): Datenelement abhaengen" << std::endl
				<< "(3): Datenbank vorwaerts ausgeben" << std::endl
				<< "(4): Datenbank rueckwaerts ausgeben" << std::endl
				<< "(5): Datenelement gezielt loeschen" << std::endl
				<< "(6): Datenelement von hinten hinzufuegen" <<std::endl
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

			testList.enqueue_head(student);
		}
			break;
		case '2':
		{
			Student delElem = Student();
			bool success = false;
			success = testList.dequeue(delElem);

			if (success)
			{
				std::cout << "Das erste Datenelemt wird entfernt\n";
				delElem.print();
			}
			else
			{
				std::cout << "Die Liste ist leer!\n";
			}
		}
			break;

		case '3':
			std::cout << "Inhalt der Liste:\n";
			testList.print_forwards();
			break;

		case '4':
			std::cout << "Inhalt der Liste:\n";
			testList.print_backwards();
			break;

		case '5':
		{
			Student delElem = Student();
			unsigned int searchMatNr;
			bool success = false;

			std::cout << "Bitte geben Sie die Matrikelnummer ein:\n";
			std::cin >> searchMatNr;

			success = testList.delete_element(searchMatNr, delElem);

			if (success == true)
			{
				std::cout << "Das Datenelemt wird entfernt\n";
				delElem.print();
			}
			else
			{
				std::cout << "Der Student/Die Studentin mit dieser MtNr ist nicht gefunden. Versuchen Sie noch mal.\n";
			}

		}
			break;
		case '6':
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

			testList.enqueue_tail(student);
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

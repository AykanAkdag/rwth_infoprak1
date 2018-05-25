/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 2.2 Iterative Berechnung der Fibonacci
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm und fib Funktion
//
// Autor: Can Özmaden
// Mtr: 375074
//
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fib(int n, int& currFib, int& prevFib)
{
	// Anfangsbedingungen fuer Fibonacci-Zahlen
	if(n == 0)
	{
		return 0;
	}
	else if(n == 1)
	{
		return 1;
	}

	// Berechnung der naechster Fibonacci-Zahl
	int newFib = prevFib + currFib ; // Formel zur Berechnung von eine Fibonacci-Zahl
	prevFib = currFib;               // Erst die aktuelle Wert zu vorherigen Wert wandeln
	currFib = newFib;                // Dann die aktuelle Wert aktualisieren

	return newFib;					 // Die neue Wert zurueckgeben
}

int main ()
{
	int prevFib = 0;
	int currFib = 1;

	std :: cout << " Fibonacci - Zahlen :" << std :: endl ;
	for (int i = 0; i <= 47 ; i ++) // i =/= 1 ! sondern i = 0
	{
		std :: cout << "f(" << i << ") = " << fib(i, currFib, prevFib) << std :: endl ;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXVII
// Versuch 2.1: Rekursive Berechnung  der Fibonacci Zahlen
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//
// Autor: Can Özmaden
// Mt.Num: 375074
//
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#define N 12

//Die Funktion die eine Zahl n aus der Hauptprogrammt kriegt und liefert entsprechend die n-te Fibonnaci Zahl
int fib (int n)
{
	// Anfangsbedingungen fuer Fibonacci-Zahlen
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	// Die Formel zur Berechnung die n-te Fibonacci-Zahl
	else
	{
		return fib(n-1)+fib(n-2);
	}
}

int main()
{
	int fibzahlen[N+1];

	//Aufrufen und speichern alle Ergebnisse von Fibonacci-Zahlen bis N in eine Array namens fibzahlen
	for (int var = 0; var != N+1; var++)
	{
		fibzahlen[var] = fib(var);
	}

	//Die Ausgabe alle Fibonnaci Zahlen bis eine vorgegebene N
	std::cout << "Die ersten " << N << " Fibonacci-Zahlen sind:" << std::endl;

	for (int var = 0; var != N+1; var++)
	{
		std::cout << fibzahlen[var] << " ";
	}
}







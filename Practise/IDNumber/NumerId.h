#pragma once
#include "NumerId.h"
#include <ostream>

//Klasa przechowujaca numer indeksu
class NumerId
{
public:
	//Kostruktor zapisujacy wartosc indeksu
	NumerId(int value);

	//Konstuktor kopiujacy
	NumerId(const NumerId& obj) = default;
	
	//Przeciazenie operatora strumienia pozwalajace na wyswietlanie zawartosci zmiennej number w specjalnym formacie
	friend std::ostream& operator << (std::ostream& os, const NumerId& obj);

	//Metoda zwracajaca stala referencje do aktualnego obiektu
	const NumerId& numId() const;

private:
	//Numer indeksu
	int number;
};

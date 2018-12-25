#pragma once
#include "Bit.h"

class BitArray 
{
public:

	//Kontruktor tworzacy tablice charow o zadanej długości count oraz ustawia zadana wartość value
	BitArray(const int& count, const bool& value = false);
	
	//Desktruktor usuwajacy tablice 
	~BitArray();

	//Metoda wypisujaca tablice bitow
	void print() const;

	//Przeladowanie operatora [] zwracajacego obiekt z wartoscia z zadanej pozycji
	//bita w indeksie
	Bit operator[](const int & position) const;

private:

	//Deklaracja zmiennych
	unsigned char * _bits;
	int _size;
};
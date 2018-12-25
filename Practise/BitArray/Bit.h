#pragma once

class Bit 
{
public:

	//Kontruktor tworzacy obiekt, ktory zawiera numer pozycji w indeksie tablicy - position,
	//oraz wskaznik do indeksu tablicy z BitArray *bitArray
	Bit(const int& position, unsigned char* bitArray);

    //Przeladowanie operatora = przypisujacy zadana wartosc do bitu w zadanej kolejnosci value
	void operator =(const bool& value);

	//Przeladowanie typu bool pozwalajace zwracac wartosc danego bitu
	operator bool() const;

private:

    //Deklaracja zmiennych
	unsigned char * _bitArray;
	int _positionInCell;
};
#pragma once
#include "InfoClass.h"

//Klasa InfoSmartPtr bedoca sprytnym wskaznikiem obslugujacym klase InfoClass
class InfoSmartPtr
{
public:
	//Glosny konstruktor
	InfoSmartPtr(InfoClass *temp);
	//Konstruktor kopiujacy
	InfoSmartPtr(const InfoSmartPtr& obj);
	//Glosny destruktor
	~InfoSmartPtr();

	//Przeciazenie operatora * ktory zwraca stala referencje do klasy InfoClass
	const InfoClass& operator*() const;
	//Przeciazenie operatora -> ktory zwraca staly wskaznik do klasy InfoClass
	const InfoClass* operator->() const;

	//Przeciazenie operatora * ktory zwraca referencje do klasy InfoClass
	InfoClass& operator*();
	//Przeciazenie operatora -> ktory zwraca wskaznik do klasy InfoClass
	InfoClass* operator->();

	//Przeciazenie operatora = pozwalajace na wskazywanie kilku wskaznikow na ten sam obiekt
	void operator=(const InfoSmartPtr& obj);

private:
	//Wskaznik do klasy InfoClass
	InfoClass *ptr;
	//Dynamicznie przechowywana liczba mowiaca o ilosc wskaznikow pokazujacych na powyzszy obiekt
	int *number;
	//Prywatna metoda operujaca pamiecia i zawartoscia zmiennej number
	void check_number();

};

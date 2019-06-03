#pragma once
#include <iostream>
#include <string>

using namespace std;

//Prosta klasa InfoClas przechowujaca napis
class InfoClass
{
public:
	//Glosny konstruktor przyjmujacy napis
	InfoClass(string _napis);
	//Glosny desktruktor
	virtual ~InfoClass();

	//Wirtualna metoda zwracajaca zawartosc skladowej name
	virtual string info() const;
	//Wirtualna metoda zwracajaca zawartosc zmiennej text
	string info(const string& text) const;

protected:
	//Przechowywany napis
	string name;
};

//Klasa InfoSuperClass dziedzicaca po InfoClass przechowujaca napis i date
class InfoSuperClass: public InfoClass
{
public:
	//Glosny konstruktor
	InfoSuperClass(string _name, int _date);

	//Metoda wyswietlajaca zawartosc skladowych name i date
	string info() const;

protected:
	//Przechowywana data
	int date;

};

#pragma once

class Visitor;

//Klasa bazowa Data, przeznaczona do dziedziczenia
class Data
{
public:

	//Domyslny konstruktor
	Data() = default;
	//Czysto wirtualna metoda obslugujaca wizytor
	virtual void acceptVisitor(Visitor& v) = 0;
	
};

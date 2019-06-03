#pragma once

class FloatData;
class IntData;

//Klasa Visitor obslugujaca rozne typy danych
class Visitor
{
public:

	//Czysto wirtualna metoda obslugujaca zmienne typu FloatData
	virtual void visit(const FloatData* obj) = 0;
	//Czysto wirtualna metoda obslugujaca zmienne typu IntData
	virtual void visit(const IntData* obj) = 0;
};


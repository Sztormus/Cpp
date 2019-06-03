#pragma once
#include "Visitor.h"

//Klasa PrintingVisitor wyswietlajaca wartosci odwiedzonych typow danych
class PrintingVisitor: public Visitor
{
public:

	//Domysny konstruktor
	PrintingVisitor() = default;
	//Metoda wyswietlajaca wartosc zmiennej IntData
	void visit(const IntData* obj);
	//Metoda wyswietlajaca wartosc zmiennej FloatData
	void visit(const FloatData* obj);

};

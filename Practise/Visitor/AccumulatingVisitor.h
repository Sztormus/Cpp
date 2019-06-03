#pragma once
#include "Visitor.h"

//Klasa AccumulatingVisitor sumujaca odwiedzone elementy
class AccumulatingVisitor: public Visitor
{
public:

	//Domyslny konstruktor
	AccumulatingVisitor() = default;
	//Metoda dodajaca wartosci zmiennych IntData do zmiennej sum
	void visit(const IntData* obj);
	//Metoda dodajaca wartosci zmiennych FloatData do zmiennej sum
	void visit(const FloatData* obj);
	//Metoda zwracajaca wartosc sumy
	float getTotalSum() const;

private:
	
	//Zmienna przechowujaca sume odwiedzonych typow danych
	float sum = 0;
};

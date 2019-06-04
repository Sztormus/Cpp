#pragma once
#include <iostream>

//Klasa StringConvertable przeznaczona do dziedziczenia
class StringConvertable
{
public:
	//Domyslny konstruktor
	StringConvertable() = default;
	//Domyslny wirtualny destruktor
	virtual ~StringConvertable() = default;
	//Czysto wirtualna metoda zwracajaca staly ciag znakow
	virtual const std::string rawString() const = 0;
};

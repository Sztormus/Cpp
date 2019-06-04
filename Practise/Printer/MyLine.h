#pragma once
#include "StringConvertable.h"
#include "AttFormat.h"
#include "AttColor.h"
#include <iostream>
#include <string>

//Klasa MyLine odpowiedzialna za przechowanie ciagu zlozonego z jednego znaku o okreslonej dlugosci
class MyLine: public StringConvertable, public AttColor
{
public:
	//Konstuktor przyjmujacy pojedynczy znak, dlugosc lancucha oraz format
	MyLine(char sign, int num, AttColor::Option opt);
	//Metoda zwracajaca stala ciag znakow
	const std::string rawString() const;
	//Metoda ustawiajaca znak do zmiennej m_sign
	void setChar(char sign);
	//Metoda ustawiajaca dlugosc lancucha znakow
	void setLength(int length);
private:
	char m_sign;
	int m_length;
};

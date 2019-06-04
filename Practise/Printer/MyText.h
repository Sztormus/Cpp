#pragma once
#include "AttFormat.h"
#include "AttColor.h"
#include "StringConvertable.h"
#include <iostream>
#include <string>

//Klasa MyText odopowiadajaca za przechowywanie ciagu znakow
class MyText: public StringConvertable, public AttFormat, public AttColor
{
public:
	//Konstruktor przyjmujacy ciag znakow, format oraz kolor przechowywanego tekstu
	MyText(std::string text, AttFormat::Option format, AttColor::Option color);
	//Metoda zwracajaca stala kopie przechowywanego tekstu
	const std::string rawString() const;
	//Metoda zapisujaca tekst do zmiennej m_text
	void setText(std::string text);

private:
	//Przechowywany tekst
	std::string m_text;
};

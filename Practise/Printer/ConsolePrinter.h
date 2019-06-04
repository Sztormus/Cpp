#pragma once

#include "StringConvertable.h"
#include "AttFormat.h"
#include "AttColor.h"

//Metoda ConsolePrinter odpowiedzialna za wyswietlanie tekstu na ekran w odpowiednim kolorze i formacie
class ConsolePrinter
{
public:
	//Konstruktor przyjmujacy dlugosc wyswietlanej linii
	ConsolePrinter(unsigned int width);
	//Metoda wyswietlajaca tekst na ekran
	void print( const StringConvertable & obj ) const;
public:	
	//Statyczna metoda zwracajaca znak "\e[0m"
	static const char * resetSeq();
	//Statyczna metoda ustawiajaca format tekstu, ktora zwraca odpowiedni znak UNICONE
	static const char * controlSeq( AttFormat::Option opt );
	//Statyczna metoda ustawiajaca kolor tekstu, ktora zwraca odpowiedni znak UNICONE
	static const char * controlSeq( AttColor::Option opt );
private:
	unsigned int m_width;
};

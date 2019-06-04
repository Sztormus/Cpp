#pragma once
#include <stdexcept>
#include <string>

//Klasa Calc_error dziedziczaca po klasie wyjatku std::runtime_error
class Calc_error: public std::runtime_error
{
public:
	//Konstuktor zapisujacy wskaznik do obiektu klasy std::runtime_error
	//nazwe bledu, nazwe pliku i numer linii, w ktorej wystapil blad
	Calc_error(std::runtime_error* _ptr, std::string _cause, std::string _name, int _number);
	//Domyslny destruktor
	~Calc_error() = default;
	//Statyczna metoda odpowiedzialna za obsluge wyjatku i zarzadzanie pamiecia
	static void handler();
private:
	std::runtime_error* ptr;
	std::string name;
	int number;
};

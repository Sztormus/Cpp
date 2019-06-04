#pragma once
#include <vector>

//Klasa Array bedaca prostym kontenerem na int
class Array
{
public:

	//Konstruktor zapisujacy rozmiar tablicy i tworzacy odpowiedni wektor
	Array(unsigned int _size): n(_size)
	{
		tab = std::vector<int>(n);
	}

	//Metoda zwracajaca rozmiar kontenera
	unsigned int size() 
	{
		return n;
	}

	//Przeladowanie operatora nawiasow kwadratowych zwrajacace referencje do danego
	//elementu kontenera
	int& operator [](int i)
	{
		return tab[i];
	}

private:

	//Rozmiar kontenera
	unsigned int n;
	
	//Wektor zmiennych typu int
	std::vector<int>tab;
};

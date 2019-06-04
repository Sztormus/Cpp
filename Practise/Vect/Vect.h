#pragma once

#include <iostream>
#include <string.h>

//Szablonowa klasa swap, do rozpoznania czy klasa do posortowania jest klasa prosta,
//wariant prosty korzysta z wydajniejszego memcpy()
//wariant skomplikowany korzysta z operatora przypisania
//Podstawowy szablon odnosi sie do klasy prostej
template<typename T, const bool p>
class Swap
{	
public:	
	static void swap(T& a, T& b)
	{
		T tmp;
		memcpy(&tmp, &a, sizeof(a));
		memcpy(&a, &b, sizeof(b));
		memcpy(&b, &tmp, sizeof(tmp));
	};
	
};
//Czesciowa specjalizacja dla szablonowej klasy swap,
//Odnoszaca sie do klasy skomplikowanej
template<typename T> class Swap<T, false>
{
public:
	static void swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
};

//Szablonowa struktura is_pod, ktora przechowuje wartosc, czy klasa jest prosta czy skomplikowana
//Wariant podstawowy odnosi sie do klasy skomplikowanej
//Dla klasy prostej powinna zostac zdefiniowana pelna specjalizacja dla wartosci pod = true
template<typename T>
struct is_pod
{
	const static bool pod = false;
};


//Szablonowa klasa Vect, bedaca prosta implementacja std::vector
template<typename T>
class Vect
{
public:
	//Konstruktor alokujacy pamiec dla podanego rozmiaru 
	Vect(int _size): t_size(_size), tab(new T[t_size])
	{

	}

	//Destruktor zwalniajacy zalokowana pamiec
	~Vect()
	{
		delete[] tab;
	}

	//Przeladowanie operatora [] w wersji const zwrajacego stala referencje do pojedynczego elementu tablicy
	const T& operator [](int index) const
	{
		return tab[index];
	}
	//Przeladowanie operatora []  zwrajacego referencje do pojedynczego elementu tablicy
	T& operator [](int index)
	{
		return tab[index];
	}

	//Metoda sortujaca tablice, ktora przyjmuje wskaznik do funkcji porownujacej elementy
	//Korzystna ona z klasy swap
	void buble_sort(bool (*fun)(const T& a, const T& b))
	{
		for (unsigned int i = 0; i < t_size; ++i)
		    for (unsigned int j = i + 1; j < t_size; ++j) 
		       if (fun(tab[i], tab[j]))
					Swap<T,is_pod<T>::pod>::swap(tab[i], tab[j]);
	}

	//Metoda size zwracajaca ilosc elementow w tablicy
	unsigned int size() const
	{
		return t_size;
	}

private:
	unsigned int t_size;
	T* tab;
};


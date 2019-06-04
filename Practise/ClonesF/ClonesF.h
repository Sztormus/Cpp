#pragma once
#include <vector>

//Pusta klasa Base przeznaczona do dziedziczenia
class Base
{
public:
	//Wirtualny domysny destruktor
	virtual ~Base() = default;
};

//Szablonowa klasa Contener bedaca przechowujaca pojedyncza wartosc dziedziczaca po Base
template<class T>
class Contener: public Base
{
public:
	//Konstruktor zapisujacy wartosc do zmiennej ptr
	Contener(const T& obj): ptr(obj)
	{}
	//Metoda zwracajaca stala referencje do przechowywanej wartosci
	const T& Copy() const
	{
		return ptr;
	}	

private:
	T ptr;
};

//Pusta klasa szablonowa missing
template <class T>
class missing
{
};

//Klasa ClonesF bedaca wektorem wskaznikow na elementy klasy Base
class ClonesF
{
public:
	//Konstruktor
	ClonesF()
	{
		tab = std::vector<Base*>(); 
	}
	//Destruktor zwalniajacy pamiec
	~ClonesF()
	{
		for(unsigned int i = 0; i < tab.size(); ++i)
			delete tab[i];
	}
	//Szablonowa metoda dodajaca nowy element do wektora
	template <class T>
	void add(const T& obj)
	{
		Contener<T> *cont = new Contener<T>(obj);
		tab.push_back(cont);
	}
	//Szablonowa metoda zwracajaca stala referencje do elementu o podanym przez nas typie w parametrze szablonu
	//Jezeli szukany przez nas typ nie wystepuje w wektorze to rzucany jest wyjatek
	template <class T>
	const T& clone() const
	{
		for(unsigned int i = 0; i < tab.size(); ++i)
		{
			if(dynamic_cast<const Contener<T>*>(tab[i]))
			{
				const Contener<T>* obj = dynamic_cast<const Contener<T>*>(tab[i]);
				return obj->Copy();
			}
		}

		throw missing<T>();
	}

private:
	std::vector<Base*> tab;
};


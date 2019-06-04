#pragma once
#include <ostream>

//Szablonowa klasa DynArray bedaca dynamiecznie alokowanym pojemnikiem na dane
template <class T>
class DynArray
{
public:
	//Wewnetrzna klasa Iterator przechowujaca wskaznik na pojedynczy element tablicy
	class Iterator
	{
	public:
		//Konstuktor ustawiajacy wskaznik na element tablicy
		Iterator(T* _ptr);
		//Domyslny destruktor
		~Iterator() = default;
		//Przeladowanie operatora * zwracajace referencje do wskazywanego elementu
		T& operator *();
		//Przeladownie operatora -> zwracajace przechowywany wskaznik
		T* operator ->();
		//Przeladowanie operatora =! sprawdzajace czy dwa obiekty klasy Iterator sa rozne
		bool operator != (Iterator iter) const;
		//Przeladowy operator preinkrementacji przesuwajacy wskaznik na kolejny element tablicy
		Iterator& operator++();
	private:
		T* ptr;
	};

	//Konstruktor alokujacy pamiec na _size elementow
	DynArray(const int _size);
	//Konstruktor alokujacy pamiec na _size elementow i kopiujacy dane z tablicy tab do tablicy wewnatrz obiektu
	DynArray(const int _size, const T* _tab);
	//Konstrukor kopiujacy
	DynArray(const DynArray& obj);
	//Desktruktor zwalniajacy zaalokowana pamiec
	~DynArray();

	//Metoda zwracajaca rozmiar tablicy
	int size() const;
	//Metoda zwracajaca obkiekt klasy Iterator, ktory wskazujuje na pierwszy element tablicy
	Iterator begin();
	//Metoda zwracajaca obiekt klasy Iterator, ktory wskazuje na element znajdujacy sie zaraz za tablica
	Iterator end();

	//Dwa przeladowania operatora [] w wersji stalej i niestalej
	//Kazde z nich zwraca referencje do pojedycznego elementu tablicy
	const T& operator[](int index) const;
	T& operator[](int index);
private:
	int number;
	T* tab;
};

template <class T>
DynArray<T>::DynArray(const int _number): number(_number)
{
	tab = new T[number];
}

template <class T>
DynArray<T>::DynArray(const int _number, const T* _tab): number(_number)
{
	tab = new T[number];
	for(int i = 0; i < number; ++i)
		tab[i] = _tab[i];
}

template <class T>
DynArray<T>::DynArray(const DynArray& obj)
{
	number = obj.size();
	tab = new T[obj.size()];
	for(int i = 0; i < obj.size(); i++)
		tab[i] = obj[i];
}

template <class T>
DynArray<T>::~DynArray()
{
	delete[] tab;
}

template <class T>
int DynArray<T>::size() const
{
	return number;
}

template <class T>
typename DynArray<T>::Iterator DynArray<T>::begin()
{
	DynArray<T>::Iterator obj(&tab[0]);
	return obj;
}

template <class T>
typename DynArray<T>::Iterator DynArray<T>::end()
{
	DynArray<T>::Iterator obj(&tab[number]);
	return obj;
}

template <class T>
const T& DynArray<T>::operator[](int index) const
{
	return tab[index];
}

template <class T>
T& DynArray<T>::operator[](int index)
{
	return tab[index];
}

template <class T>
std::ostream& operator <<(std::ostream& os, const DynArray<T>& obj)
{
	os << "{";
	for(int i = 0; i < obj.size() - 1; ++i)
		os << "\"" << obj[i] << "\",";
	return os << "\"" << obj[obj.size() - 1] << "\"}" << std::endl;
}

template <class T>
DynArray<T>::Iterator::Iterator(T* _ptr): ptr(_ptr)
{}

template <class T>
T& DynArray<T>::Iterator::operator *()
{
	return *ptr;
}

template <class T>
T* DynArray<T>::Iterator::operator ->()
{
	return ptr;
}

template <class T>
bool DynArray<T>::Iterator::operator != (Iterator iter) const
{
	if(iter.ptr != ptr)
		return true;
	else
		return false;
}

template <class T>
typename DynArray<T>::Iterator& DynArray<T>::Iterator::operator++()
{
	++ptr;
	return *this;
}



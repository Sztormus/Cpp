#pragma once
#include <ostream>

class MyString
{	
	//Przeciazenie operatora strumienia pozwalajace wyswietlic zawartosc zmiennej tab
	friend std::ostream& operator <<(std::ostream& os, const MyString& obj);

	//Przeciazenie operatora * pozwalajace na powielanie obecnego napisu
	//n razy (kolejnosc n * obiekt)
	friend MyString operator *(int n, const MyString& obj);

public:
	//Konstruktor alokujacy pamiec i kopiujacy napis do zmiennej tab oraz dlugosc napisu do zmiennej length
	MyString(const char* napis);

	//Destruktor zwalniajacy pamiec
	~MyString();

	//Metoda wyswietlajaca zawarto zmiennej tab
	void Print() const;

	//Przeciazenie operatora + pozwalajace dodawac dwa obiekty tej klasy i zwracajace nowy obiekt
	MyString operator +(const MyString& obj) const;

	//Przeciazenie operatora + pozwalajace dodawac do obiektu pojedynczy znak c i zwracajace nowy obiekt
	MyString operator +(const char c) const;

	//Przeciazenie operatora * pozwalajace na powielanie obecnego napisu
	//n razy (kolejnosc obiekt * n)
	MyString operator *(int n) const;

	//Przeciazenie operatora = pozwalace na skopiowanie zawartosci jednego obiektu do drugiego
	void operator =(const MyString& obj);

	//Przeciazenie operatora == pozwalajace porownac czy dwa obiekty sa takie same
	bool operator ==(const MyString& obj) const;

	//Przeciazenie operatora [] pozwalajace odczytac pojedynczy znak zmiennej tab
	char& operator [](int n) const;

private:
	//Prywatny pusty konstruktor
	MyString();

	//Tablica przechowowujaca lancuch znakow
	char *tab;

	//Zmienna przechowujaca dlugosc lancucha znakow
	int length;
};

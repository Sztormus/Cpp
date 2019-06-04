#pragma once
#include "NumerId.h"
#include <ostream>

//Klasa Osoba przechowujaca imie osoby, przeznaczona do dziedziczenia po niej
class Osoba
{
public:
	//Konstuktor domyslny
	Osoba() = default;

	//Konstruktor zapisujacy imie osoby
	Osoba(std::string _name);

	//Wirtualny domyslny destruktor
	virtual ~Osoba() = default;

	//Przeciazenie operatora strumienia pozwalajace na wyswietlenie imienua osoby i jej statusu
	friend std::ostream& operator << (std::ostream& os, const Osoba& obj);
private:
	//Czysto wirtualna prywatna metoda zwracajaca status osoby
	virtual const std::string GetStatus() const = 0 ;
	
	//Zmienna przechowujaca nazwe osoby
	std::string name;
};

//Klasa Pracownik sluzoca do dziedziczenia po niej
class Pracownik: public virtual Osoba
{
public:
	
	//Domyslny konstruktor
	Pracownik() = default;
	
	//Domyslny destruktor
	~Pracownik() = default;
};

//Klasa Student zawierajaca imie i indeks studenta
class Student: public virtual Osoba
{
public:
	//Kontruktor zapisujacy imie i indeks studenta
	Student(std::string name, NumerId id);

	//Domyslny dekstruktor
	~Student() = default;
	
	//Metoda zwracajaca stala referencje do indeksu studenta
	const NumerId& numId() const;

private:
	//Prywatna metoda zwracajaca napis " - student"
	const std::string GetStatus() const;

	//Numer indeksu
	NumerId index;
};

//Klasa Dydaktyk zawierajaca imie i indeks dydaktyka
class Dydaktyk: public Pracownik
{
public:
	//Kostruktor zapisujacy imie i indeks studenta
	Dydaktyk(std::string name, NumerId id);

	//Domyslny destruktor
	~Dydaktyk() = default;

	//Metoda zwracajaca stala referencje do indeksu dydaktyka
	const NumerId& numId() const;

private:
	//Prywatna metoda zwracajaca napis " - dydaktyk"
	const std::string GetStatus() const;
	
	//Indeks dydaktyka
	NumerId index;
};

//Klasa Wozny przechowujaca imie woznego
class Wozny: public Pracownik
{
public:
	//Konstruktor zapisujacy imie woznego
	Wozny(std::string name);
	
	//Destruktor domyslny woznego
	~Wozny() = default;
private:
	//Prywatna metoda zwracajaca napis " - wozny"
	const std::string GetStatus() const;
};

//Klasa Doktorant przechowujaca imie doktoranta i jego dwa indeksy: jako studenta i jako dydaktyka
class Doktorant: public Student, public Dydaktyk
{
public:
	//Konsruktor zapisujacy imie i indeksy doktoranta
	Doktorant(std::string name, NumerId id_dydaktyk, NumerId id_student);
	
	//Domyslny destruktor
	~Doktorant() = default;

	//Metoda zwracajaca stala referencje do indeksu doktoranta jako studenta
	const NumerId& numId_uczen() const;

	//Metoda zwracajaca stala referencje do indeksu doktoranta jako dydaktyka
	const NumerId& numId_nauczyciel() const;
private:
	//Prywatna metoda zwracajaca napis " - doktorant"
	const std::string GetStatus() const;
};



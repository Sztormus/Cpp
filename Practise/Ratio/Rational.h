#pragma once

//Definicja klasy zawierajacej liczbe wymierna postaci licznik/mianownik
class Rational
{
public:

	//Konstruktor dwuargumentowy tworzacy obiekt Rational
	//i uniemozliwiajacy konwersje niejawne 
	explicit Rational(int n1, int n2 = 1);

	//Metoda wyswietlajaca liczbe wymierna w postaci ulamka
	void Print() const;

	//Przeciazenie operatora "-" zwracajace liczbe przeciwna do aktualnego ulamka
	Rational operator -() const;

	//Przeciazenie operatora "+" zwracajace sume dwoch liczb wymiernych w postaci ulamka
	Rational operator +(const Rational a) const;

	//Przeciazanie operatora "-" zwracajace roznice dwoch liczb wymniernych w postaci ulamka
	Rational operator -(const Rational a) const;

	//Przeciazanie operatora "*" zwracajae iloczyn dwoch liczb wymiernych w postaci ulamka
	Rational operator *(const Rational a) const;

	//Przeciazenie typu "double" pozwalajace na zwrocenie wyniku dzielenia licznik przez mianownik
	//i uniemozliwajace niejawne konwersje
	explicit operator double() const;

private:

	//Deklaracje zmiennych
	int licznik;
	int mianownik;

	//Prywatna metoda zwracajaca najwiekszy wspolny dzielnik licznika i mianownika
	int NWD(int n1, int n2) const;
};

#pragma once

class EasyTab
{
private:
	int id_first;
	int id_last;
	int length;
	double *tab;

public:

	//Konstruktor tworzacy dynamiczna tablice o zakresie n2 - n1
	EasyTab(int n1, int n2);

	//Konstruktor kopiujacy, ktory tworzy obiekt w oparciu o obiekt podany w parametrze konstruktora
	EasyTab(const EasyTab &t);

	//Konstruktor kopiujacy, ktory tworzy obiekt kopiujac fragment obiektu podanego w parametrze konstruktora o zakresie n2 - n1
	EasyTab(const EasyTab &t, int n1, int n2);

	//Destruktor zwalniajacy pamiec
	~EasyTab();

	//Metoda wypelniajaca tablice za pomoca liczby zawartej w parametrze metody
	void setAll(double number) const;

	//Metoda pozwalajaca odczytac zawartosc tablicy o indeksie zawartym w parametrze metody
	double &at(int index) const;

	//Metoda sprawdzajaca czy podany indeks jest zgodny z zakresem tablicy
	bool inRange(int index);

	//Metoda wyswietlajaca tablice zawarta w obiekcie podanym jako parametr metody
	static void print(const EasyTab &t);
};

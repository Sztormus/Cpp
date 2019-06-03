#pragma once

//Klasa LittleThing bedaca dynamiczna tablica na wartosci typu int
class LittleThing
{
public:
	//Konstruktor przypisujacy domyslna wartosc rowna zero
	LittleThing();
	//Konstruktor przypisujacy wartosc podana w argumenice
	LittleThing(int _value);
	//Destruktor dbajacy o zwolnienie pamieci
	~LittleThing();
	//Metoda zwrajaca referencje do przechowywanej wartosci
	int& Value();
	//Przeladowanie operatora new wyswietlajace komunikat na ekran i rezerwujace pamiec
	static void* operator new(long unsigned int size);
	//Przeladowanie operatora new[] wyswietlajace komunikat na ekran i rezerwujace pamiec
	static void* operator new[](long unsigned int size);
	//Przeladowanie operatora delete wyswietlajace komunikat i zwalniajace pamiec
	static void operator delete(void* ptr, long unsigned int size);
	//Przeladowanie operatora delete[] wyswietlajace komunikat i zwalniajace pamiec
	static void operator delete[](void* ptr, long unsigned int size);

private:
	//Przechowywana wartosc
	int value;
	//Statyczna tablica obiektow wspolna dla kazdego obiektu
	static LittleThing* tab;
	//Flaga pilnujaca o zaalokowanie odpowiedniej ilosci pamieci
	static bool flag;
	//Licznik
	static int n;
};

//Klasa LittleThingCleaner bedace wskaznikiem na pojedynczy element klasy Malensto
class LittleThingCleaner
{
public:
	//Konstruktor przypisujacy do wskaznika obiekt klasy LittleThing
	LittleThingCleaner(LittleThing* obj);
	//Desktruktor zwalniajacy obiekt, na ktory wskazuje
	~LittleThingCleaner();
	//Przeciazenie operatora -> w wersji const zwracajace staly wskaznik na klase LittleThing
	const LittleThing* operator ->() const;
	//Przeciazenie operatora -> zwracajace wskaznik na klase LittleThing
	LittleThing* operator ->();
	
private:
	//Wskaznik na klase LittleThing
	LittleThing* ptr;
};

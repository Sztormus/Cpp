#pragma once

//Szablonowa klasa pomocnicza Calculation sluzaca do liczenia potegi zawieracja
//publiczna statyczna zmienna ktora przechowuje wynik obliczen
//B - podstawa potegi
//E - wykladnik
//NEG - znak wykladnika (true gdy ujemny)
//GR10 - flaga pilnujaca czy wykladnik nie jest wiekszy od 10 i mniejszy od -10
template<int B, int E, bool NEG, bool GR10> 
class Calculation
{
public:
	static const double value;
};

//Obliczanie wartosci zmiennej w czasie kompilacji z wykorzystaniem 
//klasy, ktorej wykladnik wynosi E - 1 (rekurencja)
template<int B, int E, bool NEG, bool GR10>
const double Calculation<B, E, NEG, GR10>::value = B * Calculation<B, E - 1, NEG, GR10>::value;

//Specjalizacja szablonu klasy Calculation dla wykladnika wiekszego od 10 lub mniejszego od -10
template<int B, int E, bool NEG> 
class Calculation<B, E, NEG, true>
{
public:
	static const double value;
};

//Przypisanie zmiennej value lanucha znaku w celu spowodowania bledu kompilacji
template<int B, int E, bool NEG>
const double Calculation<B, E, NEG, true>::value = "haha";

//Specjalizacja szablonu klasy Calculation dla wykladnika mniejszego od zera
template<int B, int E> 
class Calculation<B, E, true, false>
{
public:
	static const double value;
};

//Obliczanie wartosci zmiennej w czasie kompilacji dla ujemnego wykladnika z wykorzystaniem 
//klasy, ktorej wykladnik wynosi E - 1 (rekurencja)
template<int B, int E>
const double Calculation<B, E, true, false>::value = (1.0/B) * Calculation<B, E + 1, true, false>::value;

//Specjalizacja szablonu klasy Calculation dla wykladnika rownego zero i flagi znaku ustawionej na false
template<int B> 
class Calculation<B, 0, false, false>
{
public:
	static const double value;
};

//Warunek brzegowy, ustawienie zmiennej value wartosci rownej 1.0
template<int B>
const double Calculation<B, 0, false, false>::value = 1.0;

//Specjalizacja szablonu klasy Calculation dla wykladnika rownego zero i flagi znaku ustawionej na true
template<int B> 
class Calculation<B, 0, true, false>
{
public:
	static const double value;
};

//Warunek brzegowy, ustawienie zmiennej value wartosci rownej 1.0
template<int B>
const double Calculation<B, 0, true, false>::value = 1.0;

//Szablonowa klasa Power, bedaca glowna klasa do liczenia potegi z wykorzystaniem
//szablonowej klasy Calculation
//B - podstawa potegi
//E - wykladnik potegi
template <int B, int E>
class Power
{
public:
	static const double value;
};

//Przypisanie zmiennej value wartosci zmiennej value z szablonowej klasy Calculation, ktora
//przejmuje podstawe i wykladnik potegi do obliczenia szukanej przez nas liczby
template<int B, int E>
const double Power<B, E>::value = Calculation<B, E, E < 0, (E > 10) || (E < -10)>::value;


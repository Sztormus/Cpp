/* 
 * Zadanie: Ciagi
 * 
 * Panstwa zadaniem jest napisanie prostego zestawu funkcji, 
 * do obslugi ciagow geometrycznych: tworzenie i wypisywanie, a takze
 * badanie wlasnosci przy pomocy funkcji pomocniczych.
 * 
 * Funkcja znakCiagu zwraca '+', gdy wszystkie wyrazy sa dodatnie,
 * '-' gdy wszystkie sa ujemne, '0' gdy wyrazy sa raz dodatnie, raz ujemne.
 * 
 * Celem zadania jest przypomnienie sobie operacji na wskaznikach 
 * (prosze zadbac o zarzadzanie pamiecia) oraz typach. 
 * 
 * Standardowe wymagania:
 * - main.cpp nie powinien byc modyfikowany;
 * - wynik dzialania programu powinien zgadzac sie z podanym na koncu
 *   tego pliku;
 * - kompilujemy z flagami: -Wall -g
 * - sprawdzamy wycieki pamieci (np programem valgrind)
 * - nalezy przygotowac makefile, generujacy jeden plik wykonywalny (!) 
 *   test i posiadajacy cel "clean" ktory posprzata po pracy;
 * - napisany kod powinien byc przyjemny dla programisty, czytelny,
 *   praktyczny, dobrze zorganizowany, bez zbednych fragmentow;
 * - prosze pamietac o dokumentowaniu kodu.
 * - zadanie mozna zrobic tylko przy pomocy c, ale uzywanie c++, c++11, 
 *   bibliotek standardowych jest dozwolone (ale bez uzywania dokumentacji)
 * - nie korzystamy z notatek/internetu/pracy kolegow lub kolezanek;
 * - zadanie wysylamy na UPEL, w formie archiwum:
 *   [] tar -czvf arch_name.tar.gz dir_name
*/

#include "ciagi.h"
#include "ciagi.h"

#include <stdio.h>

int main()
{	
	const TypWrazowCiagu pierwszy = 1.0;
	const DlugoscCiagu rozmiar = 5;
	const TypWrazowCiagu iloraz1 = 2.0;
		
	printf("Utworzone ciagi:\n");
	const Ciag geo1 = utworzCiag( pierwszy, rozmiar, iloraz1 );
	wypiszCiag( geo1, rozmiar );
	
	const TypWrazowCiagu iloraz2 = -2.5;
	const Ciag geo2 = utworzCiag( pierwszy, rozmiar, iloraz2 );
	wypiszCiag( geo2, rozmiar );
	
	TypWrazowCiagu s1 = sumaLiczb( geo1, rozmiar );
	TypWrazowCiagu s2 = sumaLiczb( geo2, rozmiar );
	printf("Suma ciagu geo1: %.2f; geo2: %.2f\n", s1, s2);
	
	Funkcja funTab[] = { sumaLiczb, iloczynLiczb, maximumLiczb, minimumLiczb };
	const int ileFunkcji = sizeof(funTab)/sizeof(Funkcja);
	
	printf("Dzialanie funkcji na elementach ciagu geo1:\n");
	for (int i = 0; i < ileFunkcji; ++i)
		wykonajIWypisz( funTab[i], geo1, rozmiar);

	char zn1 = znakCiagu( geo1, rozmiar );
	char zn2 = znakCiagu( geo2, rozmiar );
	printf("Znak ciagu geo1: %c; geo2: %c\n", zn1, zn2);

	zniszczCiag( &geo1 );
	zniszczCiag( &geo2 );	
	
	return 0;
}

/* Wynik dzialania programu:
Utworzone ciagi:
	1	2	4	8	16
	1	-2	6	-16	39
Suma ciagu geo1: 31.00; geo2: 28.19
Dzialanie funkcji na elementach ciagu geo1:
 suma = 31
 iloczyn = 1024
 max = 16
 min = 1
Znak ciagu geo1: +; geo2: 0
*/

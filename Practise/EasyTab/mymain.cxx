/*
Celem zadania jest implementacja  klasy funkcjonujacej jak 
tablica jednowymiarowa typu double indeksowana w dowolnym zakresie 
(np. ujemnymi indeksami).

Podczas konstrukcji tablica ta ma pozwalac na wyszczegolnienie 
dolnego i gornego indeksu. Mozliwe powinny byc inne konstruktory, 
w tym pobierajace inna tablice jak i fragment innej tablicy.

FlexiTab ma posidac metody zwracajacy minimalny i maksymalny+1 indeks 
a takze rozmiar. I proste roszezenie, metoda sprawdzajaca czy indeks 
jest w zakresie.

W zadaniu nie można używać kontenerów z biblioteki standardowej (pamięć
należy alokować dynamicznie).
*/

#include "EasyTab.h"
#include "EasyTab.h"

#include <iostream>
#include <iomanip>

int main() {
	EasyTab baseTab(-8, 4);
	baseTab.setAll(0);  
	baseTab.at(-5) += 2.3;
	baseTab.at(-6) += 7.2;
	baseTab.at(3) += 3.89;  
			
	const EasyTab copyOne(baseTab);
	std::cout << "Kopia tablicy    => ";
	EasyTab::print(copyOne);
	std::cout << std::endl << std::endl;

	std::cout << "Fragment tablicy => ";
	const EasyTab copyTwo(copyOne, -5, 4);
	EasyTab::print(copyTwo);
	std::cout << std::endl << std::endl;
	
	std::cout << "Element tablicy  => baseTab[0] = ";
	baseTab.at(0) = baseTab.at(-5) + copyTwo.at(3);
	std::cout << baseTab.at(0) << std::endl << std::endl;
	
	std::cout << "Czy indeks -8 jest dobry: " << std::boolalpha << baseTab.inRange(-8) << std::endl;
	std::cout << "Czy indeks -1 jest dobry: " << std::boolalpha << baseTab.inRange(-4) << std::endl;
	std::cout << "Czy indeks +4 jest dobry: " << std::boolalpha << baseTab.inRange(+4) << std::endl;
}

/* Output:
Kopia tablicy    => -8:0 -7:0 -6:7.2 -5:2.3 -4:0 -3:0 -2:0 -1:0 0:0 1:0 2:0 3:3.89 

Fragment tablicy => -5:2.3 -4:0 -3:0 -2:0 -1:0 0:0 1:0 2:0 3:3.89 

Element tablicy  => baseTab[0] = 6.19

Czy indeks -8 jest dobry: true
Czy indeks -1 jest dobry: true
Czy indeks +4 jest dobry: false
*/

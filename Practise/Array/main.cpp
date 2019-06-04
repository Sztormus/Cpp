/* 
 * Celem zadania jest napisanie funkcji sortujacej (bubble sort):

	for(int i = 0; i < N; ++i)
		for(int j = i+1; j < N; ++j) 
			if( tab[i] > tab[j])
				std::swap(tab[i], tab[j]) 
				
 * Dodatkowo potrzebna jest funkcja print, ktora wyswietli kontener.
 * 
 * Szablon print jest przeladowany: tj trzeba napisac szablon, ktory 
 * przyjmie jeden argument (przez referencje), ale rozpozna rozmiar tablicy 
 * statycznej (wskazowka: rozmiar tablicy statycznej jest czescia jej typu) 
 * lub uzyje funkcji size() kontenera. 
 * 
 * Klasa Array ma byc prostym kontenerem na typ int (mozna uzyc std::vector),
 * z operatorem []. Jezeli zadbamy o przesylanie przez referencje, to nie 
 * trzeba definiowac konstruktora kopiujacego. 
*/

#include "Array.h"
#include "TemFun.h"
#include <iostream>

int main()
{

	const int tab_size = 5;
	double arrayDouble[tab_size];
	int arrayInt[] = {2,7,5,4,9};
	Array a(tab_size);
	std::string text = "poiuytrewq";

	for (int i = 0; i < tab_size; ++i)
	{
		arrayDouble[i] = 1-0.5*i*i;
		a[i] = 6-i;
	}

	std::cout << "Disordered" << std::endl;
    num::print( arrayDouble, tab_size );
	num::print( arrayInt, tab_size );
	num::print( a, a.size() );
	num::print( text, text.size() );

	num::bubble_sort( arrayDouble, tab_size );
	num::bubble_sort( arrayInt, tab_size );
	num::bubble_sort( a, a.size() );
	num::bubble_sort( text, text.size() );
	
	std::cout << "Sorted" << std::endl;
    num::print( arrayDouble );
	num::print( arrayInt );
	num::print( a );
	num::print( text );
	
	// Tak dla sprawdzenia
	std::cout << "\nTest primes" << std::endl;
	const bool f2t5 = num::all_primes<2, 5>(arrayInt); // wszystkie miedzy indeksami [2, 5)
	const bool f2t4 = num::all_primes<2, 4>(arrayInt); // wszystkie miedzy indeksami [2, 4)
	std::cout << "<2,5) = " << std::boolalpha << f2t5 << std::endl;
	std::cout << "<2,4) = " << std::boolalpha << f2t4 << std::endl;

	return 0;
}
/* output:
Disordered
1, 0.5, -1, -3.5, -7
2, 7, 5, 4, 9
6, 5, 4, 3, 2
p, o, i, u, y, t, r, e, w, q
Sorted
-7, -3.5, -1, 0.5, 1
2, 4, 5, 7, 9
2, 3, 4, 5, 6
e, i, o, p, q, r, t, u, w, y

Test primes
<2,5) = false
<2,4) = true
*/

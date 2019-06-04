#pragma once
#include <iostream>

namespace num
{
	//Szablon funkcji sortujacej przyjmujacej kontener elementow typu T i rozmiar konteneru
	template <typename T>
	void bubble_sort(T& tab, unsigned int number)
	{
		for(unsigned int i = 0; i < number; ++i)
			for(unsigned int j = i+1; j < number; ++j) 
				if(tab[i] > tab[j])
					std::swap(tab[i], tab[j]);
	}

	//Szablon funkcji wypisujacej zawartosc kontenera elementow typu T,
	//przyjmujcej referencje i rozmiar
	template <typename T>
	void print(T& tab, unsigned int n)
	{
		for(unsigned int i = 0; i < n; ++i)
			std::cout << tab[i] << ", ";
		std::cout << std::endl;
	}
	
	//Szablon funkcji wypisujacej zawartosc kontenera elementow typu T,
	//przyjmujcej referencje
	template <typename T>
	void print(T& tab)
	{
		for(unsigned int i = 0; i < tab.size(); ++i)
			std::cout << tab[i] << ", ";
		std::cout << std::endl;
	}

	//Szablon funkcji wypisujacej zawartosc kontenera elementow typu T,
	//przyjmujcej referencje i rozmiar
	template <typename T, int size>
	void print(T (& tab)[size])
	{
		for(unsigned int i = 0; i < size; ++i)
			std::cout << tab[i] << ", ";
		std::cout << std::endl;
	}

	//Szablon funkcji sprawdzajacej czy w podanym zakresie od a do b kontenera znajduja sie tylko liczby pierwsze 
	template <int a, int b>
	bool all_primes(int* tab)
	{
		for(int i = a; i < b; i++)
		{
			for(int k = 2; k * k <= tab[i]; k++)
			{
				if(tab[i]%k == 0)
					return false;
			}
		}

		return true;
	}
}

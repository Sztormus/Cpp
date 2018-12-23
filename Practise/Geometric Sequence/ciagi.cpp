#include "ciagi.h"
#include <iostream>
#include <iomanip>

using namespace std;

int wywolanie = 1;

void wypiszCiag(Ciag a, DlugoscCiagu n)
{
	for(int i = 0; i < n; i++)
		cout << "	" << a[i];
	cout << endl;
}
void zniszczCiag(const Ciag *tab)
{
	delete[](*tab);
}
Ciag utworzCiag(TypWrazowCiagu a, DlugoscCiagu n, TypWrazowCiagu q)
{
	Ciag tab = new TypWrazowCiagu[n];
	tab[0] = a;
	for(int i = 1; i < n; i++)
		tab[i] = tab[i-1] * q;
	return tab;
}
TypWrazowCiagu sumaLiczb(Ciag a, DlugoscCiagu n)
{
	TypWrazowCiagu suma = 0;
	for(int i = 0; i < n; i++)
		suma += a[i];
	return suma;
}
TypWrazowCiagu iloczynLiczb(Ciag a, DlugoscCiagu n)
{
	TypWrazowCiagu iloczyn = 1;
	for(int i = 0; i < n; i++)
		iloczyn *= a[i];
	return iloczyn;
}
char znakCiagu(Ciag a, DlugoscCiagu n)
{
	if(a[0] > 0)
	{
		int i = 1;
		for(i; i < n; i++)
		{
			if(a[i] < 0)
				return '0';
		}
		if(i == n)
			return '+';
	}
	else
	{
		int i = 1;
		for(i; i < n; i++)
		{
			if(a[i] > 0)
				return '0';
		}
		if(i == n)
			return '-';
	}
}
TypWrazowCiagu minimumLiczb(Ciag a, DlugoscCiagu n)
{
	TypWrazowCiagu min = a[0];
	for(int i = 1; i < n; i++)
	{
		if(min > a[i])
			min = a[i];
	}
	return min;
}
TypWrazowCiagu maximumLiczb(Ciag a, DlugoscCiagu n)
{
	TypWrazowCiagu max = a[0];
	for(int i = 1; i < n; i++)
	{
		if(max < a[i])
			max = a[i];
	}
	return max;
}
void wykonajIWypisz(Funkcja tab, Ciag a, DlugoscCiagu n)
{

	switch(wywolanie)
	{
		case 1:
			{
				cout << " Suma = " << tab(a,n) << endl;
				wywolanie++;
				break;
			}
		case 2:
			{
				cout << " Iloczyn = " << tab(a,n) << endl;
				wywolanie++;
				break;
			}
		case 3:
			{
				cout << " Min = " << tab(a,n) << endl;
				wywolanie++;
				break;
			}
		case 4:
			{
				cout << " Max = " << tab(a,n) << endl;
				wywolanie++;
				break;
			}
	}
	
}



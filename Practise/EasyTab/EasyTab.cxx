#include <iostream>
#include "EasyTab.h"

using namespace std;

EasyTab::EasyTab(int n1, int n2): id_first(n1), id_last(n2), length(n2 - n1), tab(new double[length]){}


EasyTab::EasyTab(const EasyTab &t): id_first(t.id_first), id_last(t.id_last), length(t.length), tab(new double[t.length])
{
	for(int i = 0; i < t.length; i++)
		tab[i] = t.tab[i];
}


EasyTab::EasyTab(const EasyTab &t, int n1, int n2): id_first(n1), id_last(n2), length(n2 - n1), tab(new double[length])
{
	for(int i = 0; i < length; i++)
		tab[i] = t.tab[i + id_first - t.id_first];
}


EasyTab::~EasyTab()
{
	delete []tab;
}


void EasyTab::setAll(double number) const
{
	for(int i = 0; i < length; i++)
		tab[i] = number;
}


double &EasyTab::at(int index) const
{
	return tab[index - id_first];
}


bool EasyTab::inRange(int index)
{
	return (index >= id_first && index < id_last) ? 1 : 0;
}


void EasyTab::print(const EasyTab &t)
{
	for(int i = 0; i < t.length; i++)
		cout << t.id_first + i << ":" << t.tab[i] << " ";
	cout << endl;
}

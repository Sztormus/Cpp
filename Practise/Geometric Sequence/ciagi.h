#ifndef CIAGI_H
#define CIAGI_H

//Deklaracja typow
typedef double TypWrazowCiagu;
typedef int DlugoscCiagu;
typedef TypWrazowCiagu *Ciag;
typedef TypWrazowCiagu (*Funkcja)(Ciag, DlugoscCiagu);

//Procedura wypisujaca ciag a na o dlugosci n na ekran
void wypiszCiag(Ciag a, DlugoscCiagu n);

//Procedura usuwajaca ciag tab
void zniszczCiag(const Ciag *tab);

//Funkcja tworzaca ciag geometryczny o typie wyrazow a, dlugosci n 
//i iloczynowi q
Ciag utworzCiag(TypWrazowCiagu a, DlugoscCiagu n, TypWrazowCiagu q);

//Funkcja zwracajaca sume liczb ciagu a
TypWrazowCiagu sumaLiczb(Ciag a, DlugoscCiagu n);

//Funkcja zwracajaca iloczyn wyrazow ciagu a
TypWrazowCiagu iloczynLiczb(Ciag a, DlugoscCiagu n);

//Funkcja zwrajaca + gdy wszystkie wyrazy sa dodatnie, - gdy wszystkie sa ujemne
//i 0 gdy jest to ciag naprzemienny
char znakCiagu(Ciag a, DlugoscCiagu n);

//Funkcja zwracajaca najmniejsza liczbe z ciagu a
TypWrazowCiagu minimumLiczb(Ciag a, DlugoscCiagu n);

//Funkcja zwracaja najwieksza liczbe z ciagu a
TypWrazowCiagu maximumLiczb(Ciag a, DlugoscCiagu n);

//Funkcja wykonujaca operacje zawarte w tablicy funkcji tab
//na ciagu a i zwraca ich wynik na ekran
void wykonajIWypisz(Funkcja tab, Ciag a, DlugoscCiagu n);
#endif

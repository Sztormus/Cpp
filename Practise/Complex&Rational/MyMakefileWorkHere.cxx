// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac klasy Rational, Complex reprezentujace 
// odpowiednio liczby wymierne (licznik/mianownik) oraz zespolone (Re, Im).
// Dodatkowo, proszę zaimplementować metody, funkcje działające na liczbach typu Complex.
// Metody te mogą być zaimplementowane w ramach klasy Fun:
// Jesli dane są dwie liczby zespolone, w postaci kanonicznej:
// a+ib oraz c+id, to odpowiednie dzialania:
// * Add(...) dodawanie liczb zespolonych: (a + c) + i(b + d) 
// * Multiply(...) mnozenie liczb zespolonych: (a*c - b*d) + i(a*d + b*c) 
// * Modulo(...) modul liczby zespolonej: sqrt(a*a + b*b) 

// Pliku MyMakefileWorkHere.cpp nie wolno modyfikowac. Nie można zmieniać
// jego nazwy ani rozszerzenia.


#include "MyMakefileWorkHere.hxx"
#include <iostream>


int main() {

  Rational r(1,2);
  r.Print();

  Complex a(1,5);
  a.Print();
  double aRe = double(a); // przypisanie czesci rzeczywistej
  std::cout << "Re(a) = " << aRe <<std::endl;
  std::cout << "Im(a) = " << a.Im() <<std::endl;
  std::cout << "  |a| = " << Fun::Modulo(a) <<std::endl;

  Complex b(4);
  b.Print();

  Complex c = Fun::Add(a,b);
  c.Print();
  
  Complex d(Fun::Multiply(Fun::Add(a,6),r));   
  d.Print();

  return 0;
}
/** Wynik dzialania programu:
1/2
1+5i
Re(a) = 1
Im(a) = 5
  |a| = 5.09902
4
5+5i
3.5+2.5i
*/

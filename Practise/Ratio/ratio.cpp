// Prosze napisac klase Rational reprezentujacą liczby wymierne (licznik/mianownik).
// Dodatkowo, proszę zaimplementować operacje na liczbach typu Rational:
// + dodawanie, * mnożenie, - zmiana znaku (jednoargumentowy).
// Minimalnym kosztem nalezy dodac operator - odejmowanie dwoch liczb
// Skracanie ulamkow jest zalecane ale nie jest najwazniejsza czescia zadania.

#include "Rational.h"

#include <iostream>
#include <cmath>

int main() {
  
  const Rational a(1, 2);
  std::cout<<"a = ";
  a.Print();

  #ifdef ERROR_CTOR
    // ta linijka ma generować error
    const Rational bb = 2;
  #endif 
  
  const Rational b(2);
  std::cout<<"b = ";
  b.Print();

  const Rational c(2, -3);
  std::cout<<"c = ";
  c.Print();

  Rational d = a + b + c;
  std::cout<<"a+b+c = ";
  d.Print();

  Rational m = -c;
  std::cout<<"-c = "; 
  m.Print(); 

  Rational e = a - c;
  std::cout<<"a-c = "; 
  e.Print(); 

  Rational f = a * c;
  std::cout<<"a*c = ";
  f.Print(); 
  std::cout<<"dziesietnie: "<< static_cast<double>(f) << std::endl;


  std::cout<<"sqrt(a*a) = "<< std::sqrt( static_cast<double>(a*a) ) << std::endl;
  #ifdef ERROR_SQRT
    // ta linijka ma generować error
	std::cout<<"sqrt(a*a) = "<< std::sqrt(a*a) << std::endl;
  #endif

  return 0;
}
/** Wynik dzialania programu:
a = 1/2
b = 2
c = -2/3
a+b+c = 11/6
-c = 2/3
a-c = 7/6
a*c = -1/3
dziesietnie: -0.333333
sqrt(a*a) = 0.5
*/

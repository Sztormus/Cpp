// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku. 

// Po raz kolejny i pewnie nie ostatni piszemy klase, ktora odpowiada
// klasie std::string. Nalezy dodac podstawowe operatory do obslugi 
// lancucha znakow: ==, =, +, *, <<

// Reszta poleceń standardowa.

// !!! UWAGA !!! 
// Przy wykonaniu tego zadania nie wolno korzystac z std::string!

#include "MyString.h"
#include <iostream>

using namespace std;

int main() {
	MyString s0("Szczesliwego Nowego Roku");  
	MyString s1("Szczesliwego nowego roku");
	const MyString s2("Szczesliwego nowego roku");  

	if ( s0 == s1 )  
		cout << " s0 i s1 sa identyczne" << endl;
	if ( s1 == s2 )  
		cout << " s1 i s2 sa identyczne" << endl;
	if ( s2 == s1 )  
		cout << " s2 i s1 sa identyczne" << endl;

	s1.Print();
	MyString s3 = s2 + " tu i teraz,";
	s3.Print();
	MyString s4 = s1 + ". " + s1 + " - " + s2 + '!'; // uwaga na typ char
	s4.Print();

	MyString s5 = 2 * MyString("*");
	MyString s6 = s5 + (const MyString&)s5*4;
	s6.Print();
	
	s6 = s1;
	cout << s6 << endl;
	s6[20] = 'R';
	cout << s6 << endl;

}
/* wynik
 s1 i s2 sa identyczne
 s2 i s1 sa identyczne
Szczesliwego nowego roku
Szczesliwego nowego roku tu i teraz,
Szczesliwego nowego roku. Szczesliwego nowego roku - Szczesliwego nowego roku!
**********
Szczesliwego nowego roku
Szczesliwego nowego Roku
*/

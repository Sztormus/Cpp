/* 
Celem zadania jest napisanie klasy opisujacej wspolrzedne punktu na mapie.

Pod wzgledem dydaktycznym, wazne jest umiejetne zastosowanie 
metod stalych, referencji, metod statycznych, funkcji prywatnych etc.
*/

#include "main.h"
#include "main.h"

#include <iostream>

int main() {
	// ============== Cracow ==============
	const double latKRK = 50.06139;
	const double lonKRK = 19.93833;
	const MapPoint krk( latKRK,  lonKRK );
	krk.print();

	// =============== Pisa ===============
	MapPoint pisa(43.70853, 10.4036);
	pisa.move(0.1, -0.1);
	pisa.print();

	// =============== Bali ===============
	MapPoint bali(-8.40952, 115.18892);
	MapPoint& inIndonesia = bali;
	inIndonesia.print();

	// ======== methods ========
	const MapPoint& cl = krk.furtherFrom( pisa, inIndonesia );
	cl.print();

	MapPoint mp = MapPoint::inTheMiddle(krk,  cl);
	mp.print();
}

/* wynik
Num of points = 1, current Point (50.0614N, 19.9383E)
Point (50.0614N, 19.9383E)
Num of points = 2, current Point (43.7085N, 10.4036E)
Point (43.8085N, 10.3036E)
Num of points = 3, current Point (8.40952S, 115.189E)
Point (8.40952S, 115.189E)
Point (8.40952S, 115.189E)
Num of points = 4, current Point (20.8259N, 67.5636E)
Point (20.8259N, 67.5636E)
Num of points = 3
Num of points = 2
Num of points = 1
Num of points = 0
*/

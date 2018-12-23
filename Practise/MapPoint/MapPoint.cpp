#include "MapPoint.h"
#include <iostream>
#include <cmath>

using namespace std;

int MapPoint::number = 0;

void MapPoint::print() const
{
	if(d_lat > 0 && d_lon > 0)
		cout << "Point (" << d_lat << "N, " << d_lon << "E)" << endl;
	else if(d_lat > 0 && d_lon < 0)
		cout << "Point (" << d_lat << "N, " << -d_lon << "W)" << endl;
	else if(d_lat < 0 && d_lon > 0)
		cout << "Point (" << -d_lat << "S, " << d_lon << "E)" << endl;
	else
		cout << "Point (" << -d_lat << "S, " << -d_lon << "W)" << endl;
}

void MapPoint::Number_of_Points(int n) const
{
	cout << "Num of points = " << n;
}
MapPoint::MapPoint(const double lat, const double lon)
{
	
	d_lat =  lat;
	d_lon = lon;
	number++;
	Number_of_Points(number);
	cout << ", Current";
	print();
}
MapPoint::~MapPoint()
{
	number--;
	Number_of_Points(number);
	cout << endl;
}
void MapPoint::move(const double lat, const double lon)
{
	d_lat += lat;
	d_lon += lon;
}
double MapPoint::odleglosc(double x1, double y1, double x2, double y2) const
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
const MapPoint &MapPoint::furtherFrom(const MapPoint &A, const MapPoint &B) const
{
	double dA = odleglosc(d_lat, d_lon, A.d_lat, A.d_lon);
	double dB = odleglosc(d_lat, d_lon, B.d_lat, B.d_lon);
	return (dA > dB)?A:B;
}
MapPoint MapPoint::inTheMiddle(const MapPoint &A, const MapPoint &B)
{
	MapPoint C((A.d_lat + B.d_lat)/2, (A.d_lon + B.d_lon)/2);
	return C;
}

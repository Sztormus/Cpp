#include <iostream>
#include <cmath>
#include "BitArray.h"


BitArray::BitArray(const int& number, const bool& value) : _size(number) 
{
    int size = ceil(number/8.0);
    _bits = new unsigned char[size];
    for(int i = 0; i < number; i++) 
        (*this)[i] = value;
}

BitArray::~BitArray() 
{
	delete[] _bits;
}

void BitArray::print() const 
{
    for(int i = _size - 1; i >= 0; i--) 
    {
		std::cout << (*this)[i];
		if(i % 8  == 0)
			std::cout << " <-"<< i-i%8 << " ";
	}
}

Bit BitArray::operator[](const int & position) const
{
	int positionInArray = position / 8;
	int positionInCell = position % 8;
	return Bit(positionInCell, _bits + positionInArray);
}


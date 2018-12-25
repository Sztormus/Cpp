#include <iostream>
#include "Bit.h"

Bit::Bit(const int& position, unsigned char* bitArray) : _bitArray(bitArray), _positionInCell(position) {}

void Bit::operator = (const bool& value) 
{
    
	if(value == false)
		*_bitArray &= ~(1 << _positionInCell);
	
	else 
		*_bitArray |= (1 << _positionInCell);
}

Bit::operator bool() const
{
    return(*_bitArray & (1 << _positionInCell)) != 0;
}
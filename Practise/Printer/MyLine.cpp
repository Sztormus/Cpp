#include "MyLine.h"

MyLine::MyLine(char sing, int num, AttColor::Option opt)
	:StringConvertable(), AttColor(), m_sign(sing), m_length(num)
{
	setColor(opt);
}

const std::string MyLine::rawString() const
{
	std::string r(m_length, m_sign);
	return r;
}

void MyLine::setChar(char sign) 
{ 
	m_sign = sign;
}

void MyLine::setLength(int length) 
{ 
	m_length = length; 
}

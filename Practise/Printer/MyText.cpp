#include "MyText.h"

MyText::MyText(std::string text, AttFormat::Option format, AttColor::Option color)
:StringConvertable(), AttFormat(), AttColor(), m_text(text)
{
	setColor(color);
	setFormat(format);
}

const std::string MyText::rawString() const
{ 
	return m_text; 
}

void MyText::setText(std::string text) 
{
	m_text = text;
}

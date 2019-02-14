#include "stdafx.h"
#include "circle.h"


circle::circle()
{
}

std::string circle::toSVG()
{
	s = "<circle";
	for (Attribute* attPtr : Shape::getAtt())
	{
		s += ' ';
		s += attPtr->getKey();
		s += "=\"";
		s += attPtr->getValue();
		s += "\"";
	}
	s += " />";
	return s;
}

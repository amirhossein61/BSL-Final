#include "stdafx.h"
#include "ellipse.h"


ellipse::ellipse()
{
}

std::string ellipse::toSVG()
{
	s = "<ellipse";
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


#include "stdafx.h"
#include "polygon.h"


polygon::polygon()
{
}

std::string polygon::toSVG()
{
	s = "<polygon";
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

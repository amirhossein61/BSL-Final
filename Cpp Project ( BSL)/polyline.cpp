#include "stdafx.h"
#include "polyline.h"


polyline::polyline()
{
}

std::string polyline::toSVG()
{
	s = "<polyline";
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


polyline::~polyline()
{
}

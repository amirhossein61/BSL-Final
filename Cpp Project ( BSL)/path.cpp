#include "stdafx.h"
#include "path.h"


path::path()
{
}

std::string path::toSVG()
{
	s = "<path";
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

#include "stdafx.h"
#include "text.h"


text::text()
{
}

std::string text::toSVG()
{
	s = "<text";
	for (Attribute* attPtr : Shape::getAtt())
	{
		if (attPtr->getKey() == "text")
		{
			s += ">";
			s += attPtr->getValue();
			s += "</text>";
			break;
		}
		s += ' ';
		s += attPtr->getKey();
		s += "=\"";
		s += attPtr->getValue();
		s += "\"";

	}
	s += " />";
	return s;
}

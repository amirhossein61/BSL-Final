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
	if (Shape::getAnimate().size() == 0)
		s += " />";
	else
	{

		for (auto animPtr : Shape::getAnimate())
		{
			s += " >";
			s += "\n<animate";
			for (auto attPtr : animPtr->getAtt())
			{
				s += ' ';
				s += attPtr->getKey();
				s += "=\"";
				s += attPtr->getValue();
				s += "\"";
			}
			s += " />";
		}
		s += "\n</path>";
	}
	return s;
}

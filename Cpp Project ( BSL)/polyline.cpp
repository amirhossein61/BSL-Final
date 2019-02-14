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
		s += "\n</polyline>";
	}
	return s;
}


polyline::~polyline()
{
}

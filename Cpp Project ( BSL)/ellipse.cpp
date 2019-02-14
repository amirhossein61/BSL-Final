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
		s += "\n</ellipse>";
	}
	return s;
}


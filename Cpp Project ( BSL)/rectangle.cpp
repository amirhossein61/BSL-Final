#include "stdafx.h"
#include "rectangle.h"

using namespace std;
rectangle::rectangle()
{
}

string rectangle::toSVG()
{
	s = "<rect";
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
		
		s += "\n</rect>";
	}
	return s;
}


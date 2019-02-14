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
		s += " >";
		s += "\n<animate";
		for (auto animPtr : Shape::getAnimate())
		{
			s += ' ';
			s += animPtr->getKey();
			s += "=\"";
			s += animPtr->getValue();
			s += "\"";
		}
		s += " />";
		s += "\n</rect>";
	}
	return s;
}


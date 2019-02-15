#include "stdafx.h"
#include "text.h"


text::text()
{
}

std::string text::toSVG()
{
	s = "<text";
	if (Shape::getAnimate().size() == 0)
	{
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
	}
	else if(Shape::getAnimate().size() != 0)
	{
		for (Attribute* attPtr : Shape::getAtt())
		{
			if (attPtr->getKey() == "text")
			{
				continue;
			}
			s += ' ';
			s += attPtr->getKey();
			s += "=\"";
			s += attPtr->getValue();
			s += "\"";

		}

		s += " >";

		for (auto animPtr : Shape::getAnimate())
		{
			//s += " >";
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
		for (auto attPtr : Shape::getAtt())
		{
			if (attPtr->getKey() == "text")
				s += attPtr->getValue();
		}
		s += "\n</text>";
	}
	return s;
}

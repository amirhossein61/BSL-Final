#include "stdafx.h"
#include "clearCommand.h"

using namespace std;

clearCommand::clearCommand()
{
}

void clearCommand::cmdRun(std::vector<std::string>& inputString, SVG & svg)
{
	int determiner = inputString[1].find('>');
	if (determiner == string::npos)
	{
		string name = inputString[1];
		size_t i = 0;
		for (auto shape : svg.getShape())
		{
			if (name == shape->getName())
			{
				Shape* temp = shape;
				svg.getShape().erase(svg.getShape().begin() + i);
				delete temp;
			}
			++i;
		}
		if (name == "all")
		{
			for (auto shape : svg.getShape())
				shape->~Shape();

			svg.getShape().clear();
		}
	}
	else
	{
		int nameLocation = inputString[1].find_first_of('-');
		string shapeName = inputString[1].substr(0, nameLocation);

		int animLocation = inputString[1].find_last_of('>');
		string animName = inputString[1].substr(animLocation + 1);

		
		for (auto shape : svg.getShape())
		{
			if (shapeName == shape->getName())
			{
				size_t i = 0;
				for (auto anim : shape->getAnimate())
				{
					if (animName == anim->getName())
					{
						Animation* temp = anim;
						shape->getAnimate().erase(shape->getAnimate().begin()+i);
						delete temp;
					}
					i++;
				}
			}
		}
	}
}

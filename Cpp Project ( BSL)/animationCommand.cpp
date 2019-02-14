#include "stdafx.h"
#include "animationCommand.h"

using namespace std;
animationCommand::animationCommand()
{
}

void animationCommand::cmdRun(std::vector<std::string>& inputString, SVG & svg)
{
	string nameOfShape = inputString[1];
	for (auto s : svg.getShape())
	{
		if (s->getName() == inputString[1])
		{
			Animation* anim1 = new Animation;
			anim1->setName(inputString[2]);
			s->pushBackAnimate(anim1);
		}
	}
}


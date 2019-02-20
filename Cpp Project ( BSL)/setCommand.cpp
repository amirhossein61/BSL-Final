#include "stdafx.h"
#include "setCommand.h"

using namespace std;
setCommand::setCommand()
{
}

void setCommand::cmdRun(std::vector<std::string>& inputString, SVG &svg)
{
	int nameLocation = inputString[1].find_first_of('-');
	string shapeName = inputString[1].substr(0, nameLocation);

	int keyLocation = inputString[1].find_last_of('>');
	string key = inputString[1].substr(keyLocation + 1);

	int valueLocation = inputString[2].find_last_of(')');
	string value = inputString[2].substr(1, valueLocation - 1);

	if (inputString.size() > 3)//to support path features
	{
		string pathValueStart = inputString[2].substr(1);
		string pathValue;
		pathValue += pathValueStart;
		for (size_t i = 3; i <inputString.size(); i++)
		{
			pathValue += ' ';
			pathValue += inputString[i];
		}
		pathValue.erase(pathValue.end()-1);
		value = pathValue;
	}

	Attribute* att = new Attribute;
	att->setKey(key);
	att->setValue(value);


	int arrowLocation1 = inputString[1].find_first_of('>');
	int arrowLocation2 = inputString[1].find_last_of('>');
	if (arrowLocation1 != arrowLocation2)
	{
		string animName = inputString[1].substr(arrowLocation1 + 1, ((arrowLocation2 - 2) - arrowLocation1));

		for (auto s : svg.getShape())
		{
			if (s->getName() == shapeName)
			{
				for (auto a : s->getAnimate())
				{
					if (animName == a->getName())
					{
						a->pushBackAtt(att);
						return;
					}
				}
			}


		}
	}


	for (auto s : svg.getShape())
	{
		if (s->getName() == shapeName)
		{
			s->pushBackAtt(att);
		}
	}
}

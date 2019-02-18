#include "stdafx.h"
#include "getCommand.h"

using namespace std;

getCommand::getCommand()
{
}

void getCommand::cmdRun(std::vector<std::string>& inputString, SVG & svg)
{
	int nameLocation = inputString[1].find_first_of('-');
	string shapeName = inputString[1].substr(0, nameLocation);

	int keyLocation = inputString[1].find_last_of('>');
	string key = inputString[1].substr(keyLocation + 1);

	int arrowLocation1 = inputString[1].find_first_of('>');
	int arrowLocation2 = inputString[1].find_last_of('>');
	if (arrowLocation1 != arrowLocation2)
	{
		string animName = inputString[1].substr(arrowLocation1 + 1, ((arrowLocation2 - 2) - arrowLocation1));

		for (auto shape : svg.getShape())
		{
			if (shapeName == shape->getName())
			{
				for (auto anim : shape->getAnimate())
				{
					if (animName == anim->getName())
					{
						for (auto att : anim->getAtt())
						{
							if (key == att->getKey())
							{
								cout << att->getValue() << endl;
								return;
							}
						}
					}


				}


			}

		}




	}
	for (auto shape : svg.getShape())
	{
		if (shapeName == shape->getName())
		{
			for (auto att : shape->getAtt())
			{
				if (key == att->getKey())
					cout << att->getValue()<<endl;

			}


		}
	}
}

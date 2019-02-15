#include "stdafx.h"
#include "listCommand.h"
#include<typeinfo>

using namespace std;
listCommand::listCommand()
{
}

void listCommand::cmdRun(std::vector<std::string>& inputString, SVG & svg)
{
	if (inputString.size()!=1)
	{
		if (inputString[1] == "animate")
		{
			string shapeName = inputString[2];
			for (auto shape : svg.getShape())
			{
				if (shapeName == shape->getName())
				{
					for (auto anim : shape->getAnimate())
					{
						cout << anim->getName() << " : " << endl;
						for (auto att : anim->getAtt())
						{
							cout << "\tKey : " << att->getKey() << " , Value : " << att->getValue() << endl;

						}
					}


				}



			}
		}

	}
	else
	{
		for (auto shape : svg.getShape())
		{
			cout << "name: " << shape->getName();
			cout << ", type: " << typeid(*shape).name();
			cout << endl;
		}
	}
}

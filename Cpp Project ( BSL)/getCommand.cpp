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

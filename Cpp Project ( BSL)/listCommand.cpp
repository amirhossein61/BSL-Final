#include "stdafx.h"
#include "listCommand.h"
#include<typeinfo>

using namespace std;
listCommand::listCommand()
{
}

void listCommand::cmdRun(std::vector<std::string>& inputString, SVG & svg)
{
	for (auto shape : svg.getShape())
	{
		cout << "name: " << shape->getName();
		cout << ", type: " << typeid(*shape).name();
		cout << endl;
	}
}

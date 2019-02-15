#include "stdafx.h"
#include "clearCommand.h"

using namespace std;

clearCommand::clearCommand()
{
}

void clearCommand::cmdRun(std::vector<std::string>& inputString, SVG & svg)
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

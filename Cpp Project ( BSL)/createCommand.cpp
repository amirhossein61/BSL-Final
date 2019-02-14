#include "stdafx.h"
#include "createCommand.h"
#include"Shape.h"
#include"rectangle.h"
#include"circle.h"
#include"ellipse.h"
#include"path.h"
#include"polygon.h"
#include"polyline.h"
#include"text.h"
#include"App.h"
#include<string>
#include"SVG.h"

using namespace std;

createCommand::createCommand()
{
}

void createCommand::cmdRun(std::vector<std::string>& inputString, SVG &svg)
{
	string name = inputString[2];
	if (inputString[1] == "rectangle")
	{
		Shape* newShape = new rectangle;
		newShape->setName(name);
		svg.getShape().push_back(newShape);
	}
	if (inputString[1] == "circle")
	{
		Shape* newShape = new circle;
		newShape->setName(name);
		svg.getShape().push_back(newShape);
	}
	if (inputString[1] == "ellipse")
	{
		Shape* newShape = new ellipse;
		newShape->setName(name);
		svg.getShape().push_back(newShape);
	}
	if (inputString[1] == "text")
	{
		Shape* newShape = new text;
		newShape->setName(name);
		svg.getShape().push_back(newShape);
	}
	if (inputString[1] == "path")
	{
		Shape* newShape = new path;
		newShape->setName(name);
		svg.getShape().push_back(newShape);
	}
	if (inputString[1] == "text")
	{
		Shape* newShape = new text;
		newShape->setName(name);
		svg.getShape().push_back(newShape);
	}
	if (inputString[1] == "polygon")
	{
		Shape* newShape = new polygon;
		newShape->setName(name);
		svg.getShape().push_back(newShape);
	}
	if (inputString[1] == "polyline")
	{
		Shape* newShape = new polyline;
		newShape->setName(name);
		svg.getShape().push_back(newShape);
	}
}


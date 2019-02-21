#include "stdafx.h"
#include "Plot.h"
#include"Shape.h"
#include"circle.h"
#include"rectangle.h"
#include"polyline.h"
#include"text.h"
//#include"Split.h"
using namespace std;

Plot::Plot()
{
	Shape* rect = new rectangle;

	Attribute* fill = new Attribute;
	fill->setKey("fill");
	fill->setValue("white");
	rect->pushBackAtt(fill);
	Attribute* stroke = new Attribute;
	stroke->setKey("stroke");
	stroke->setValue("blue");
	rect->pushBackAtt(stroke);
	shape.push_back(rect);
}

std::string Plot::toSVG()
{
	setRectangleFeatures();
	setText();
	readFile();
	for (auto sh : shape)
	{
		s += sh->toSVG();
		s += '\n';
	}
	return s;
	
}

std::vector<Shape*> Plot::getShape() const
{
	return shape;
}

void Plot::setShape(std::vector<Shape*> sh)
{
	shape = sh;
}

void Plot::pushBackShape(Shape * sh)
{
	shape.push_back(sh);
}

void Plot::readFile()
{
	string fileName;

	for (auto att : this->getAtt())
	{
		if (att->getKey() == "data")
			fileName = att->getValue();
	}
	
	ifstream dataFile("data/" + fileName);
	if (!dataFile)
	{
		cout << "File didn't opened properly. " << endl;
		exit(EXIT_FAILURE);//EXCEPTION BEZARAM
	}
	
	string type;
	for (auto att : this->getAtt())
	{
		if (att->getKey() == "type")
			type = att->getValue();
	}
	string line;
	//vector<string>splitedString;

	if (type == "scatter")
	{
		while (dataFile>>line)
		{
		//	split(line, splitedString, ',');
			int location = line.find_first_of(',');
			string first = line.substr(0, location);
			string second = line.substr(location + 1);
			scatterPlot(first, second);
		}
	}
	else if (type == "line")
	{
		Shape* newShape = new polyline;
		Attribute* atts1 = new Attribute;
		atts1->setKey("fill");
		atts1->setValue("none");
		newShape->pushBackAtt(atts1);

		Attribute* atts2 = new Attribute;
		atts2->setKey("stroke");
		atts2->setValue("red");
		newShape->pushBackAtt(atts2);

		string polyPoints;
		Attribute* atts3 = new Attribute;
		atts3->setKey("points");
		while (dataFile >> line)
		{
		//	split(line, splitedString, ',');
			int location = line.find_first_of(',');
			string first = line.substr(0, location);
			string second = line.substr(location + 1);
			polyPoints += linePlot(first, second);
		}
		atts3->setValue(polyPoints);
		newShape->pushBackAtt(atts3);

		shape.push_back(newShape);
	}
}

void Plot::scatterPlot(string x, string y)
{
	Shape* newShape = new circle;
	float X=20.0f;
	for (auto att : this->getAtt())
	{
		if (att->getKey() == "x")
			X =stof( att->getValue());
	}
	float xTransform = stof(x);
	float xPosition = xTransform + X;
	string newXPosition = to_string(xPosition);

	Attribute* att1 = new Attribute;
	att1->setKey("cx");
	att1->setValue(newXPosition);
	newShape->pushBackAtt(att1);
	//-------------------------------------------------------
	float Y=20.0f,height=300.0f;

	for (auto att : this->getAtt())
	{
		if (att->getKey() == "y")
			Y = stof(att->getValue());

		if (att->getKey() == "height")
			height = stof(att->getValue());
	}
	float yTransform = stof(y);
	float yPosition = (Y + height) - yTransform;
	string newYPosition = to_string(yPosition);

	Attribute* att2 = new Attribute;
	att2->setKey("cy");
	att2->setValue(newYPosition);
	newShape->pushBackAtt(att2);
	//------------------------------------------------------
	Attribute* att3 = new Attribute;
	Attribute* att4 = new Attribute;

	att3->setKey("fill");
	att3->setValue("red");
	newShape->pushBackAtt(att3);

	att4->setKey("r");
	att4->setValue("2");
	newShape->pushBackAtt(att4);


	shape.push_back(newShape);

}

string Plot::linePlot(string x,string y)
{
	
	float X;
	for (auto att : this->getAtt())
	{
		if (att->getKey() == "x")
			X = stof(att->getValue());
	}
	float xTransform = stof(x);
	float xPosition = xTransform + X;
	string newXPosition = to_string(xPosition);

	string polyPoints;
	polyPoints += newXPosition;

	float Y, height;
	for (auto att : this->getAtt())
	{
		if (att->getKey() == "y")
			Y = stof(att->getValue());

		if (att->getKey() == "height")
			height = stof(att->getValue());
	}
	float yTransform = stof(y);
	float yPosition = (Y + height) - yTransform;
	string newYPosition = to_string(yPosition);

	polyPoints += ',';
	polyPoints += newYPosition;
	polyPoints += ' ';
	return polyPoints;
}

void Plot::setRectangleFeatures()
{

	for (auto sh : shape)
	{
		rectangle* rectPtr = dynamic_cast<rectangle*>(sh);
		if (rectPtr != nullptr)
		{
			for (auto att : this->getAtt())
			{
				if (att->getKey() == "x")
				{
					Attribute* att0 = new Attribute;
					att0->setKey("x");
					att0->setValue(att->getValue());
					rectPtr->pushBackAtt(att0);
				}
				if (att->getKey() == "y")
				{
					Attribute* att1 = new Attribute;
					att1->setKey("y");
					att1->setValue(att->getValue());
					rectPtr->pushBackAtt(att1);
				}
				if (att->getKey() == "height")
				{
					Attribute* att2 = new Attribute;
					att2->setKey("height");
					att2->setValue(att->getValue());
					rectPtr->pushBackAtt(att2);
				}
				if (att->getKey() == "width")
				{
					Attribute* att3 = new Attribute;
					att3->setKey("width");
					att3->setValue(att->getValue());
					rectPtr->pushBackAtt(att3);
				}
			}

		}

	}
	
}

void Plot::setText()
{
	Shape* newShape = new text;
	float x;
	float y;
	float width;
	string title;
	for (auto att : this->getAtt())
	{
		if (att->getKey() == "x")
			x = stof(att->getValue());

		if (att->getKey() == "y")
			y =stof(att->getValue());

		if (att->getKey() == "width")
			width = stof(att->getValue());

		if (att->getKey() == "title")
			title = att->getValue();

	}
	float xText = (width / 2) - x-10;
	string xPos = to_string(xText);
	float yText = y - 5;
	string yPos = to_string(yText);

	Attribute* att1 = new Attribute;
	att1->setKey("x");
	att1->setValue(xPos);
	newShape->pushBackAtt(att1);

	Attribute* att2 = new Attribute;
	att2->setKey("y");
	att2->setValue(yPos);
	newShape->pushBackAtt(att2);

	Attribute* att3 = new Attribute;
	att3->setKey("font-size");
	att3->setValue("24");
	newShape->pushBackAtt(att3);

	Attribute* att4 = new Attribute;
	att4->setKey("font-family");
	att4->setValue("Ubuntu");
	newShape->pushBackAtt(att4);

	Attribute* att5 = new Attribute;
	att5->setKey("text");
	att5->setValue(title);
	newShape->pushBackAtt(att5);

	shape.push_back(newShape);
}

#include "stdafx.h"
#include "SVG.h"

using namespace std;

SVG::SVG() {
	defaultSvg =
		"<?xml version=\"1.0\" standalone=\"no\"?>\n<!DOCTYPE svg PUBLIC \" "
		"-//W3C//DTD SVG "
		"1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">";

}

std::vector<Shape *> &SVG::getShape() {
	return shape;
}

void SVG::setShape(std::vector<Shape*> shVector)
{
	shape = shVector;
}

string& SVG::makePic()
{
	cmpSvg += defaultSvg;
	cmpSvg += "\n<svg ";
	cmpSvg += "width=\"";
	cmpSvg += getWidth();
	cmpSvg += "\" height=\"";
	cmpSvg += getHeight();
	cmpSvg += "\"\nxmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n";
	for (auto sh : shape)
	{
		cmpSvg += sh->toSVG();
		cmpSvg += "\n";
	}
	cmpSvg += "\n</svg>";

	return cmpSvg;
}

void SVG::setWidth(std::string w)
{
	width = w;
}

void SVG::setHeight(std::string h)
{
	height = h;
}


std::string SVG::getWidth() const
{
	return width;
}

std::string SVG::getHeight() const
{
	return height;
}

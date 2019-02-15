#include "stdafx.h"
#include "Shape.h"

using namespace std;
Shape::Shape() { }

Shape::~Shape()
{
	for (auto a : att)
		delete (a);

	att.clear();

	for (auto anim : animate)
		delete (anim);

	animate.clear();
}

std::string Shape::getName() const
{
	return nameOfShape;
}

void Shape::setName(std::string name)
{
	nameOfShape = name;
}

std::vector<Attribute*> Shape::getAtt() const
{
	return att;
}

void Shape::setAtt(std::vector<Attribute*>& att)
{
	this->att = att;
}

void Shape::pushBackAtt(Attribute * attribute)
{
	att.push_back(attribute);
}

std::vector<Animation*> Shape::getAnimate() const
{
	return animate;
}

void Shape::setAnimate(std::vector<Animation*>& anim)
{
	animate = anim;
}

void Shape::pushBackAnimate(Animation *anim)
{
	animate.push_back(anim);
}


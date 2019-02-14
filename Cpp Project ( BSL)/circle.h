#pragma once
#include "Shape.h"
class circle :
	public Shape
{
public:
	circle();
	virtual ~circle() {};
	virtual std::string toSVG() override;

private:
	std::string s;
};


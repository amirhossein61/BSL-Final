#pragma once
#include "Shape.h"
class ellipse :
	public Shape
{
public:
	ellipse();
	virtual ~ellipse() {};
	virtual std::string toSVG() override;

private:
	std::string s;
};


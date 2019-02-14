#pragma once
#include "Shape.h"
class polyline :
	public Shape
{
public:
	polyline();
	virtual std::string toSVG() override;
	virtual ~polyline();

private:
	std::string s;
};


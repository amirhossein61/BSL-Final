#pragma once
#include "Shape.h"
class polygon :
	public Shape
{
public:
	polygon();
	virtual ~polygon() {};
	virtual std::string toSVG() override;

private:
	std::string s;
};


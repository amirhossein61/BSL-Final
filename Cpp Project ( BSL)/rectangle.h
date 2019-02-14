#pragma once
#include "Shape.h"
class rectangle :
	public Shape
{
public:
	rectangle();
	virtual std::string toSVG() override;
	virtual ~rectangle() {};

private:
	std::string s;
};


#pragma once
#include "Shape.h"
class path :
	public Shape
{
public:
	path();
	virtual ~path() {};
	virtual std::string toSVG() override;
private:
	std::string s;
};


#pragma once
#include "Shape.h"
class text :
	public Shape
{
public:
	text();
	virtual std::string toSVG() override;
	virtual ~text() {};

private:
	std::string s;
};


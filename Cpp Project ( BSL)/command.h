#pragma once
#include<vector>
#include"Shape.h"
#include"SVG.h"
class command
{
public:
	command();
	virtual ~command() {};
	virtual void cmdRun(std::vector<std::string>&, SVG &) = 0;
};
#pragma once
#include "command.h"
#include<iostream>
class listCommand :
	public command
{
public:
	listCommand();
	virtual ~listCommand() {};
	virtual void cmdRun(std::vector<std::string>&, SVG &) override;
};


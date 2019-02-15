#pragma once
#include "command.h"
#include<iostream>

class getCommand :
	public command
{
public:
	getCommand();
	virtual ~getCommand() {};
	virtual void cmdRun(std::vector<std::string>&, SVG &) override;
};


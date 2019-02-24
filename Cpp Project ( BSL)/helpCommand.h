#pragma once
#include "command.h"
#include<iostream>
class helpCommand :
	public command
{
public:
	helpCommand();
	virtual ~helpCommand() {};
	virtual void cmdRun(std::vector<std::string>&, SVG &) override;
};


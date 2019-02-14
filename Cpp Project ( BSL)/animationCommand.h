#pragma once
#include "command.h"
class animationCommand :
	public command
{
public:
	animationCommand();
	virtual ~animationCommand() {};
	virtual void cmdRun(std::vector<std::string>&, SVG &) override;
};


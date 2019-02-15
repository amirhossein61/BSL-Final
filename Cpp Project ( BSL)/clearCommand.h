#pragma once
#include "command.h"
class clearCommand :
	public command
{
public:
	clearCommand();
	virtual ~clearCommand() {};
	virtual void cmdRun(std::vector<std::string>&, SVG &) override;
};


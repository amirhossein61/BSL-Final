#pragma once
#include "command.h"
#include"SVG.h"
class exportCommand :
	public command
{
public:
	exportCommand();
	virtual ~exportCommand() {};
	virtual void cmdRun(std::vector<std::string>&, SVG &) override;
};


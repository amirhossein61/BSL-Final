#pragma once
#include "command.h"
#include"SVG.h"
class createCommand :
	public command
{
public:
	createCommand();
	virtual ~createCommand() {};
	virtual void cmdRun(std::vector<std::string>&, SVG &) override;

};


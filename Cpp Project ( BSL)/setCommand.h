#pragma once
#include "command.h"
#include"SVG.h"
#include"Attribute.h"
#include"SVG.h"
class setCommand :
	public command
{
public:
	setCommand();
	virtual ~setCommand() {};
	virtual void cmdRun(std::vector<std::string>&, SVG &) override;

};


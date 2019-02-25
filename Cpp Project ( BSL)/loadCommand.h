#pragma once
#include "command.h"
#include<string>
#include<iostream>
#include<fstream>
class loadCommand :
	public command
{
public:
	loadCommand();
	virtual ~loadCommand() {};
	virtual void cmdRun(std::vector<std::string>&, SVG &) override;
	std::vector<std::string>& getVect();

private:
	std::vector<std::string> out;
};


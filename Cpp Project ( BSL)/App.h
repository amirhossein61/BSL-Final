#pragma once
#include<vector>
#include<string>
#include"SVG.h"

class App
{
	friend class loadCommand;
public:
	App();
	virtual ~App() {};
	void run();
	void setString(std::string &);
private:
	std::string input;
	std::vector<std::string> splitedString;
	SVG svg;
};


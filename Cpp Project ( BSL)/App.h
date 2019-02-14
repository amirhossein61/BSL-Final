#pragma once
#include<vector>
#include<string>
#include"SVG.h"

class App
{
public:
	App();
	virtual ~App() {};
	void run();
private:
	std::string input;
	std::vector<std::string> splitedString;
	SVG svg;
};


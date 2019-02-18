#include "stdafx.h"
#include "exportCommand.h"
#include<fstream>
#include"SVG.h"
using namespace std;
exportCommand::exportCommand()
{
}

void exportCommand::cmdRun(std::vector<std::string>& inputString, SVG & svg)
{
	int fileNameLocation = inputString[1].find_last_of(')');
	string nameOfFile = inputString[1].substr(1, fileNameLocation - 1);
	string file = svg.makePic();
	ofstream myfile;
	string saveLocation = "export/";
	myfile.open(saveLocation + nameOfFile);
	myfile << file;
	myfile.close();

}



#include "stdafx.h"
#include "loadCommand.h"
#include"helper.h"
#include"App.h"
using namespace std;

loadCommand::loadCommand()
{
}

void loadCommand::cmdRun(std::vector<std::string>& inputString, SVG &svg)
{
	int location = inputString[1].find_first_of(')');
	string nameOfFile = inputString[1].substr(1, location-1);

	ifstream openFile("programs/"+nameOfFile);
	if (!openFile)
	{
		cout << "File didn't opened properly. " << endl;
		exit(EXIT_FAILURE);//EXCEPTION BEZARAM
	}
	string read;
	while (!openFile.eof())
	{
		getline(openFile, read);
		size_t inputSize = read.size();
		if (inputSize != 0 && read[0] != '#' && read[inputSize - 1] == ';')
		{
			vector<string> splitedString;
			helper::split(read, splitedString, ' ');
			App* app = new App;
			app->setVector(splitedString);

			//App::setVector(splitedString);

		}

	}



}

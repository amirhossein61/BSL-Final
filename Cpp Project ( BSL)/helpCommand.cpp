#include "stdafx.h"
#include "helpCommand.h"

using namespace std;
helpCommand::helpCommand()
{
}

void helpCommand::cmdRun(std::vector<std::string>& inputString, SVG & svg)
{
	string nameOfCommand = inputString[1];
	if (nameOfCommand == "create")
		cout << "create command : You can make a shape or plot using this command. " << endl;
	else if (nameOfCommand == "set")
		cout << "set command : You can set attributes or animations for shapes or plots using this command. " << endl;
	else if (nameOfCommand == "export")
		cout << "export command : You can export your final svg file with your optional svg file name using this command. " << endl;
	else if (nameOfCommand == "list")
		cout << "list command : You can see list of shapes or plots and even animations of a specific shape using this command. " << endl;
	else if (nameOfCommand == "clear")
		cout << "clear command : You can remove shapes,plots and even animations of a specific shape using this command. " << endl;
	else if (nameOfCommand == "get")
		cout << "get command : You can see value of attributes of a shape,plot or animation using this command. " << endl;
	else if (nameOfCommand == "animation")
		cout << "animation command : You can make a new animation for an existing shape using this command. " << endl;
	else if (nameOfCommand == "load")
		cout << "load command : You can read commands from a file using this command. " << endl;
	else if (nameOfCommand == "exit")
		cout << "exit command : You can exit the program using this command. " << endl;
	else
		cout << "Undefined command entered. " << endl;

}		

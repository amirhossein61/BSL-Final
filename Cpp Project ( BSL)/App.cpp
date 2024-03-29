#include "stdafx.h"
#include "App.h"
#include"command.h"
#include"createCommand.h"
#include"setCommand.h"
#include"exportCommand.h"
#include"animationCommand.h"
#include"listCommand.h"
#include"clearCommand.h"
#include"getCommand.h"
#include"helper.h"
#include"loadCommand.h"
#include"helpCommand.h"
using namespace std;

App::App()
{
}

void App::run()
{
	bool appRun = true;
	while (appRun == true)
	{
		cout << "> ";
		getline(cin, input);
		helper::split(input, splitedString, ' ');
		if (splitedString[0] == "load")
		{
			loadCommand *cmd = new loadCommand;
			cmd->cmdRun(splitedString, svg);
			for (size_t i = 0; i < cmd->getVect().size(); ++i)
			{
				helper::split(cmd->getVect().at(i), splitedString, ' ');
				if (splitedString[0] == "create")
				{
					command *cmd = new createCommand;
					cmd->cmdRun(splitedString, svg);
				}
				if (splitedString[0] == "set" && splitedString[1] == "width")
				{
					int Location = splitedString[2].find_last_of(')');
					string widthValue = splitedString[2].substr(1, Location - 1);
					svg.setWidth(widthValue);

				}
				if (splitedString[0] == "set" && splitedString[1] == "height")
				{
					int Location = splitedString[2].find_last_of(')');
					string heightValue = splitedString[2].substr(1, Location - 1);
					svg.setHeight(heightValue);

				}
				if (splitedString[0] == "set")
				{
					command *cmd = new setCommand;
					cmd->cmdRun(splitedString, svg);
				}
				if (splitedString[0] == "export")
				{
					command *cmd = new exportCommand;
					cmd->cmdRun(splitedString, svg);
				}
				if (splitedString[0] == "list")
				{
					command *cmd = new listCommand;
					cmd->cmdRun(splitedString, svg);
				}
				if (splitedString[0] == "clear")
				{
					command *cmd = new clearCommand;
					cmd->cmdRun(splitedString, svg);
				}
				if (splitedString[0] == "get")
				{
					command *cmd = new getCommand;
					cmd->cmdRun(splitedString, svg);
				}
				if (splitedString[0] == "animation")
				{
					command *cmd = new animationCommand;
					cmd->cmdRun(splitedString, svg);
				}
				if (splitedString[0] == "help")
				{
					command *cmd = new helpCommand;
					cmd->cmdRun(splitedString, svg);
				}
				if (splitedString[0] == "exit")
					appRun = false;
			}
			continue;
		}
		if (splitedString[0] == "create")
		{
			command *cmd = new createCommand;
			cmd->cmdRun(splitedString, svg);
		}
		if (splitedString[0] == "set" && splitedString[1] == "width")
		{
			int Location = splitedString[2].find_last_of(')');
			string widthValue = splitedString[2].substr(1, Location - 1);
			svg.setWidth(widthValue);

		}
		if (splitedString[0] == "set" && splitedString[1] == "height")
		{
			int Location = splitedString[2].find_last_of(')');
			string heightValue = splitedString[2].substr(1, Location - 1);
			svg.setHeight(heightValue);

		}
		if (splitedString[0] == "set")
		{
			command *cmd = new setCommand;
			cmd->cmdRun(splitedString, svg);
		}
		if (splitedString[0] == "export")
		{
			command *cmd = new exportCommand;
			cmd->cmdRun(splitedString, svg);
		}
		if (splitedString[0] == "list")
		{
			command *cmd = new listCommand;
			cmd->cmdRun(splitedString, svg);
		}
		if (splitedString[0] == "clear")
		{
			command *cmd = new clearCommand;
			cmd->cmdRun(splitedString, svg);
		}
		if (splitedString[0] == "get")
		{
			command *cmd = new getCommand;
			cmd->cmdRun(splitedString, svg);
		}
		if (splitedString[0] == "animation")
		{
			command *cmd = new animationCommand;
			cmd->cmdRun(splitedString, svg);
		}
		if (splitedString[0] == "help")
		{
			command *cmd = new helpCommand;
			cmd->cmdRun(splitedString, svg);
		}
		if (splitedString[0] == "exit")
			appRun = false;
	}

}


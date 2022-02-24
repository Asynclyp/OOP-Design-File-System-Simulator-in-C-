#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>
#include <iterator>
#include <sstream>

class CommandPrompt {
	map<string, AbstractCommand*> command_map;
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
public:
	CommandPrompt();
	virtual ~CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem* file_system);
	void setFileFactory(AbstractFileFactory* file_factory);
	int addCommand(string str, AbstractCommand* command);
	int run();
protected:
	void listCommands();
	string prompt();
};
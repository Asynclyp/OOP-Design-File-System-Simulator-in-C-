#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFile.h"
#include "AbstractFileSystem.h"
#include<vector>

class MacroCommand : public AbstractCommand {
	vector<AbstractCommand*> commands;
	AbstractParsingStrategy* strategy;
public:
	MacroCommand(AbstractFileSystem* afs);
	virtual int execute(string input);
	virtual void displayInfo();
	virtual ~MacroCommand() = default;
	void addCommand(AbstractCommand* command);
	void setParseStrategy(AbstractParsingStrategy* s);
};
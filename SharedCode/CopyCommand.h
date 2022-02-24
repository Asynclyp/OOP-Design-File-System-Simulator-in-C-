#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include<sstream>

class CopyCommand : public AbstractCommand {
	AbstractFileSystem* afs;
public:
	CopyCommand(AbstractFileSystem* file_system);
	virtual int execute(string arguments);
	virtual void displayInfo();
};
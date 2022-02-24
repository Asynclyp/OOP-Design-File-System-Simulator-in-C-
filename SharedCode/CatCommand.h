#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include<sstream>

class CatCommand : public AbstractCommand {
	AbstractFileSystem* afs;
public:
	CatCommand(AbstractFileSystem* file_system);
	virtual int execute(string arguments);
	virtual void displayInfo();
};
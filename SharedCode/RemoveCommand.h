#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
	AbstractFileSystem* afs;
public:
	RemoveCommand(AbstractFileSystem* file_system);
	virtual int execute(string flags);
	virtual void displayInfo();
};
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "BasicDisplayVisitor.h"
#include<sstream>

class DisplayCommand : public AbstractCommand {
	AbstractFileSystem* afs;
public:
	DisplayCommand(AbstractFileSystem* file_system);
	virtual int execute(string arguments);
	virtual void displayInfo();
};
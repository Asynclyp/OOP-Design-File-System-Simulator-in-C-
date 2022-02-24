#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "PasswordProxy.h"
#include<sstream>

class TouchCommand : public AbstractCommand {
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
public:
	TouchCommand(AbstractFileSystem* file_system, AbstractFileFactory* file_factory);
	virtual int execute(string filename);
	virtual void displayInfo();
};
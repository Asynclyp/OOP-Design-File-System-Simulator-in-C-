#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "MetadataDisplayVisitor.h"
#include <sstream>

class LSCommand : public AbstractCommand {
	AbstractFileSystem* afs;
public:
	LSCommand(AbstractFileSystem* file_system);
	virtual int execute(string flags);
	virtual void displayInfo();
};
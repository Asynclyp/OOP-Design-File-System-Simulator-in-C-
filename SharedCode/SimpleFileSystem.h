#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include <map>
#include <set>
class SimpleFileSystem : public AbstractFileSystem {
	map<string, AbstractFile*> mp;
	set<AbstractFile*> st;
public:
	virtual int addFile(string str, AbstractFile* abs);
	virtual AbstractFile* openFile(string);
	virtual int closeFile(AbstractFile* abs);
	virtual int deleteFile(string);
	virtual set<string> getFileNames();
};

#pragma once
// declaration of the interface all file systems provide goes here
#include<string>
#include<set>
#include "AbstractFile.h"

class AbstractFileSystem {
public:
	virtual int addFile(string str, AbstractFile * abs) = 0;
	virtual int deleteFile(string) = 0;
	virtual AbstractFile* openFile(string) = 0;
	virtual int closeFile(AbstractFile* abs) = 0;
	virtual set<string> getFileNames() = 0;
	virtual ~AbstractFileSystem() = default;
};

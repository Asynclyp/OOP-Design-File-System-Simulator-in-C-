#pragma once
// Image file class declaration here
#include "AbstractFile.h"
#include <string>
#include <vector>

class ImageFile : public AbstractFile {
	string name_;
	vector<char> contents_;
	char size;
public:
	ImageFile(std::string);
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(vector<char> v);
	virtual int append(vector<char> v);
	virtual vector<char> read();
	virtual void accept(AbstractFileVisitor* afv);
	virtual AbstractFile* clone(string destination);
};
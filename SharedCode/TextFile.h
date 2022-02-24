#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"
class TextFile : public AbstractFile {
	vector<char> contents_;
	string name_;
public:
	TextFile(string name);
	virtual unsigned int getSize();
	virtual string getName();
	virtual int write(vector<char> v);
	virtual int append(vector<char> v);
	virtual vector<char> read();
	virtual void accept(AbstractFileVisitor* afv);
	virtual AbstractFile* clone(string destination);
};
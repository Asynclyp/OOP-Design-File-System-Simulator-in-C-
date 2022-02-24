#pragma once
#include "AbstractFile.h"

class PasswordProxy : public AbstractFile {
	AbstractFile* file;
	string password;
public:
	virtual vector<char> read();
	virtual int write(vector<char> v);
	virtual int append(vector<char> v);
	virtual unsigned int getSize();
	virtual string getName();
	PasswordProxy(AbstractFile* f, string pwd);
	~PasswordProxy();
	virtual void accept(AbstractFileVisitor* afv);
	virtual AbstractFile* clone(string destination);
protected:
	string passwordPrompt();
	bool isPassword(string input);
};
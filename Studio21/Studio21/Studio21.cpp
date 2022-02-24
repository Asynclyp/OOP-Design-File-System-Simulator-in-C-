// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\MetadataDisplayVisitor.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include "..\..\\SharedCode\TextFile.h"
#include "..\..\\SharedCode\CommandPrompt.h"
#include "..\..\\SharedCode\TouchCommand.h"
#include <iostream>
using namespace std;

int main()
{
	// SET UP FILE SYSTEM
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();
	CommandPrompt* cp = new CommandPrompt;
	cp->setFileSystem(sfs);
	cp->setFileFactory(sff);
	// ADD COMMAND
	AbstractCommand* ct = new TouchCommand(sfs, sff);
	string commandname = "touch";
	cp->addCommand(commandname, ct);
	cout << "Return Value: " << cp->run() << endl;				// Test various input
	AbstractFile* file = sfs->openFile("foo.txt");
	if (file == nullptr) {
		cout << "Couldn't find foo.txt" << endl;
	}
	else {
		cout << "File Name: " << file->getName() << endl;
	}
	file = sfs->openFile("foo moo.txt");
	if (file == nullptr) {
		cout << "Couldn't find foo moo.txt" << endl;
	}
	else {
		cout << "File Name: " << file->getName() << endl;
	}
	cout << "Return Value: " << cp->run() << endl;				// Input q
	return 0;
}


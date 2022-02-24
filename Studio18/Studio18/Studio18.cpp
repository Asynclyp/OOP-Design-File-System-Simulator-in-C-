// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include <iostream>
using namespace std;

int main()
{
	AbstractFileSystem* afs = new SimpleFileSystem();
	AbstractFileFactory* aff = new SimpleFileFactory();
	afs->addFile("Kevin", aff->createFile("Kevin.txt"));
	afs->addFile("Kai", aff->createFile("Kai.img"));

	vector<char> test = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};

	auto file = afs->openFile("Kevin");
	cout << file->getSize() << endl;	// Expect 0
	file->read();						// Expect no output
	cout << endl;
	file->write(test);
	file->read();						// Expect "hello world"
	cout << endl;
	cout << file->getSize();			// Expect 11


	return 0;
}

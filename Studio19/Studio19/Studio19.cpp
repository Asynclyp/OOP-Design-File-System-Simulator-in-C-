// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	afs->addFile("Test_1", aff->createFile("Test_1.txt"));
	afs->addFile("Test_2", aff->createFile("Test_2.img"));

	vector<char> test_1 = { 'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd' };

	AbstractFile* file = afs->openFile("Test_1");
	file->write(test_1);
	vector<char> buffer = file->read();

	for (auto it = buffer.begin(); it != buffer.end(); ++it) {
		cout << *it;
	}
	cout << endl;

	vector<char> test_2 = { 'g', 'o', 'o', 'd', 'b', 'y', 'e' };
	file->write(test_2);
	buffer = file->read();

	for (auto it = buffer.begin(); it != buffer.end(); ++it) {
		cout << *it;
	}
	cout << endl;

	return 0;
}

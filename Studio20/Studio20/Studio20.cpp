// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\MetadataDisplayVisitor.h"
#include "..\..\\SharedCode\BasicDisplayVisitor.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include "..\..\\SharedCode\TextFile.h"
#include <iostream>
using namespace std;

int main()
{
	string password = "hi";
	AbstractFile* real_file = new TextFile("Real");
	AbstractFile* proxy_file = new PasswordProxy(real_file, password);
	BasicDisplayVisitor* bdv = new BasicDisplayVisitor();
	MetadataDisplayVisitor* mdv = new MetadataDisplayVisitor();

	vector<char> test_1 = { 'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd' };

	proxy_file->write(test_1);		// User should fail the password
	proxy_file->accept(bdv);		// Expect nothing
	cout << endl;
	proxy_file->accept(mdv);		// Expect "Name: Real\nSize: 0\nType: text"

	proxy_file->write(test_1);		// User should succeed
	proxy_file->accept(bdv);		// Expect "hello world"
	cout << endl;
	proxy_file->accept(mdv);		// Expect "Name: Real\nSize: 11\nType: text"

	return 0;
}


// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
//#include "AbstractFile.h"
//#include "TextFile.h"
#include <iostream>
#include <vector>


using namespace std;


int main()
{
	vector<char> v = { '2','3','4','5' };		// Test contents
	AbstractFile * abs = new TextFile("One");	// Create AbstractFile Object
	cout << abs->getName() << endl;				// Expect "One"
	abs->write(v);
	abs->read();								// Expect "2345"
	cout << endl;
	cout << abs->getSize() << endl;				// Expect "4"
	abs->append(v);
	abs->read();								// Expect "23452345"
	cout << endl;
	cout << abs->getSize() << endl;				// Expect "8"
	abs->write(v);
	abs->read();								// Expect "2345"
	cout << endl;
	cout << abs->getSize() << endl;				// Expect "4"
}



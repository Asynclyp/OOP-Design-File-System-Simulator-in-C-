// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\ImageFile.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\TextFile.h"
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	AbstractFile * imf = new ImageFile("Kevin");

	cout << imf->getName() <<" "<< imf->getSize() << endl;

	vector<char> v = { 'X', 'X', 'X','X', 'X', 'X','X', 'X', 'X', '3'};
	imf->write(v);
	cout << imf->getName() << " " << imf->getSize() << endl;
	imf->read();
	int return_value = imf->append(v);
	cout << "Attempt to append return type: " << return_value << endl;
	cout << imf->getName() << " " << imf->getSize() << endl;

	SimpleFileSystem sfs = SimpleFileSystem();
	AbstractFile * txf = new TextFile("Kai");
	sfs.addFile("Kevin", imf);
	sfs.addFile("Kai", txf);

	sfs.createFile("Spark.txt");


}


// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include "ImageFile.h"
#include"TextFile.h"
#include <utility>

AbstractFile* SimpleFileFactory::createFile(string str) {
	
	// Isolate file ending
	int periodLocation = str.find('.');

	if (periodLocation != str.npos) {
		string endingText = str.substr(periodLocation, str.npos);

		// If .img ending
		if (endingText == ".img") {
			auto img = new ImageFile(str);									// Create new ImageFile Object
			return img;
		}

		if (endingText == ".txt") {
			auto txt = new TextFile(str);									// Create new TextFile Object
			return txt;
		}
	}

	// If the file doesn't match any of the currently supported file endings or didn't have a file ending
	return nullptr;
}
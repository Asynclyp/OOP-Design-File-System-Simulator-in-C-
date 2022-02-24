// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "ImageFile.h"
#include"TextFile.h"
#include <utility>

int SimpleFileSystem::addFile(string str, AbstractFile* abs) {
	// If the file already exists
	if (mp.count(str) > 0) {
		return ReturnType::file_already_exists;
	}

	// If the file pointer is a nullptr
	if (abs == nullptr) {
		return ReturnType::file_pointer_is_nullptr;
	}

	// Insert name-file pair into map
	mp.insert(pair<string, AbstractFile*>(str, abs));
	return ReturnType::success;
}


AbstractFile* SimpleFileSystem::openFile(string str) {
	// Search for the file
	auto search = mp.find(str);

	// If the file doesn't exist
	if (search == mp.end()) {
		return nullptr;
	}

	AbstractFile* abs = search->second;
	// If the file is not open yet
	if (st.count(abs) == 0) {
		st.insert(abs);
		return abs;
	}

	// File was already open
	return nullptr;
}


int SimpleFileSystem::closeFile(AbstractFile* abs) {
	// For each of the open files
	for (auto it = st.begin(); it != st.end(); ++it) {
		// If the file is the file we want to close
		if (*it == abs) {
			// Close the file
			st.erase(it);
			return ReturnType::success;
		}
	}

	// We did not find the file
	return ReturnType::file_not_found;
}

int SimpleFileSystem::deleteFile(string str) {
	// Search for the file
	auto search = mp.find(str);

	// If the file doesn't exist
	if (search == mp.end()) {
		return ReturnType::file_not_found;
	}

	AbstractFile* abs = search->second;
	// If the file is open
	if (st.count(abs) > 0) {
		return ReturnType::file_in_use;
	}

	// Delete the file object, remove the pointer from the set of open files, and return success
	delete abs;
	mp.erase(str);
	return ReturnType::success;
}

set<string> SimpleFileSystem::getFileNames() {
	set<string> filenames;
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		filenames.insert(it->first);
	}
	return filenames;
}